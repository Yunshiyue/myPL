//
// Created by qqy on 22-11-25.
//

#ifndef MYPL_CLASSDECLARATION_H
#define MYPL_CLASSDECLARATION_H

#include <utility>

#include "Statement.h"
#include "Expression.h"

namespace qwq {

    class ClassHead : public Statement {
    public:
        ClassHead(std::shared_ptr<Identifier> id, std::shared_ptr<Identifier> templateId,
                  std::shared_ptr<Identifier> extendClassId)
                  : id(std::move(id))
                  , templateId(std::move(templateId))
                  , extendClassId(std::move(extendClassId)) {}

    private:
        std::shared_ptr<Identifier> id;
//        std::shared_ptr<Block> publicBlock = nullptr;
//        std::shared_ptr<Block> protectedBlock = nullptr;
//        std::shared_ptr<Block> privateBlock = nullptr;
        std::shared_ptr<Identifier> templateId = nullptr;
        std::shared_ptr<Identifier> extendClassId = nullptr;
    };

    class ClassDeclaration : public Statement {
    public:
        ClassDeclaration(std::shared_ptr<ClassHead> classHead, std::shared_ptr<Block> block)
        : classHead(std::move(classHead))
        , block(std::move(block)) {}
    private:
        std::shared_ptr<ClassHead> classHead;
        std::shared_ptr<Block> block;
    };



}
#endif //MYPL_CLASSDECLARATION_H
