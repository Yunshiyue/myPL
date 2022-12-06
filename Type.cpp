//
// Created by Qingyue on 2022/11/25.
//

#include "Type.h"
#include "printAst.h"

// 打印语法树

void qwq::Type::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "Type";
    io::print_endl();
    io::print_ident(depth+1);
    std::cout << type;
    io::print_endl();
}

void qwq::ArrayType::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "ArrayType";
    io::print_endl();
    io::print_ident(depth+1);
    std::cout << "elementType";
    io::print_endl();
    elementType->printAst(depth+2);
    io::print_ident(depth+1);
    std::cout << "capacity";
    io::print_endl();
    io::print_ident(depth+2);
    std::cout << capacity;
    io::print_endl();
}

void qwq::IntType::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "IntType";
    io::print_endl();
    io::print_ident(depth+1);
    std::cout << type;
    io::print_endl();
}

void qwq::DoubleType::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "DoubleType";
    io::print_endl();
    io::print_ident(depth+1);
    std::cout << type;
    io::print_endl();
}

void qwq::BooleanType::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "BooleanType";
    io::print_endl();
    io::print_ident(depth+1);
    std::cout << type;
    io::print_endl();
}

void qwq::CharType::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "CharType";
    io::print_endl();
    io::print_ident(depth+1);
    std::cout << type;
    io::print_endl();
}

void qwq::StringType::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "StringType";
    io::print_endl();
    io::print_ident(depth+1);
    std::cout << type;
    io::print_endl();
}

void qwq::ClassType::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "ClassType";
    io::print_endl();
    if (templateType != nullptr) {
        templateType->printAst(depth+1);
    }
    classId->printAst(depth+1);
}