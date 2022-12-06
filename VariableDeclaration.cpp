//
// Created by QQY on 2022/11/29.
//

#include "VariableDeclaration.h"


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
