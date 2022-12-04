//
// Created by qqy on 22-11-25.
//

#include "CommonStatement.h"

Element qwq::IfStatement::eval() {
    // 1.分析条件表达式
    auto exp = relationalExpr->eval();

    // 2.为真，执行if；否则执行else
    if (exp.intVal >= 1) {
        auto result = ifBlock->eval();
        if (SymbolManager::topStatus() == SymbolManager::RETURN) {
            SymbolManager::popFunc();
            return result;
        }
    }
    else if (elseBlock != nullptr) {
        auto result = elseBlock->eval();
        if (SymbolManager::topStatus() == SymbolManager::RETURN) {
            SymbolManager::popFunc();
            return result;
        }
    }
    return EMPTY;
}

Element qwq::WhileStatement::eval() {
    return AstNode::eval();
}

Element qwq::PyLikeForStatement::eval() {
    return AstNode::eval();
}

Element qwq::CLikeForStatement::eval() {
    return AstNode::eval();
}

Element qwq::RangeForStatement::eval() {
    return AstNode::eval();
}

Element qwq::ReturnStatement::eval() {
    // 只有函数里面可以写return（TODO 不包括main）
    if (!SymbolManager::checkFunc()) {
        std::cerr << "can't return here" << std::endl;
        exit(EXIT_FAILURE);
    }
    SymbolManager::addStatus(SymbolManager::RETURN);
    if (returnExpr != nullptr)
        return returnExpr->eval();
    return EMPTY;
}

Element qwq::ExpressionStatement::eval() {
    return AstNode::eval();
}

Element qwq::JumpStatement::eval() {
    return AstNode::eval();
}
