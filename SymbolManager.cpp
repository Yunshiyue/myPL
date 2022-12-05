//
// Created by QQY on 2022/12/3.
//

#include "SymbolManager.h"
#include "FunctionDeclaration.h"

using namespace qwq;
/*
 * Symbol Table
 */
std::vector<SymbolTable> SymbolManager::symbolTables_ = std::vector<SymbolTable>();
std::vector<std::map<std::string, FunPtr>> SymbolManager::funcTables_ = std::vector<std::map<std::string, FunPtr>>();
std::vector<SymbolManager::Status> SymbolManager::status_ = std::vector<SymbolManager::Status>();

ElePtr SymbolManager::lookup(const std::string &name) {
    ElePtr result = nullptr;
    for (auto it = symbolTables_.rbegin(); it != symbolTables_.rend(); ++it)
        if ((*it).find(name) != (*it).end()) {
            result = (*it)[name];
            break;
        }
    return result;
}

ElePtr SymbolManager::lookupTop(const std::string &name) {
    ElePtr result = nullptr;
    if (symbolTables_.back().find(name) != symbolTables_.back().end())
        result = symbolTables_.back()[name];
    return result;
}

void SymbolManager::addLayer() {
    symbolTables_.emplace_back();
}

void SymbolManager::add(const std::string &name, const ElePtr &symbol) {
    symbolTables_.back()[name] = symbol;
}

void SymbolManager::del(const std::string &name) {
    for (auto it = symbolTables_.rbegin(); it != symbolTables_.rend(); ++it)
        if ((*it).find(name) != (*it).end()) {
            it->erase(name);
            break;
        }
}

void SymbolManager::popLayer() {
    symbolTables_.pop_back();
}

FunPtr SymbolManager::lookupF(const std::string &name) {
    FunPtr result = nullptr;
    for (auto it = funcTables_.rbegin(); it != funcTables_.rend(); ++it)
        if ((*it).find(name) != (*it).end()) {
            result = (*it)[name];
            break;
        }
    return result;
}

void SymbolManager::addLayerF() {
    funcTables_.emplace_back();
}

void SymbolManager::addF(const std::string &name, const FunPtr &func) {
    funcTables_.back()[name] = func;
}

void SymbolManager::popLayerF() {
    funcTables_.pop_back();
}

bool SymbolManager::checkFunc() {
    for (auto it = status_.rbegin(); it != status_.rend(); ++it)
        if (*it == FUNC)
            return true;
    return false;
}

void SymbolManager::popFunc() {
    if (!checkFunc()) {
        std::cerr << "can't return here" << std::endl;
        exit(EXIT_FAILURE);
    }
    while(status_.back() != FUNC)
        status_.pop_back();
    status_.push_back(RETURN);
}
