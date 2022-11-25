//
// Created by qqy on 22-11-25.
//

#ifndef MYPL_COMMONSTATEMENT_H
#define MYPL_COMMONSTATEMENT_H

#include "Statement.h"

class CommonStatement : public Statement {
public:
};


class IfStatement : public CommonStatement {
public:
};

class WhileStatement : public CommonStatement {
public:
};

class ForStatement : public CommonStatement {
public:
};

class VariableDeclaration : public CommonStatement {
public:
};

class ReturnStatement : public CommonStatement {
public:
};

class ExpressionStatement : public CommonStatement {
public:
};

class JumpStatement : public CommonStatement {
public:
};

#endif //MYPL_COMMONSTATEMENT_H
