//
// Created by qqy on 22-11-25.
//

#include "Expression.h"

Element qwq::Identifier::eval() {
    // 从符号表中找对应的符号
    symbol = SymbolManager::lookup(name);
    if (symbol == nullptr) {
        std::cerr << "can't refer to a uninitialized variable: " << name << std::endl;
        exit(1);
    }
    return *symbol;
}

Element qwq::Factor::eval() {
    return exp->eval();
}

// TODO
Element qwq::Item::eval() {
    if (lhs == nullptr) {
        return rhs->eval();
    }
    else {
        auto left = lhs->eval();
        auto right = rhs->eval();
        Element result;
        switch (op) {
            case 1:
                result = left * right;
                break;
            case 2:
                result = left / right;
                break;
            case 3:
                result = left % right;
                break;
            case 4:
                result = left.pow(right);
                break;
            case 5:
                result = left.ediv(right);
                break;
        }
        return result;
    }
}

// TODO
Element qwq::ArithmeticExpression::eval() {
    if (lhs == nullptr) {
        return rhs->eval();
    }
    else {
        auto left = lhs->eval();
        auto right = rhs->eval();
        Element result;
        switch (op) {
            case 1:
                result = left + right;
                break;
            case 2:
                result = left - right;
                break;
        }
        return result;
    }
}

// TODO
Element qwq::LogicalExpression::eval() {
    if (lhs == nullptr) {
        return rhs->eval();
    }
    else {
        auto left = lhs->eval();
        auto right = rhs->eval();
        Element result;
        switch (op) {
            case 1:
                result = left && right;
                break;
            case 2:
                result = left || right;
                break;
        }
        return result;
    }
}

// TODO
Element qwq::RelationalExpression::eval() {
    auto left = lhs->eval();
    auto right = rhs->eval();
    Element result;
    switch (op) {
        case 1:
            result = left > right;
            break;
        case 2:
            result = left >= right;
            break;
        case 3:
            result = left < right;
            break;
        case 4:
            result = left <= right;
            break;
        case 5:
            result = left == right;
            break;
        case 6:
            result = left != right;
            break;
    }
    return result;

}

Element qwq::AssignExpression::eval() {
    // 给标识符赋值
    Element result;
    auto value = arrayExpr->eval();
    if (id != nullptr) {
        result = id->eval();
        result = value;
        *(id->symbol) = result;
    }
    // TODO 给数组赋值
    else {

    }
    return result;
}
