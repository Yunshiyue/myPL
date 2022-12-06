//
// Created by qqy on 22-11-25.
//

#include "FunctionDeclaration.h"
#include "printAst.h"
#include "VariableDeclaration.h"

Element qwq::FunctionDeclaration::eval() {
    // 检查函数是否已经被声明
    FunPtr func = SymbolManager::lookupF(functionHead->id->name);
    if (func != nullptr) {
        std::cerr << "this functions has been defined" << std::endl;
        exit(EXIT_FAILURE);
    }

    // 将本函数声明加入符号表
    SymbolManager::addF(functionHead->id->name, std::shared_ptr<qwq::FunctionDeclaration>(this));
    return EMPTY;
}

// 打印语法树

void qwq::FunctionHead::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "FunctionHead";
    io::print_endl();
    if (templateType != nullptr) {
        templateType->printAst(depth+1);
    }
    id->printAst(depth+1);
    for (int i = 0; i < arguments->size(); i++) {
        (*arguments)[i]->printAst(depth+1);
    }
    if (returnType != nullptr) {
        returnType->printAst(depth+1);
    }
}

void qwq::FunctionDeclaration::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "FunctionDeclaration";
    io::print_endl();
    functionHead->printAst(depth+1);
    block->printAst(depth+1);
}
