//
// Created by qqy on 22-11-25.
//

#ifndef MYPL_FUNCTIONDECLARATION_H
#define MYPL_FUNCTIONDECLARATION_H

#include <utility>

#include "Statement.h"
#include "Type.h"
#include "ClassDeclaration.h"

class FunctionDeclaration : public Statement {
public:
    FunctionDeclaration(std::shared_ptr<Type> returnType, std::shared_ptr<Identifier> id,
                        std::shared_ptr<VariableList> arguments, std::shared_ptr<Block> block,
                        std::shared_ptr<Type> templateType = nullptr)
                        : returnType(std::move(returnType))
                        , id(std::move(id))
                        , arguments(std::move(arguments))
                        , block(std::move(block))
                        , templateType(std::move(templateType)) {}
    FunctionDeclaration(std::shared_ptr<Identifier> id,
                        std::shared_ptr<VariableList> arguments, std::shared_ptr<Block> block,
                        std::shared_ptr<Type> templateType = nullptr)
            : id(std::move(id))
            , arguments(std::move(arguments))
            , block(std::move(block))
            , templateType(std::move(templateType)) {}
private:
    friend class ClassDeclaration;
    std::shared_ptr<Type> returnType = nullptr;
    std::shared_ptr<Identifier> id;
    std::shared_ptr<VariableList> arguments = nullptr;
    std::shared_ptr<Block> block;
    std::shared_ptr<Type> templateType = nullptr;
};


#endif //MYPL_FUNCTIONDECLARATION_H
