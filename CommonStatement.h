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
                std::shared_ptr<Block> elseBlock = nullptr)
            : ifCbs(std::move(cbs))
            , elifCbs(std::move(elifCbs))
            , elseBlock(std::move(elseBlock)) {}
private:
    std::shared_ptr<CBPair> ifCbs;
    std::shared_ptr<std::vector<CBPair>> elifCbs = nullptr;
    std::shared_ptr<Block> elseBlock = nullptr;
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
    , ForStatement(std::move(block)) {}
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
    // 形如：int a;
    VariableDeclaration(std::shared_ptr<Type> type, std::shared_ptr<Identifier> id, YYLTYPE loc)
    : type(std::move(type))
    , id(std::move(id))
    , loc(std::move(loc)) {}

    // 形如：int a = exp;
    VariableDeclaration(std::shared_ptr<Type> type, std::shared_ptr<Identifier> id,
                        std::shared_ptr<Expression> assignmentExpr, YYLTYPE loc)
                        : type(std::move(type))
                        , id(std::move(id))
                        , assignmentExpr(std::move(assignmentExpr))
                        , loc(std::move(loc)) {}

    // 形如：A<int> a;
    VariableDeclaration(std::shared_ptr<Type> type, std::shared_ptr<Identifier> id,
                        std::shared_ptr<Type> templateType, YYLTYPE loc)
                        : type(std::move(type))
                        , id(std::move(id))
                        , templateType(std::move(templateType))
                        , loc(std::move(loc)) {}

    // 形如：A<int> a = b;
    VariableDeclaration(std::shared_ptr<Type> type, std::shared_ptr<Identifier> id,
                        std::shared_ptr<Expression> assignmentExpr, std::shared_ptr<Type> templateType
                        , YYLTYPE loc)
                        : type(std::move(type))
                        , id(std::move(id))
                        , assignmentExpr(std::move(assignmentExpr))
                        , templateType(std::move(templateType))
                        , loc(std::move(loc)) {}

    YYLTYPE getLocation() { return loc; }
private:
    std::shared_ptr<Type> type;
    std::shared_ptr<Identifier> id;
    std::shared_ptr<Expression> assignmentExpr = nullptr;
    std::shared_ptr<Type> templateType = nullptr;
    YYLTYPE loc;
};

class ReturnStatement : public CommonStatement {
public:
    // 有返回值
    explicit ReturnStatement(std::shared_ptr<Expression> expr, YYLTYPE loc)
    : returnExpr(std::move(expr))
    , loc(std::move(loc)) {}

    // 无返回值
    explicit ReturnStatement(YYLTYPE loc) : loc(std::move(loc)) {}
    YYLTYPE getLocation() { return loc; }
private:
    std::shared_ptr<Expression> returnExpr = nullptr;
    YYLTYPE loc;
};

class ExpressionStatement : public CommonStatement {
public:
    explicit ExpressionStatement(std::shared_ptr<Expression> expr, YYLTYPE loc)
    : expr(std::move(expr))
    , loc(std::move(loc)) {}
    YYLTYPE getLocation() { return loc; }
private:
    std::shared_ptr<Expression> expr;
    YYLTYPE loc;
};

class JumpStatement : public CommonStatement {
public:
    explicit JumpStatement(int op, YYLTYPE loc) : op(op), loc(std::move(loc)) {}
    YYLTYPE getLocation() { return loc; }
private:
    int op;
    YYLTYPE loc;
};

#endif //MYPL_COMMONSTATEMENT_H
