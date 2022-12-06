//
// Created by qqy on 22-11-25.
//

#include "Expression.h"
#include "FunctionDeclaration.h"
#include "VariableDeclaration.h"
#include "printAst.h"
// #include "qwq_parser.cpp"

Array::ArrayType switchToArrayType(Element::ElementType type) {
    switch (type) {
        case Element::ElementType::INTEGER:
            return Array::ArrayType::INTEGER;
        case Element::ElementType::CHAR:
            return Array::ArrayType::CHAR;
        case Element::ElementType::BOOL:
            return Array::ArrayType::BOOL;
        case Element::ElementType::DOUBLE:
            return Array::ArrayType::DOUBLE;
        case Element::ElementType::STRING:
            return Array::ArrayType::STRING;
    }
}

Element qwq::Identifier::eval() {
    // 从符号表中找对应的符号
    symbol = SymbolManager::lookup(name);
    if (symbol == nullptr) {
        std::cerr << "can't refer to a uninitialized variable: " << name << std::endl;
        exit(1);
    }
    return *symbol;
}

Element qwq::Factor::eval() {
    return exp->eval();
}

Element qwq::Item::eval() {
    if (lhs == nullptr) {
        return rhs->eval();
    }
    else {
        auto left = lhs->eval();
        auto right = rhs->eval();
        Element result;
        switch (op) {
            case 1:
                result = left * right;
                break;
            case 2:
                result = left / right;
                break;
            case 3:
                result = left % right;
                break;
            case 4:
                result = left.pow(right);
                break;
            case 5:
                result = left.ediv(right);
                break;
        }
        return result;
    }
}

Element qwq::ArithmeticExpression::eval() {
    if (lhs == nullptr) {
        return rhs->eval();
    }
    else {
        auto left = lhs->eval();
        auto right = rhs->eval();
        Element result;
        switch (op) {
            case 1:
                result = left + right;
                break;
            case 2:
                result = left - right;
                break;
        }
        return result;
    }
}

// TODO
Element qwq::LogicalExpression::eval() {
    if (lhs == nullptr) {
        return rhs->eval();
    }
    else {
        auto left = lhs->eval();
        auto right = rhs->eval();
        Element result;
        switch (op) {
            case 1:
                result = left && right;
                break;
            case 2:
                result = left || right;
                break;
        }
        return result;
    }
}

Element qwq::RelationalExpression::eval() {
    auto left = lhs->eval();
    auto right = rhs->eval();
    Element result;
    switch (op) {
        case 1:
            result = left > right;
            break;
        case 2:
            result = left >= right;
            break;
        case 3:
            result = left < right;
            break;
        case 4:
            result = left <= right;
            break;
        case 5:
            result = left == right;
            break;
        case 6:
            result = left != right;
            break;
    }
    return result;

}

Element qwq::AssignExpression::eval() {
    Element result;
    auto value = rhs->eval();

    // 给标识符赋值
    if (id != nullptr) {
        result = id->eval();

        // 右边非数组
        if (value.type != Element::ElementType::ARRAY) {
            result = value;
            *(id->symbol) = result;
        }
        // 右边为数组
        else {
            if (result.type == Element::ElementType::INTEGER || result.type == Element::ElementType::BOOL ||
                    result.type == Element::ElementType::CHAR) {
                result.intVal = *value.array.intData[0];
            }
            else if (result.type == Element::ElementType::DOUBLE) {
                result.doubleVal = *value.array.doubleData[0];
            }
            else if (result.type == Element::ElementType::STRING) {
                result.strVal = *value.array.stringData[0];
            }
            *(id->symbol) = result;
        }
    }
    else {
        // 如果右侧也是数组，则整体赋值
        if (value.type == Element::ElementType::ARRAY) {
            result = arrayExpr->eval();
            result.array = value.array;
        }
        // 如果右侧是单独的数字，则单独赋值
        else {
            // 里面修改指针指向的内容
            result = arrayExpr->eval();
            if (value.type == Element::ElementType::INTEGER || value.type == Element::ElementType::BOOL ||
                    value.type == Element::ElementType::CHAR) {
                *result.array.intData[0] = value.intVal;
            }
            else if (value.type == Element::ElementType::DOUBLE) {
                *result.array.doubleData[0] = value.doubleVal;
            }
            if (value.type == Element::ElementType::STRING) {
                *result.array.stringData[0] = value.strVal;
            }
        }
    }
    return result;
}

