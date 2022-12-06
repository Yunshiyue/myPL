//
// Created by qqy on 22-11-25.
//

#ifndef MYPL_EXPRESSION_H
#define MYPL_EXPRESSION_H

#include <utility>

#include "AstNode.h"


namespace qwq {


    class Type;
    class VariableDeclaration;
    class FunctionDeclaration;

    class Expression : public AstNode {
    public:
        void printAst(int depth) override;
    };

    class Identifier : public Expression {
    public:
        explicit Identifier(std::string name, YYLTYPE loc = defaultLoc) : name(std::move(name)), loc(std::move(loc)) {}

        Identifier(const Identifier &id) : name(id.name), loc(id.loc) {}

        YYLTYPE getLocation() { return loc; }
        Element eval() override;
        void printAst(int depth) override;

        std::string name;
        ElePtr symbol;
    private:

        YYLTYPE loc;
    };

    class ArrayAccess : public Expression {
    public:
        // 一维数组
        ArrayAccess(std::shared_ptr<Identifier> id, std::shared_ptr<Expression> index, YYLTYPE loc)
                : id(std::move(id)), index(std::move(index)), loc(std::move(loc)) {}

        // 多维数组
        ArrayAccess(std::shared_ptr<ArrayAccess> arrayAccess, std::shared_ptr<Expression> index, YYLTYPE loc)
                : arrayExpr(std::move(arrayAccess)), index(std::move(index)), loc(std::move(loc)) {}

        YYLTYPE getLocation() { return loc; }
        Element eval() override;
        void printAst(int depth) override;
        std::shared_ptr<Identifier> getId() {
            if (id != nullptr) {
                return id;
            }
            else {
                return arrayExpr->getId();
            }
        }

    private:
        std::shared_ptr<Identifier> id = nullptr;
        std::shared_ptr<ArrayAccess> arrayExpr = nullptr;
        std::shared_ptr<Expression> index;
        YYLTYPE loc;
    };

    class Factor : public Expression {
    public:
        explicit Factor(std::shared_ptr<Expression> exp) : exp(std::move(exp)) {}
        Element eval() override;
        void printAst(int depth) override;

    private:
        std::shared_ptr<Expression> exp;
    };

    class Item : public Expression {
    public:
        explicit Item(std::shared_ptr<Factor> factor) : rhs(std::move(factor)) {}
        explicit Item(std::shared_ptr<Item> lhs,
                      std::shared_ptr<Factor> rhs = nullptr,
                      int op = -1)
                : lhs(std::move(lhs)), op(op), rhs(std::move(rhs)) {}
        Element eval() override;
        void printAst(int depth) override;

    private:
        std::shared_ptr<Item> lhs = nullptr;
        std::shared_ptr<Factor> rhs = nullptr;
        int op = -1;
    };

    class ArithmeticExpression : public Expression {
    public:
        // 形如：a op b
        explicit ArithmeticExpression(std::shared_ptr<ArithmeticExpression> lhs, std::shared_ptr<Item> rhs,
                                      int op, YYLTYPE loc)
                : lhs(std::move(lhs)), rhs(std::move(rhs)), op(op), loc(std::move(loc)) {}

        // 形如：a
        explicit ArithmeticExpression(std::shared_ptr<Item> item, YYLTYPE loc)
                : rhs(std::move(item)), loc(std::move(loc)) {}

        YYLTYPE getLocation() { return loc; }
        Element eval() override;
        void printAst(int depth) override;

    private:
        std::shared_ptr<ArithmeticExpression> lhs = nullptr;
        std::shared_ptr<Item> rhs = nullptr;
        int op = -1;
        YYLTYPE loc;
    };

    class LogicalExpression : public Expression {
    public:
        // 形如：a op b
        explicit LogicalExpression(std::shared_ptr<LogicalExpression> lhs, std::shared_ptr<Factor> rhs,
                                   int op, YYLTYPE loc)
                : lhs(std::move(lhs)), rhs(std::move(rhs)), op(op), loc(std::move(loc)) {}

        // 形如：a
        explicit LogicalExpression(std::shared_ptr<Factor> factor, YYLTYPE loc)
                : rhs(std::move(factor)), loc(std::move(loc)) {}

