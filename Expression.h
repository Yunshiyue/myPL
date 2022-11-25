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
};

class ArithmeticExpression : public Expression {
public:
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


#endif //MYPL_EXPRESSION_H
