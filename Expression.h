//
// Created by qqy on 22-11-25.
//

#ifndef MYPL_EXPRESSION_H
#define MYPL_EXPRESSION_H

#include <utility>

#include "AstNode.h"

class Type;

class Expression : public AstNode {
public:
};

class Identifier : public Expression {
public:
    explicit Identifier(std::string name) : name(std::move(name)) {}
    Identifier(const Identifier& id) : name(id.name) {}
private:
    std::string name;
};



class Factor : public Expression {
public:
    explicit Factor(std::shared_ptr<Expression> exp) : exp(std::move(exp)) {}
private:
    std::shared_ptr<Expression> exp;
};

class Item : public Expression {
public:
    explicit Item(std::shared_ptr<Factor> lhs,
                  std::shared_ptr<Factor> rhs = nullptr,
                  int op = -1)
                 : lhs(std::move(lhs))
                 , op(op)
                 , rhs(std::move(rhs)) {}

private:
    std::shared_ptr<Factor> lhs;
    std::shared_ptr<Factor> rhs;
    int op;
};

class ArithmeticExpression : public Expression {
public:
    explicit ArithmeticExpression(std::shared_ptr<Item> lhs, std::shared_ptr<Item> rhs = nullptr,
                         int op = -1)
                         : lhs(std::move(lhs))
                         , rhs(std::move(rhs))
                         , op(op) {}
private:
    std::shared_ptr<Item> lhs;
    std::shared_ptr<Item> rhs;
    int op;
};

class LogicalExpression : public Expression {
public:
    explicit LogicalExpression(std::shared_ptr<Factor> lhs, std::shared_ptr<Factor> rhs = nullptr,
                      int op = -1)
                      : lhs(std::move(lhs))
                      , rhs(std::move(rhs))
                      , op(op) {}
private:
    std::shared_ptr<Factor> lhs;
    std::shared_ptr<Factor> rhs;
    int op;
};

// TODO string各种操作
class StringExpression : public Expression {
public:
private:
    std::string value;
};

// TODO 切片另外2种
class SliceExpression : public Expression {
public:
    SliceExpression(std::shared_ptr<Identifier> id, int left, int right)
    : id(std::move(id))
    , left(left)
    , right(right) {}
private:
    std::shared_ptr<Identifier> id;
    int left;
    int right;
};

// TODO: array
class AssignExpression : public Expression {
public:
private:
    std::shared_ptr<Identifier> id;
    std::shared_ptr<Expression> rhs;
};

class FunctionCall : public Expression {
public:
private:
    std::shared_ptr<Identifier> id;
    std::shared_ptr<ExpressionList> arguments;
};

class RelationalExpression : public Expression {
public:
    explicit RelationalExpression(std::shared_ptr<ArithmeticExpression> lhs,
                         std::shared_ptr<ArithmeticExpression> rhs = nullptr, int op = -1)
                         : lhs(std::move(lhs))
                         , rhs(std::move(rhs))
                         , op(op) {}
private:
    std::shared_ptr<ArithmeticExpression> lhs;
    std::shared_ptr<ArithmeticExpression> rhs;
    int op;
};

class Block : Expression {
public:
    StatementList statementLists;
};


#endif //MYPL_EXPRESSION_H
