//
// Created by Qingyue on 2022/11/25.
//

#include "Literal.h"
#include "printAst.h"

Element qwq::Character::eval() {
    Element result;
    result.type = Element::ElementType::CHAR;
    result.intVal = value;
    return result;
}

Element qwq::Boolean::eval() {
    Element result;
    result.type = Element::ElementType::BOOL;
    result.intVal = value;
    return result;
}

Element qwq::Integer::eval() {
    Element result;
    result.type = Element::ElementType::INTEGER;
    result.intVal = value;
    return result;
}

Element qwq::Real::eval() {
    Element result;
    result.type = Element::ElementType::DOUBLE;
    result.doubleVal = value;
    return result;
}

// 打印语法树

void qwq::Literal::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "Literal";
    io::print_endl();
}

void qwq::Character::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "Character";
    io::print_endl();
    io::print_ident(depth+1);
    std::cout << value;
    io::print_endl();
}

void qwq::Boolean::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "Boolean";
    io::print_endl();
    io::print_ident(depth);
    std::cout << value;
    io::print_endl();
}

void qwq::Integer::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "Integer";
    io::print_endl();
    io::print_ident(depth);
    std::cout << value;
    io::print_endl();
}

void qwq::Real::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "Double";
    io::print_endl();
    io::print_ident(depth);
    std::cout << value;
    io::print_endl();
}