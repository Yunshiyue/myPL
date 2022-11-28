//
// Created by qqy on 22-11-25.
//

#ifndef MYPL_CLASSDECLARATION_H
#define MYPL_CLASSDECLARATION_H

#include <utility>

#include "Statement.h"
#include "Expression.h"

namespace qwq {


    class ClassDeclaration : public Statement {
    public:
        // 非模板类
        ClassDeclaration(std::shared_ptr<Identifier> id, std::shared_ptr<Block> publicBlock,
                         std::shared_ptr<Block> protectedBlock, std::shared_ptr<Block> privateBlock)
                : id(std::move(id)), publicBlock(std::move(publicBlock)), protectedBlock(std::move(protectedBlock)),
                  privateBlock(std::move(privateBlock)) {}

        // 模板类
        ClassDeclaration(std::shared_ptr<Identifier> id, std::shared_ptr<Block> publicBlock,
                         std::shared_ptr<Block> protectedBlock, std::shared_ptr<Block> privateBlock,
                         std::shared_ptr<Identifier> templateId)
                : id(std::move(id)), publicBlock(std::move(publicBlock)), protectedBlock(std::move(protectedBlock)),
                  privateBlock(std::move(privateBlock)), templateId(std::move(templateId)) {}

    private:
        std::shared_ptr<Identifier> id;
        std::shared_ptr<Block> publicBlock = nullptr;
        std::shared_ptr<Block> protectedBlock = nullptr;
        std::shared_ptr<Block> privateBlock = nullptr;
        std::shared_ptr<Identifier> templateId = nullptr;
    };

}
#endif //MYPL_CLASSDECLARATION_H
