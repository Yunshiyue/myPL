//
// Created by Qingyue on 2022/11/25.
//

#ifndef MYPL_LITERAL_H
#define MYPL_LITERAL_H

#include "Expression.h"

class Literal : public Expression {
public:
private:
};

class Character : public Literal {
public:
    Character(int value) : value(value) {}
private:
    int value;
};

class Boolean : public Literal {
public:
    Boolean(int v) { v >= 1 ? value = 1 : value = 0; }
private:
    int value;
};

class Double : public Literal {
public:
    Double(double value) : value(value) {}
private:
    double value;
};

class Float : public Literal {
public:
    Float(float value) : value(value) {}
private:
    float value;
};



#endif //MYPL_LITERAL_H
