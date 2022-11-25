//
// Created by qqy on 22-11-25.
//

#ifndef MYPL_ASTNODE_H
#define MYPL_ASTNODE_H

#include <vector>
#include <memory>

using StatementList = std::vector<class Statement*>;
using ExpressionList = std::vector<class Expression*>;
using VariableList = std::vector<class VariableDeclaration*>;

class AstNode {
public:
    virtual ~AstNode() = default;
};


#endif //MYPL_ASTNODE_H
