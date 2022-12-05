//
// Created by QQY on 2022/12/3.
//

#ifndef MYPL_SYMBOLMANAGER_H
#define MYPL_SYMBOLMANAGER_H

#include <vector>
#include <memory>
#include <map>
#include <iostream>

#include "Element.h"


namespace qwq {
    class FunctionDeclaration;

    typedef std::shared_ptr<Element> ElePtr;
    typedef std::map<std::string, ElePtr> SymbolTable;
    using FunPtr = std::shared_ptr<FunctionDeclaration>;

    class SymbolManager {
    public:
        static ElePtr lookup(const std::string & name);
        static ElePtr lookupTop(const std::string &name);
        static void addLayer();
        static void add(const std::string & name, const ElePtr & symbol);
        static void del(const std::string & name);
        static void popLayer();

        static FunPtr lookupF(const std::string & name);
        static void addLayerF();
        static void addF(const std::string & name, const FunPtr & func);
        static void popLayerF();

        enum Status { MAIN, WHILE, FUNC, CONTINUE, BREAK, RETURN };
        static void addStatus(Status status) { status_.push_back(status); }
        static Status topStatus() { return status_.back(); }
        static bool checkFunc();
        static void popFunc();
        static void popStatus() { status_.pop_back(); }
    private:
        static std::vector<SymbolTable> symbolTables_;
        static std::vector<std::map<std::string, FunPtr>> funcTables_;

        static std::vector<Status> status_;
    };
}



#endif //MYPL_SYMBOLMANAGER_H
