//
// Created by Qingyue on 2022/11/25.
//

#ifndef MYPL_TYPE_H
#define MYPL_TYPE_H

#include <utility>

#include "AstNode.h"
#include "Expression.h"

namespace qwq {


//    enum class TypeName {
//        NONE,
//        INT,
//        CHAR,
//        DOUBLE,
//        BOOLEAN,
//        CLASS,
//        ARRAY,
//        STRING
//    };

    class Type : public AstNode {
    public:
        using TypeName = Element::ElementType;
        explicit Type(int type) : type(type) {}
        void printAst(int depth) override;
        virtual TypeName getTypeName() { return TypeName::NONE; };
    protected:
        int type;   // 初始化时，传入词法对应的标识符，比如int、double、char对应的ID
    };

    class ArrayType : public Type {
    public:
        ArrayType(int type, std::shared_ptr<Type> eleType, int capacity)
                : Type(type), elementType(std::move(eleType)), capacity(capacity) {}

        TypeName getTypeName() override { return TypeName::ARRAY; }

        TypeName getElementName() { return elementType->getTypeName(); }
        std::shared_ptr<Type> getElementType() { return elementType; }
        int getCapacity() const { return capacity; }
        void printAst(int depth) override;

    private:
        std::shared_ptr<Type> elementType;   // 数组存放元素的类型
        int capacity;
    };

    class IntType : public Type {
    public:
        explicit IntType(int type) : Type(type) {}

        TypeName getTypeName() override { return TypeName::INTEGER; }

        void printAst(int depth) override;

    private:
    };

    class DoubleType : public Type {
    public:
        explicit DoubleType(int type) : Type(type) {}

        TypeName getTypeName() override { return TypeName::DOUBLE; }

        void printAst(int depth) override;

    private:
    };


    class BooleanType : public Type {
    public:
        explicit BooleanType(int type) : Type(type) {}

        TypeName getTypeName() override { return TypeName::BOOL; }

        void printAst(int depth) override;

    private:
    };

    class CharType : public Type {
    public:
        explicit CharType(int type) : Type(type) {}

        TypeName getTypeName() override { return TypeName::CHAR; }

        void printAst(int depth) override;

    private:
    };

    class StringType : public Type {
    public:
        explicit StringType(int type) : Type(type) {}

        TypeName getTypeName() override { return TypeName::STRING; }

        void printAst(int depth) override;

    };

    class ClassType : public Type {
    public:
        ClassType(int type, std::shared_ptr<Identifier> classId, std::shared_ptr<Type> templateType = nullptr)
                : Type(type), classId(std::move(classId)), templateType(std::move(templateType)) {}

        TypeName getTypeName() override { return TypeName::CLASS; }

        std::shared_ptr<Identifier> getClassId() { return classId; }

        std::shared_ptr<Type> getTemplateType() { return templateType; }

        void printAst(int depth) override;

    private:
        std::shared_ptr<Identifier> classId;
        std::shared_ptr<Type> templateType = nullptr;   // 模板类类型。非模板类为nullptr
    };

}

#endif //MYPL_TYPE_H
