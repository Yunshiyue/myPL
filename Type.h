//
// Created by Qingyue on 2022/11/25.
//

#ifndef MYPL_TYPE_H
#define MYPL_TYPE_H

#include <utility>

#include "AstNode.h"
#include "Expression.h"

namespace qwq {


    enum class TypeName {
        NONE,
        INT,
        CHAR,
        DOUBLE,
        BOOLEAN,
        CLASS,
        ARRAY
    };

    class Type : public AstNode {
    public:
        explicit Type(int type) : type(type) {}

        virtual TypeName getTypeName() { return TypeName::NONE; };
    protected:
        int type;   // 初始化时，传入词法对应的标识符，比如int、double、char对应的ID
    };

    class ArrayType : public Type {
    public:
        // TODO 构造函数内部要根据eleType初始化elementType。词法定义好后可以做�?
        ArrayType(int type, int eleType, int capacity)
                : Type(type), capacity(capacity) {}

        TypeName getTypeName() override { return TypeName::ARRAY; }

        TypeName getElementName() { return elementType; }

    private:
        TypeName elementType;   // 数组存放元素的类�?
        int capacity;
    };

    class IntType : public Type {
    public:
        explicit IntType(int type) : Type(type) {}

        TypeName getTypeName() override { return TypeName::INT; }

    private:
    };

    class DoubleType : public Type {
    public:
        explicit DoubleType(int type) : Type(type) {}

        TypeName getTypeName() override { return TypeName::DOUBLE; }

    private:
    };


    class BooleanType : public Type {
    public:
        explicit BooleanType(int type) : Type(type) {}

        TypeName getTypeName() override { return TypeName::BOOLEAN; }

    private:
    };

    class CharType : public Type {
    public:
        explicit CharType(int type) : Type(type) {}

        TypeName getTypeName() override { return TypeName::CHAR; }

    private:
    };

    class ClassType : public Type {
    public:
        ClassType(int type, std::shared_ptr<Identifier> classId, std::shared_ptr<Type> templateType = nullptr)
                : Type(type), classId(std::move(classId)), templateType(std::move(templateType)) {}

        TypeName getTypeName() override { return TypeName::CLASS; }

        std::shared_ptr<Identifier> getClassId() { return classId; }

        std::shared_ptr<Type> getTemplateType() { return templateType; }

    private:
        std::shared_ptr<Identifier> classId;
        std::shared_ptr<Type> templateType = nullptr;   // 模板类类型。非模板类为nullptr
    };

}

#endif //MYPL_TYPE_H
