//
// Created by qqy on 22-11-25.
//

#include "Expression.h"
#include "FunctionDeclaration.h"
#include "VariableDeclaration.h"


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
    // 给标识符赋值
    Element result;
    auto value = arrayExpr->eval();
    if (id != nullptr) {
        result = id->eval();
        result = value;
        *(id->symbol) = result;
    }
    // TODO 给数组赋值
    else {

    }
    return result;
}

// TODO
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

// TODO
Element qwq::SliceExpression::eval() {
    return AstNode::eval();
}

// TODO
Element qwq::ArrayAccess::eval() {
    return AstNode::eval();
}
