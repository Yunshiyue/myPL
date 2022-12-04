//
// Created by QQY on 2022/12/3.
//

#ifndef MYPL_ELEMENT_H
#define MYPL_ELEMENT_H

#include <string>
#include <iostream>
#include <cmath>
#include <utility>
#include "Array.h"

class Element {
public:
    enum class ElementType  { NONE, INTEGER, DOUBLE, CHAR, BOOL, ARRAY, STRING, CLASS };
    Element() = default;
    Element(ElementType type, int val) : type(type), intVal(val) {}
    Element(ElementType type, double val) : type(type), doubleVal(val) {}
    Element(ElementType type, std::string  val) : type(type), strVal(std::move(val)) {}
    Element(ElementType type, const Array& val) : type(type), array(val) {}

    Element operator+(const Element& rhs) const;
    Element operator-(const Element& rhs) const;
    Element operator*(const Element& rhs) const;
    Element operator/(const Element& rhs) const;

    Element operator>(const Element& rhs) const;
    Element operator<(const Element& rhs) const;
    Element operator!=(const Element& rhs) const;
    Element operator==(const Element& rhs) const;
    Element operator>=(const Element& rhs) const;
    Element operator<=(const Element& rhs) const;
    Element operator&&(const Element& rhs) const;
    Element operator||(const Element& rhs) const;
    Element operator%(const Element& rhs) const;
    Element pow(const Element& rhs) const;
    Element ediv(const Element& rhs) const;

    Element& operator=(const Element& rhs);

    //friend std::ostream& operator<<(std::ostream& os, const Element & element);
    ElementType type;
    int intVal;
    double doubleVal;
    std::string strVal;
    Array array;
};

const Element EMPTY = { Element::ElementType::INTEGER, 0 };


#endif //MYPL_ELEMENT_H
