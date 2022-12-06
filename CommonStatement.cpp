//
// Created by qqy on 22-11-25.
//

#include "CommonStatement.h"
#include "VariableDeclaration.h"
#include "Type.h"
#include "Literal.h"

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
    auto exp = condition->eval();

    SymbolManager::addStatus(SymbolManager::Status::WHILE);
    while (exp.intVal >= 1) {
        auto result = block->eval();
        if (SymbolManager::topStatus() == SymbolManager::CONTINUE) {
            SymbolManager::popStatus();
        }
        else if (SymbolManager::topStatus() == SymbolManager::BREAK) {
            SymbolManager::popStatus();
            break;
        }
        else if (SymbolManager::topStatus() == SymbolManager::RETURN) {
            SymbolManager::popFunc();
            return result;
        }

        // 更新循环条件
        exp = condition->eval();
    }
    SymbolManager::popStatus();
    return EMPTY;
}

Element qwq::PyLikeForStatement::eval() {

    SymbolManager::addLayer();
    auto leftRange = left->eval();
    auto rightRange = right->eval();
    if (leftRange.type != Element::ElementType::INTEGER || rightRange.type != Element::ElementType::INTEGER) {
        std::cerr << "non-integer range for py like loop" << std::endl;
        exit(1);
    }

    // 声明并定义循环变量，初值为leftRange
    auto* a = new qwq::VarDeclByExpr(std::make_shared<qwq::IntType>(1),
            loopVariable, std::make_shared<qwq::Integer>(leftRange.intVal));
    a->eval();

    while (loopVariable->symbol->intVal < rightRange.intVal) {
        auto result = block->eval();

        if (SymbolManager::topStatus() == SymbolManager::CONTINUE) {
            SymbolManager::popStatus();

        }
        else if (SymbolManager::topStatus() == SymbolManager::BREAK) {
            SymbolManager::popStatus();
            break;
        }
        else if (SymbolManager::topStatus() == SymbolManager::RETURN) {
            SymbolManager::popFunc();
            return result;
        }

        // 修改循环变量
        loopVariable->symbol->intVal += 1;
    }

    delete a;
    SymbolManager::popStatus();
    SymbolManager::popLayer();
    return EMPTY;
}

Element qwq::CLikeForStatement::eval() {

    SymbolManager::addLayer();
    // 变量声明或定义
    if (firstExpr1 != nullptr) {
        firstExpr1->eval();
    }
    else if (firstExpr2 != nullptr) {
        firstExpr2->eval();
    }

    // 执行条件分析
    Element exp = judgeExpr->eval();
    SymbolManager::addStatus(SymbolManager::WHILE);
    while (exp.intVal >= 1) {
        Element result = block->eval();
        if (SymbolManager::topStatus() == SymbolManager::CONTINUE) {
            SymbolManager::popStatus();

        }
        else if (SymbolManager::topStatus() == SymbolManager::BREAK) {
            SymbolManager::popStatus();
            break;
        }
        else if (SymbolManager::topStatus() == SymbolManager::RETURN) {
            SymbolManager::popFunc();
            return result;
        }

        // 第三个表达式执行
        assignExpr->eval();
        // 循环条件更新
        exp = judgeExpr->eval();
    }
    SymbolManager::popStatus();
    SymbolManager::popLayer();
    return EMPTY;
}

Element qwq::RangeForStatement::eval() {
    // TODO
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
    // 直接执行表达式
    expr->eval();
    return EMPTY;
}

Element qwq::JumpStatement::eval() {
    if (SymbolManager::topStatus() != SymbolManager::WHILE) {
        std::cerr << "invalid jump" << std::endl;
        exit(EXIT_FAILURE);
    }
    // TODO op改成对应的操作
    if (op == 0) {
        SymbolManager::addStatus(SymbolManager::BREAK);
    }
    else {
        SymbolManager::addStatus(SymbolManager::CONTINUE);
    }
    return EMPTY;
}

Element qwq::PrintStatement::eval() {
    auto expEle = expr->eval();
    if (expEle.type == Element::ElementType::INTEGER) {
        std::cout << expEle.intVal << std::endl;
    }
    else if (expEle.type == Element::ElementType::CHAR) {
        std::cout << static_cast<char>(expEle.intVal) << std::endl;
    }
    else if (expEle.type == Element::ElementType::BOOL) {
        if (expEle.intVal >= 1) {
            std::cout << true << std::endl;
        }
        else 
        {
            std::cout << false << std::endl;
        }
    }
    else if (expEle.type == Element::ElementType::DOUBLE) {
        std::cout << expEle.doubleVal << std::endl;

    }
    else if (expEle.type == Element::ElementType::STRING) {
        std::cout << expEle.strVal << std::endl;
    }
    else {
        std::cout << expEle.array << std::endl;
    }
}