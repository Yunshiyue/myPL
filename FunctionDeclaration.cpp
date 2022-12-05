//
// Created by qqy on 22-11-25.
//

#include "FunctionDeclaration.h"

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
