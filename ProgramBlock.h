#ifndef MYPL_PROGRAMBLOCK_H
#define MYPL_PROGRAMBLOCK_H

#include "AstNode.h"
#include "Statement.h"

namespace qwq {


    class ProgramBlock : public AstNode
    {
    public:
        ProgramBlock() = default;
        
        Element eval() override;
    
        std::shared_ptr<std::vector<std::shared_ptr<Statement>>> stmts;
    
    };
}





#endif // PROGRAMBLOCK