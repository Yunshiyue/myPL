//
// Created by qqy on 22-11-25.
//

#ifndef MYPL_COMMONSTATEMENT_H
#define MYPL_COMMONSTATEMENT_H

#include "Statement.h"

#include <utility>
#include "Type.h"

class CommonStatement : public Statement {
public:
private:
};


class IfStatement : public CommonStatement {
public:
    using CBPair = std::pair<std::shared_ptr<RelationalExpression>, Block>;

    // if-else
    explicit IfStatement(std::shared_ptr<CBPair> cbs, std::shared_ptr<Block> elseBlock = nullptr)
    : ifCbs(std::move(cbs))
    , elseBlock(std::move(elseBlock)) {}

    // if-elif-else
    IfStatement(std::shared_ptr<CBPair> cbs, std::shared_ptr<std::vector<CBPair>> elifCbs,
                std::shared_ptr<Block> elseBlock)
            : ifCbs(std::move(cbs))
            , elifCbs(std::move(elifCbs))
            , elseBlock(std::move(elseBlock)) {}
private:
    std::shared_ptr<CBPair> ifCbs;
    std::shared_ptr<std::vector<CBPair>> elifCbs = nullptr;
    std::shared_ptr<Block> elseBlock;
};

class WhileStatement : public CommonStatement {
public:
    WhileStatement(std::shared_ptr<RelationalExpression> condition, std::shared_ptr<Block> block)
    : condition(std::move(condition))
    , block(std::move(block)) {}
private:
    std::shared_ptr<RelationalExpression> condition;
    std::shared_ptr<Block> block;
};

class ForStatement : public CommonStatement {
public:
};

class VariableDeclaration : public CommonStatement {
public:

private:
    std::shared_ptr<Type> type;
    std::shared_ptr<Identifier> id;
    std::shared_ptr<Expression> assignmentExpr = nullptr;
    std::shared_ptr<Type> templateType = nullptr;
};

class ReturnStatement : public CommonStatement {
public:
    explicit ReturnStatement(std::shared_ptr<Expression> expr = nullptr)
    : returnExpr(std::move(expr)) {}
private:
    std::shared_ptr<Expression> returnExpr;
};

class ExpressionStatement : public CommonStatement {
public:
    explicit ExpressionStatement(std::shared_ptr<Expression> expr) : expr(std::move(expr)) {}
private:
    std::shared_ptr<Expression> expr;
};

class JumpStatement : public CommonStatement {
public:
    explicit JumpStatement(int op) : op(op) {}
private:
    int op;
};

#endif //MYPL_COMMONSTATEMENT_H
