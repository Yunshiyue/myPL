//
// Created by qqy on 22-11-25.
//

#ifndef MYPL_EXPRESSION_H
#define MYPL_EXPRESSION_H

#include "AstNode.h"

class Expression : public AstNode {
public:
};

class LogicalExpression : public Expression {
public:
private:
    std::shared_ptr<Expression> lhs;
    std::shared_ptr<Expression> rhs;
    int op;
};

class Factor : public Expression {
public:
private:
    std::shared_ptr<Expression> exp;
};

class Item : public Expression {
public:
private:
    std::shared_ptr<Factor> lhs;
    std::shared_ptr<Factor> rhs;
    int op;
};

class ArithmeticExpression : public Expression {
public:
private:
    std::shared_ptr<Item> lhs;
    std::shared_ptr<Item> rhs;
    int op;
};

class StringExpression : public Expression {
public:
};

class SliceExpression : public Expression {
public:
};

class AssignExpression : public Expression {
public:
};

class FunctionCall : public Expression {
public:
};

class RelationalExpression : public Expression {
public:
private:
    std::shared_ptr<ArithmeticExpression> lhs;
    std::shared_ptr<ArithmeticExpression> rhs;
    int op;
};




#endif //MYPL_EXPRESSION_H
