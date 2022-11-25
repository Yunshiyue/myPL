//
// Created by Qingyue on 2022/11/25.
//

#ifndef MYPL_TYPE_H
#define MYPL_TYPE_H

#include <utility>

#include "AstNode.h"
#include "Expression.h"

enum class TypeName {
    INT,
    DOUBLE,
    FLOAT,
    BOOLEAN,
    CLASS,
    ARRAY
};

class Type : public AstNode {
public:
    Type(int type, std::shared_ptr<Identifier> id) : type(type), id(std::move(id)) {}
    virtual TypeName getTypeName() = 0;
protected:
    int type;
    std::shared_ptr<Identifier> id;
};

class ArrayType : public Type {
public:
    ArrayType(int type, std::shared_ptr<Identifier> id, int capacity)
    : Type(type, std::move(id))
    , capacity(capacity) {}
    TypeName getTypeName() override { return TypeName::ARRAY; }
private:
    int capacity;
};

class IntType : public Type {
public:
    IntType(int type, std::shared_ptr<Identifier> id) : Type(type, std::move(id)) {}
    TypeName getTypeName() override { return TypeName::ARRAY; }
private:
};

class DoubleType : public Type {
public:
    DoubleType(int type, std::shared_ptr<Identifier> id) : Type(type, std::move(id)) {}
    TypeName getTypeName() override { return TypeName::DOUBLE; }
private:
};

class FloatType : public Type {
public:
    FloatType(int type, std::shared_ptr<Identifier> id) : Type(type, std::move(id)) {}
    TypeName getTypeName() override { return TypeName::FLOAT; }
private:
};

class BooleanType : public Type {
public:
    BooleanType(int type, std::shared_ptr<Identifier> id) : Type(type, std::move(id)) {}
    TypeName getTypeName() override { return TypeName::BOOLEAN; }
private:
};

class ClassType : public Type {
public:
    ClassType(int type, std::shared_ptr<Identifier> id, std::shared_ptr<Identifier> classId)
    : Type(type, std::move(id))
    , classId(std::move(classId)) {}
    TypeName getTypeName() override { return TypeName::CLASS; }
private:
    std::shared_ptr<Identifier> classId;
};

#endif //MYPL_TYPE_H
