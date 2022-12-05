#include "ProgramBlock.h"

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