Element qwq::FunctionCall::eval() {
    // 检查是否有该函数的声明
    auto funcDecl = SymbolManager::lookupF(funcId->name);
    if (funcDecl == nullptr) {
        std::cerr << "no such functions called: " << funcId->name << std::endl;
        exit(EXIT_FAILURE);
    }

    // 检查参数个数是否相符
    if (funcDecl->getHead()->arguments->size() != arguments->size()) {
        std::cerr << "need " << funcDecl->getHead()->arguments->size() << " parameters, but providing " << arguments->size() << std::endl;
        exit(EXIT_FAILURE);
    }

    SymbolManager::addLayer();
    SymbolManager::addStatus(SymbolManager::FUNC);

    // 参数声明并定义
    for (int i = 0; i < arguments->size(); i++) {
        VarDeclByExpr* temp = new VarDeclByExpr((*(funcDecl->getHead()->arguments))[i]->getType(),
                                           (*(funcDecl->getHead()->arguments))[i]->getIdentifier(), (*arguments)[i]);
        temp->eval();
        delete temp;
    }

    // 执行函数体
    Element result = funcDecl->getBlock()->eval();
    if (SymbolManager::topStatus() == SymbolManager::RETURN) {
        SymbolManager::popStatus();
        SymbolManager::popStatus();
        SymbolManager::popLayer();
        return result;
    }


    SymbolManager::popStatus();
    SymbolManager::popLayer();
    return AstNode::eval();
}

Element qwq::Block::eval() {
    SymbolManager::addLayer();
    for (auto& s : *statementList) {
        auto result = s->eval();
        if (SymbolManager::topStatus() == SymbolManager::CONTINUE ||
            SymbolManager::topStatus() == SymbolManager::BREAK ||
            SymbolManager::topStatus() == SymbolManager::RETURN)
            break;
            //return result;
    }
    SymbolManager::popLayer();
    return EMPTY;
}

Element qwq::SliceExpression::eval() {
    auto arr = SymbolManager::lookup(id->name);
    if (arr->type != Element::ElementType::ARRAY) {
        std::cerr << "cannot use slice on a non-array type" << std::endl;
        exit(1);
    }

    auto leftRange = left->eval();
    auto rightRange = right->eval();
    if (leftRange.type != Element::ElementType::INTEGER || rightRange.type != Element::ElementType::INTEGER) {
        std::cerr << "non-integer type for range of slice expr" << std::endl;
        exit(1);
    }
    Element result;
    result.type = arr->type;

    // 构建array
    Array arrRes;
    arrRes.type = switchToArrayType(result.type);
    arrRes.sizeList.push_back(rightRange.intVal - leftRange.intVal);
    if (arrRes.type == Array::ArrayType::INTEGER || arrRes.type == Array::ArrayType::BOOL ||
        arrRes.type == Array::ArrayType::CHAR) {
        for (int i = leftRange.intVal; i < rightRange.intVal; i++) {
            arrRes.intData.push_back(arr->array.intData[i]);
        }
    }
    else if (arrRes.type == Array::ArrayType::DOUBLE) {
        for (int i = leftRange.intVal; i < rightRange.intVal; i++) {
            arrRes.doubleData.push_back(arr->array.doubleData[i]);
        }
    }
    else if (arrRes.type == Array::ArrayType::STRING) {
        for (int i = leftRange.intVal; i < rightRange.intVal; i++) {
            arrRes.stringData.push_back(arr->array.stringData[i]);
        }
    }
    result.array = arrRes;

    return result;
}

Element qwq::ArrayAccess::eval() {
    // 检查下标类型
    auto indexEle = index->eval();
    if (indexEle.type != Element::ElementType::INTEGER) {
        std::cerr << " subscript must be a integer type" << std::endl;
        exit(1);
    }

    // 一个下标
    if (id != nullptr) {
        auto idEle = SymbolManager::lookup(id->name);
        if (idEle->type != Element::ElementType::ARRAY) {
            std::cerr << "cannot visit a non-array type by subscript" << std::endl;
            exit(1);
        }

        // 根据下标获取
        auto a = idEle->array.at({indexEle.intVal});
        Element result;
        result.type = Element::ElementType::ARRAY;
        result.array = *a;
        return result;
    }
    // 多维数组
    else {
        auto arr = arrayExpr->eval();

        // 根据下标获取
        auto a = arr.array.at({indexEle.intVal});
        Element result;
        result.type = Element::ElementType::ARRAY;
        result.array = *a;
        return result;
    }
}

