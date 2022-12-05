//
// Created by qqy on 22-11-25.
//

#include "Expression.h"
#include "FunctionDeclaration.h"
#include "VariableDeclaration.h"

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

// TODO
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

// TODO
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

// TODO
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
        result = value;
        *(id->symbol) = result;
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
