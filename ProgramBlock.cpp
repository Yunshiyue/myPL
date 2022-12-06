#include "ProgramBlock.h"
#include "printAst.h"

Element qwq::ProgramBlock::eval()  {
    SymbolManager::addLayer();
    SymbolManager::addStatus(SymbolManager::MAIN);
    SymbolManager::addLayerF();
    for (auto& s : *stmts) {
        s->eval();
    }
    SymbolManager::popLayer();
    return EMPTY;
}

// 打印语法树

void qwq::ProgramBlock::printAst(int depth) {
    io::print_ident(depth);
    std::cout << "Program";
    io::print_endl();
    for (auto& s : *stmts) {
        s->printAst(depth+1);
    }
}