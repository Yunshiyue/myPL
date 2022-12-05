//
// Created by qqy on 22-11-25.
//

#ifndef MYPL_COMMONSTATEMENT_H
#define MYPL_COMMONSTATEMENT_H

#include "Statement.h"

#include <utility>
#include "Type.h"

namespace qwq {
    class VariableDeclaration;
    class VariableDeclarationAssign;

    class CommonStatement : public Statement {
    public:
        Element eval() override { return EMPTY; }
    private:
    };


    class IfStatement : public CommonStatement {
    public:
        using CBPair = std::pair<std::shared_ptr<RelationalExpression>, Block>;

//        // if-else
//        explicit IfStatement(std::shared_ptr<CBPair> cbs, std::shared_ptr<Block> elseBlock = nullptr)
//                : ifCbs(std::move(cbs)), elseBlock(std::move(elseBlock)) {}

        // if-elif-else
//        IfStatement(std::shared_ptr<CBPair> cbs, std::shared_ptr<std::vector<CBPair>> elifCbs,
//                    std::shared_ptr<Block> elseBlock = nullptr)
//                : ifCbs(std::move(cbs)), elifCbs(std::move(elifCbs)), elseBlock(std::move(elseBlock)) {}
        IfStatement(std::shared_ptr<RelationalExpression> relationalExpr, std::shared_ptr<Block> ifBlock
                    , std::shared_ptr<Block> elseBlock = nullptr)
                    : relationalExpr(std::move(relationalExpr))
                    , ifBlock(std::move(ifBlock))
                    , elseBlock(std::move(elseBlock)) {}
        Element eval() override;
    private:
//        std::shared_ptr<CBPair> ifCbs;
//        std::shared_ptr<std::vector<CBPair>> elifCbs = nullptr;
        std::shared_ptr<RelationalExpression> relationalExpr;
        std::shared_ptr<Block> ifBlock;
        std::shared_ptr<Block> elseBlock = nullptr;
    };

    class WhileStatement : public CommonStatement {
    public:
        WhileStatement(std::shared_ptr<RelationalExpression> condition, std::shared_ptr<Block> block)
                : condition(std::move(condition)), block(std::move(block)) {}
        Element eval() override;
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
        PyLikeForStatement(std::shared_ptr<Identifier> loopVariable, std::shared_ptr<Expression> left, std::shared_ptr<Expression> right, std::shared_ptr<Block> block)
                : loopVariable(std::move(loopVariable))
                , left(std::move(left))
                , right(std::move(right))
                , ForStatement(std::move(block)) {}
        Element eval() override;
    private:
        std::shared_ptr<Identifier> loopVariable;
        std::shared_ptr<Expression> left;
        std::shared_ptr<Expression> right;
    };

    class CLikeForStatement : public ForStatement {
    public:
        CLikeForStatement(std::shared_ptr<VariableDeclarationAssign> firstExpr1,
                          std::shared_ptr<RelationalExpression> judgeExpr,
                          std::shared_ptr<AssignExpression> assignExpr,
                          std::shared_ptr<Block> block)
                : firstExpr1(std::move(firstExpr1)), judgeExpr(std::move(judgeExpr)), assignExpr(std::move(assignExpr)),
                  ForStatement(std::move(block)) {}

        CLikeForStatement(std::shared_ptr<AssignExpression> firstExpr2,
                          std::shared_ptr<RelationalExpression> judgeExpr,
                          std::shared_ptr<AssignExpression> assignExpr,
                          std::shared_ptr<Block> block)
                : firstExpr2(std::move(firstExpr2)), judgeExpr(std::move(judgeExpr)), assignExpr(std::move(assignExpr)),
                  ForStatement(std::move(block)) {}
        Element eval() override;

    private:
        std::shared_ptr<VariableDeclarationAssign> firstExpr1 = nullptr;  // 注意：expr1和expr2只能用1个
        std::shared_ptr<AssignExpression> firstExpr2 = nullptr;
        std::shared_ptr<RelationalExpression> judgeExpr = nullptr;
        std::shared_ptr<AssignExpression> assignExpr = nullptr;
    };

    class RangeForStatement : public ForStatement {
    public:
        RangeForStatement(std::shared_ptr<VariableDeclaration> variableDeclaration,
                          std::shared_ptr<Identifier> loopRangeId, std::shared_ptr<Block> block)
                : variableDeclaration(std::move(variableDeclaration))
                , loopRangeId(std::move(loopRangeId)), ForStatement(std::move(block)) {}
        Element eval() override;

    private:
        std::shared_ptr<VariableDeclaration> variableDeclaration;
        std::shared_ptr<Identifier> loopRangeId;
    };



    class ReturnStatement : public CommonStatement {
    public:
        // 有返回值
        explicit ReturnStatement(std::shared_ptr<Expression> expr, YYLTYPE loc)
                : returnExpr(std::move(expr)), loc(std::move(loc)) {}

        // 无返回值
        explicit ReturnStatement(YYLTYPE loc) : loc(std::move(loc)) {}

        YYLTYPE getLocation() { return loc; }
        Element eval() override;

    private:
        std::shared_ptr<Expression> returnExpr = nullptr;
        YYLTYPE loc;
    };

    class ExpressionStatement : public CommonStatement {
    public:
        explicit ExpressionStatement(std::shared_ptr<Expression> expr, YYLTYPE loc)
                : expr(std::move(expr)), loc(std::move(loc)) {}

        YYLTYPE getLocation() { return loc; }
        Element eval() override;

    private:
        std::shared_ptr<Expression> expr;
        YYLTYPE loc;
    };

    class JumpStatement : public CommonStatement {
    public:
        explicit JumpStatement(int op, YYLTYPE loc) : op(op), loc(std::move(loc)) {}

        YYLTYPE getLocation() { return loc; }
        Element eval() override;

    private:
        int op;
        YYLTYPE loc;
    };

}

#endif //MYPL_COMMONSTATEMENT_H
