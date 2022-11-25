//
// Created by qqy on 22-11-25.
//

#ifndef MYPL_ASTNODE_H
#define MYPL_ASTNODE_H

#include <vector>
#include <memory>
#include <string>


class CommonStatement;
class Expression;
class VariableDeclaration;

using StatementList = std::vector<std::shared_ptr<CommonStatement>>;
using ExpressionList = std::vector<std::shared_ptr<Expression>>;
using VariableList = std::vector<std::shared_ptr<VariableDeclaration>>;

class AstNode {
public:
    virtual ~AstNode() = default;
};


#endif //MYPL_ASTNODE_H