// 打印语法树

void qwq::Expression::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "Expression";
    io::print_endl();
}

void qwq::Identifier::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "Identifier";
    io::print_endl();
    io::print_ident(depth+1);
    std::cout << name;
    io::print_endl();
}

void qwq::ArrayAccess::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "ArrayAccess";
    io::print_endl();
    if (id != nullptr) {
        id->printAst(depth+1);
    }
    if (arrayExpr != nullptr) {
        arrayExpr->printAst(depth+1);
    }
    index->printAst(depth+1);
}

void qwq::Factor::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "Factor";
    io::print_endl();
    exp->printAst(depth+1);
}

void qwq::Item::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "Item";
    io::print_endl();
    if (lhs != nullptr) {
        lhs->printAst(depth+1);
        switch (op) {
            case 1:
                io::print_ident(depth+1);
                std::cout << "*";
                io::print_endl();
                break;
            case 2:
                io::print_ident(depth+1);
                std::cout << "/";
                io::print_endl();
                break;
            case 3:
                io::print_ident(depth+1);
                std::cout << "%";
                io::print_endl();
                break;
            case 4:
                io::print_ident(depth+1);
                std::cout << "**";
                io::print_endl();
                break;
            case 5:
                io::print_ident(depth+1);
                std::cout << "//";
                io::print_endl();
                break;
        }
    }
    if (rhs != nullptr) {
        rhs->printAst(depth+1);
    }
}

void qwq::ArithmeticExpression::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "ArithmeticExpression";
    io::print_endl();
    if (lhs != nullptr) {
        lhs->printAst(depth+1);
        switch (op) {
            case 1:
                io::print_ident(depth+1);
                std::cout << "+";
                io::print_endl();
                break;
            case 2:
                io::print_ident(depth+1);
                std::cout << "-";
                io::print_endl();
                break;
        }
    }
    if (rhs != nullptr) {
        rhs->printAst(depth+1);
    }
}

void qwq::LogicalExpression::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "LogicalExpression";
    io::print_endl();
    if (lhs != nullptr) {
        lhs->printAst(depth+1);
        switch (op) {
            case 1:
                io::print_ident(depth+1);
                std::cout << "&&";
                io::print_endl();
                break;
            case 2:
                io::print_ident(depth+1);
                std::cout << "||";
                io::print_endl();
                break;
        }
    }
    if (rhs != nullptr) {
        rhs->printAst(depth+1);
    }
}

void qwq::SliceExpression::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "SliceExpression";
    io::print_endl();
    id->printAst(depth+1);
    left->printAst(depth+1);
    right->printAst(depth+1);
}

void qwq::AssignExpression::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "AssignExpression";
    io::print_endl();
    if (id != nullptr) {
        id->printAst(depth+1);
    } else {
        arrayExpr->printAst(depth+1);
    }
    io::print_ident(depth+1);
    std::cout << "=";
    io::print_endl();
    rhs->printAst(depth+1);
}

void qwq::FunctionCall::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "FunctionCall";
    io::print_endl();
    if (varId != nullptr) {
        varId->printAst(depth+1);
    }
    funcId->printAst(depth+1);
    io::print_ident(depth+1);
    std::cout << "arguments";
    io::print_endl();
    for (int i = 0; i < arguments->size(); i++) {
        (*arguments)[i]->printAst(depth+2);
    }
}

void qwq::RelationalExpression::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "RelationalExpression";
    io::print_endl();
    lhs->printAst(depth+1);
    switch (op) {
        case 1:
            io::print_ident(depth+1);
            std::cout << ">";
            io::print_endl();
            break;
        case 2:
            io::print_ident(depth+1);
            std::cout << ">=";
            io::print_endl();
            break;
        case 3:
            io::print_ident(depth+1);
            std::cout << "<";
            io::print_endl();
            break;
        case 4:
            io::print_ident(depth+1);
            std::cout << "<=";
            io::print_endl();
            break;
        case 5:
            io::print_ident(depth+1);
            std::cout << "==";
            io::print_endl();
            break;
        case 6:
            io::print_ident(depth+1);
            std::cout << "!=";
            io::print_endl();
            break;
    }
    if (rhs != nullptr) {
        rhs->printAst(depth+1);
    }
}

void qwq::Block::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "Block";
    io::print_endl();
    for (int i = 0; i < statementList->size(); i++) {
        (*statementList)[i]->printAst(depth+1);
    }
}