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
    explicit ForStatement(std::shared_ptr<Block> block) : block(std::move(block)) {}
protected:
    std::shared_ptr<Block> block;
};

class PyLikeForStatement : public ForStatement {
public:
    PyLikeForStatement(std::shared_ptr<Identifier> loopVariable, int left, int right, std::shared_ptr<Block> block)
    : loopVariable(std::move(loopVariable))
    , left(left)
    , right(right)
    , ForStatement(std::move(block)){}
private:
    std::shared_ptr<Identifier> loopVariable;
    int left;
    int right;
};

class CLikeForStatement : public ForStatement {
public:
    CLikeForStatement(std::shared_ptr<VariableDeclaration> firstExpr1,
                      std::shared_ptr<RelationalExpression> judgeExpr,
                      std::shared_ptr<AssignExpression> assignExpr,
                      std::shared_ptr<Block> block)
                      : firstExpr1(std::move(firstExpr1))
                      , judgeExpr(std::move(judgeExpr))
                      , assignExpr(std::move(assignExpr))
                      , ForStatement(std::move(block)) {}

    CLikeForStatement(std::shared_ptr<AssignExpression> firstExpr2,
                      std::shared_ptr<RelationalExpression> judgeExpr,
                      std::shared_ptr<AssignExpression> assignExpr,
                      std::shared_ptr<Block> block)
            : firstExpr2(std::move(firstExpr2))
            , judgeExpr(std::move(judgeExpr))
            , assignExpr(std::move(assignExpr))
            , ForStatement(std::move(block)) {}
private:
    std::shared_ptr<VariableDeclaration> firstExpr1 = nullptr;  // 注意：expr1和expr2只能用1个
    std::shared_ptr<AssignExpression> firstExpr2 = nullptr;
    std::shared_ptr<RelationalExpression> judgeExpr = nullptr;
    std::shared_ptr<AssignExpression> assignExpr = nullptr;
};

class RangeForStatement : public ForStatement {
public:
    RangeForStatement(std::shared_ptr<Type> loopVariableType, std::shared_ptr<Identifier> loopVariable,
                      std::shared_ptr<Identifier> loopRangeId, std::shared_ptr<Block> block)
                      : loopVariableType(std::move(loopVariableType))
                      , loopVariable(std::move(loopVariable))
                      , loopRangeId(std::move(loopRangeId))
                      , ForStatement(std::move(block)) {}
private:
    std::shared_ptr<Type> loopVariableType;
    std::shared_ptr<Identifier> loopVariable;
    std::shared_ptr<Identifier> loopRangeId;
};

class VariableDeclaration : public CommonStatement {
public:
    VariableDeclaration(std::shared_ptr<Type> type, std::shared_ptr<Identifier> id)
    : type(std::move(type))
    , id(std::move(id)) {}

    VariableDeclaration(std::shared_ptr<Type> type, std::shared_ptr<Identifier> id,
                        std::shared_ptr<Expression> assignmentExpr)
                        : type(std::move(type))
                        , id(std::move(id))
                        , assignmentExpr(std::move(assignmentExpr)) {}

    VariableDeclaration(std::shared_ptr<Type> type, std::shared_ptr<Identifier> id,
                        std::shared_ptr<Type> templateType)
                        : type(std::move(type))
                        , id(std::move(id))
                        , templateType(std::move(templateType)) {}

    VariableDeclaration(std::shared_ptr<Type> type, std::shared_ptr<Identifier> id,
                        std::shared_ptr<Expression> assignmentExpr, std::shared_ptr<Type> templateType)
                        : type(std::move(type))
                        , id(std::move(id))
                        , assignmentExpr(std::move(assignmentExpr))
                        , templateType(std::move(templateType)) {}
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
