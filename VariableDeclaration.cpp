//
// Created by QQY on 2022/11/29.
//

#include "VariableDeclaration.h"
#include "printAst.h"


// TODO 模板未实现
Element qwq::VariableDeclaration::eval() {
    // 当前作用域不可以重复声明
    auto symbol = SymbolManager::lookupTop(id->name);
    if (symbol != nullptr) {
        std::cerr << "this variable has been used: " << id->name << std::endl;
        exit(1);
    }

    // 变量声明时，符号表新建记录
    ElePtr result = std::make_shared<Element>();
    result->type = type->getTypeName();
    SymbolManager::add(id->name, result);
    return *result;
}

Element qwq::VarDeclByExpr::eval() {
    // 当前作用域不可以重复声明
    auto symbol = SymbolManager::lookupTop(id->name);
    if (symbol != nullptr) {
        std::cerr << "this variable has been used: " << id->name << std::endl;
        exit(1);
    }

    // 求出赋值表达式的值
    auto value = assignmentExpr->eval();

    // 变量声明时，符号表新建记录
    ElePtr result = std::make_shared<Element>();
    result->type = getType()->getTypeName();
    *result = value;
    SymbolManager::add(id->name, result);
    return *result;
}

Element qwq::VarDeclAssignStmt::eval() {
    variableDeclarationAssign->eval();
    return EMPTY;
}

// TODO
Element qwq::ObjectDeclaration::eval() {
    return AstNode::eval();
}

// 打印语法树

void qwq::VariableDeclaration::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "VariableDeclaration";
    io::print_endl();
    type->printAst(depth+1);
    id->printAst(depth+1);
    if (templateType != nullptr) {
        templateType->printAst(depth+1);
    }
}

void qwq::VariableDeclarationAssign::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "VariableDeclarationAssign";
    io::print_endl();
    type->printAst(depth+1);
    id->printAst(depth+1);
    if (templateType != nullptr) {
        templateType->printAst(depth+1);
    }
}

void qwq::VarDeclByExpr::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "VarDeclByExpr";
    io::print_endl();
    type->printAst(depth+1);
    if (templateType != nullptr) {
        templateType->printAst(depth+1);
    }
    id->printAst(depth+1);
    io::print_ident(depth+1);
    std::cout << "=";
    io::print_endl();
    assignmentExpr->printAst(depth+1);
}

void qwq::ObjectDeclaration::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "VarDeclByExpr";
    io::print_endl();
    type->printAst(depth+1);
    if (templateType != nullptr) {
        templateType->printAst(depth+1);
    }
    id->printAst(depth+1);
    io::print_ident(depth+1);
    std::cout << "=";
    io::print_endl();
    io::print_ident(depth+1);
    std::cout << "ExpressionList";
    io::print_endl();
    for (int i = 0; i < expressionList->size(); i++) {
        (*expressionList)[i]->printAst(depth+2);
    }
}

void qwq::VarDeclAssignStmt::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "VarDeclAssignStmt";
    io::print_endl();
    variableDeclarationAssign->printAst(depth+1);
}