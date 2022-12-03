//
// Created by Qingyue on 2022/11/25.
//

#ifndef MYPL_LITERAL_H
#define MYPL_LITERAL_H

#include "Expression.h"

namespace qwq {

    class Literal : public Expression {
    public:
    private:
    };

    class Character : public Literal {
    public:
        explicit Character(int value) : value(value) {}
        virtual Element eval() override;
    private:
        int value;
    };

    class Boolean : public Literal {
    public:
        explicit Boolean(int v) { v >= 1 ? value = 1 : value = 0; }
        virtual Element eval() override;

    private:
        int value;
    };

    class Integer : public Literal {
    public:
        explicit Integer(int v) : value(v) {}
        virtual Element eval() override;

    private:
        int value;
    };

    class Real : public Literal {
    public:
        explicit Real(double value) : value(value) {}
        virtual Element eval() override;

    private:
        double value;
    };



}
#endif //MYPL_LITERAL_H