        YYLTYPE getLocation() { return loc; }
        Element eval() override;
        void printAst(int depth) override;

    private:
        std::shared_ptr<LogicalExpression> lhs = nullptr;
        std::shared_ptr<Factor> rhs = nullptr;
        int op = -1;
        YYLTYPE loc;
    };


    class SliceExpression : public Expression {
    public:
        SliceExpression(std::shared_ptr<Identifier> id, std::shared_ptr<Expression> left, std::shared_ptr<Expression> right, YYLTYPE loc)
                : id(std::move(id)), left(std::move(left)), right(std::move(right)), loc(std::move(loc)) {}

        YYLTYPE getLocation() { return loc; }
        Element eval() override;
        void printAst(int depth) override;

    private:
        std::shared_ptr<Identifier> id;
        std::shared_ptr<Expression> left;
        std::shared_ptr<Expression> right;
        YYLTYPE loc;
    };

    class AssignExpression : public Expression {
    public:
        // 给标识符赋值
        AssignExpression(std::shared_ptr<Identifier> id, std::shared_ptr<Expression> rhs, YYLTYPE loc = defaultLoc)
                : id(std::move(id)), rhs(std::move(rhs)), loc(std::move(loc)) {}

        // 给数组赋值
        AssignExpression(std::shared_ptr<ArrayAccess> arrayAccess, std::shared_ptr<Expression> rhs, YYLTYPE loc)
                : arrayExpr(std::move(arrayAccess)), rhs(std::move(rhs)), loc(std::move(loc)) {}

        YYLTYPE getLocation() { return loc; }
        Element eval() override;
        void printAst(int depth) override;
    private:
        std::shared_ptr<Identifier> id = nullptr;
        std::shared_ptr<Expression> rhs = nullptr;
        std::shared_ptr<ArrayAccess> arrayExpr = nullptr; // 只有对数组元素赋值时才使用
        YYLTYPE loc;
    };

    class FunctionCall : public Expression {
    public:
        // func(xxx)
        FunctionCall(std::shared_ptr<Identifier> funcId, std::shared_ptr<ExpressionList> arguments, YYLTYPE loc)
                : funcId(std::move(funcId))
                , arguments(std::move(arguments))
                , loc(std::move(loc)) {}

        // a.func(xxx)
        FunctionCall(std::shared_ptr<Identifier> varId, std::shared_ptr<Identifier> funcId, std::shared_ptr<ExpressionList> arguments, YYLTYPE loc)
                : varId(std::move(varId))
                , funcId(std::move(funcId))
                , arguments(std::move(arguments))
                , loc(std::move(loc)) {}

        YYLTYPE getLocation() { return loc; }
        Element eval() override;
        void printAst(int depth) override;

    private:
        std::shared_ptr<Identifier> varId = nullptr;
        std::shared_ptr<Identifier> funcId;
        std::shared_ptr<ExpressionList> arguments;
        YYLTYPE loc;
    };

    class RelationalExpression : public Expression {
    public:
        // 形如：a op b
        explicit RelationalExpression(std::shared_ptr<ArithmeticExpression> lhs,
                                      std::shared_ptr<ArithmeticExpression> rhs, int op, YYLTYPE loc)
                : lhs(std::move(lhs)), rhs(std::move(rhs)), op(op), loc(std::move(loc)) {}
//
//        // 形如：a
//        explicit RelationalExpression(std::shared_ptr<ArithmeticExpression> lhs, YYLTYPE loc)
//                : lhs(std::move(lhs)), loc(std::move(loc)) {}
        Element eval() override;
        void printAst(int depth) override;

    private:
        std::shared_ptr<ArithmeticExpression> lhs;
        std::shared_ptr<ArithmeticExpression> rhs;
        int op;
        YYLTYPE loc;
    };

    class Block : public Expression {
    public:
        explicit Block(std::shared_ptr<StatementList> statementList) : statementList(std::move(statementList)) {}
        Element eval() override;
        void printAst(int depth) override;

        std::shared_ptr<StatementList> statementList;
    };

}
#endif //MYPL_EXPRESSION_H
