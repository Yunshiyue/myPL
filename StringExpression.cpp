//
// Created by Qingyue on 2022/11/26.
//

#include "StringExpression.h"
#include "printAst.h"

inline bool isUpper(const char c) {
    if (c >= 'A' && c <= 'Z') {
        return true;
    }
    return false;
}

inline bool isLower(const char c) {
    if (c >= 'a' && c <= 'z') {
        return true;
    }
    return false;
}

inline void toUpperCase(char& c) {
    if (isLower(c)) {
        c = static_cast<char>(c - 'a' + 'A');
    }
}

inline void toLowerCase(char& c) {
    if (isUpper(c)) {
        c = static_cast<char>(c - 'A' + 'a');
    }
}


Element qwq::StringLiteral::eval() {
    Element result;
    result.type = Element::ElementType::STRING;
    result.strVal = value;
    return result;
}


Element qwq::StringIdentifier::eval() {
    Element result;
    result = id->eval();
    if (result.type != Element::ElementType::STRING) {
        std::cerr << "not a string type identifier" << std::endl;
        exit(1);
    }
    return result;
}

Element qwq::StringOperation::eval() {
    Element result;
    result.type = Element::ElementType::STRING;
    Element lhs;
    if (strExpr != nullptr) {
        lhs = strExpr->eval();
    }
    else {
        lhs = strId->eval();
    }
    switch (op) {
        // +
        case 1:
        {
            
            auto right = rhs->eval();
            result = lhs + right;
        }
            break;
        // substr
        case 2:
        {
            
            auto left = leftRange->eval();
            auto right = rightRange->eval();
            if (left.type != Element::ElementType::INTEGER || right.type != Element::ElementType::INTEGER) {
                std::cerr << "substr error" << std::endl;
                exit(1);
            }
            std::string resultStr = lhs.strVal.substr(left.intVal, right.intVal - left.intVal);
            result.strVal = resultStr;
        }
            break;
        // reverse
        case 3:
        {
            
            std::reverse(lhs.strVal.begin(), lhs.strVal.end());
            result.strVal = lhs.strVal;
        }
            break;
        // Title
        case 4:
        {
            
            std::string s = lhs.strVal;
            for (int i = 0; i < s.size(); i++) {
                if (i == 0) {
                    toUpperCase(s[i]);
                }
                else
                {
                    if (s[i - 1] == ' ') {
                        toUpperCase(s[i]);
                    }
                }
            }
            result.strVal = s;
        }
            break;
        // toUpper
        case 5:
        {
            
            std::string s = lhs.strVal;
            for (auto& c : s) {
                toUpperCase(c);
            }
            result.strVal = s;
        }
            break;
        // toLower
        case 6:
        {
            
            std::string s = lhs.strVal;
            for (auto& c : s) {
                toLowerCase(c);
            }
            result.strVal = s;
        }
            break;
    }
    return result;
}

Element qwq::StringFuncExpression::eval() {
    Element result = funcExpr->eval();
    if (result.type != Element::ElementType::STRING) {
        std::cerr << "the function does not return a string type" << std::endl;
        exit(1);
    }
    return result;
}

// 打印语法树

void qwq::StringExpression::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "StringExpression";
    io::print_endl();
}

void qwq::StringLiteral::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "StringLiteral";
    io::print_endl();
    io::print_ident(depth+1);
    std::cout << value;
    io::print_endl();
}

void qwq::StringIdentifier::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "StringIdentifier";
    io::print_endl();
    id->printAst(depth+1);
}

void qwq::StringOperation::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "StringOperation";
    io::print_endl();
    if (strExpr != nullptr) {
        strExpr->printAst(depth+1);
    } else {
        strId->printAst(depth+1);
    }
    switch (op) {
        // +
        case 1:
        {
            io::print_ident(depth+1);
            std::cout << "+";
            io::print_endl();
            rhs->printAst(depth+1);
        }
            break;
        // substr
        case 2:
        {
            io::print_ident(depth+1);
            std::cout << ".substr";
            io::print_endl();
            io::print_ident(depth+1);
            std::cout << "leftRange:";
            io::print_endl();
            leftRange->printAst(depth+2);
            io::print_ident(depth+1);
            std::cout << "rightRange:";
            io::print_endl();
            rightRange->printAst(depth+2);
        }
            break;
        // reverse
        case 3:
        {
            io::print_ident(depth+1);
            std::cout << ".reverse";
            io::print_endl();
        }
            break;
        // Title
        case 4:
        {
            io::print_ident(depth+1);
            std::cout << ".Title";
            io::print_endl();
        }
            break;
        // toUpper
        case 5:
        {
            io::print_ident(depth+1);
            std::cout << ".toUpper";
            io::print_endl();
        }
            break;
        // toLower
        case 6:
        {
            io::print_ident(depth+1);
            std::cout << ".toLower";
            io::print_endl();
        }
            break;
    }
}

void qwq::StringFuncExpression::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "StringFuncExpression";
    io::print_endl();
    funcExpr->printAst(depth+1);
}