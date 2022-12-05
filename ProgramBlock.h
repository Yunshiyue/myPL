#ifndef MYPL_PROGRAMBLOCK_H
#define MYPL_PROGRAMBLOCK_H

#include "AstNode.h"
#include "Statement.h"

namespace qwq {


    class ProgramBlock : public AstNode
    {
    public:
        using AllStmts = std::vector<std::shared_ptr<Statement>>;
        ProgramBlock() = default;
        
        Element eval() override;
    
        std::shared_ptr<AllStmts> stmts = std::make_shared<AllStmts>();
    
    };
}





#endif // PROGRAMBLOCK