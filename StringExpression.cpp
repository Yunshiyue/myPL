//
// Created by Qingyue on 2022/11/26.
//

#include "StringExpression.h"

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
    switch (op) {
        // +
        case 1:
        {
            auto left = strExpr->eval();
            auto right = rhs->eval();
            result = left + right;
        }
            break;
        // substr
        case 2:
        {
            auto exp = strExpr->eval();
            auto left = leftRange->eval();
            auto right = rightRange->eval();
            if (left.type != Element::ElementType::INTEGER || right.type != Element::ElementType::INTEGER) {
                std::cerr << "substr error" << std::endl;
                exit(1);
            }
            std::string resultStr = exp.strVal.substr(left.intVal, right.intVal - left.intVal);
            result.strVal = resultStr;
        }
            break;
        // reverse
        case 3:
        {
            auto exp = strExpr->eval();
            std::reverse(exp.strVal.begin(), exp.strVal.end());
            result.strVal = exp.strVal;
        }
            break;
        // Title
        case 4:
        {
            auto exp = strExpr->eval();
            std::string s = exp.strVal;
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
            auto exp = strExpr->eval();
            std::string s = exp.strVal;
            for (auto& c : s) {
                toUpperCase(c);
            }
            result.strVal = s;
        }
            break;
        // toLower
        case 6:
        {
            auto exp = strExpr->eval();
            std::string s = exp.strVal;
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
