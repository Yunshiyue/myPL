//
// Created by Qingyue on 2022/11/25.
//

#include "Literal.h"

Element qwq::Character::eval() {
    Element result;
    result.type = Element::ElementType::CHAR;
    result.intVal = value;
    return result;
}

Element qwq::Boolean::eval() {
    Element result;
    result.type = Element::ElementType::BOOL;
    result.intVal = value;
    return result;
}

Element qwq::Integer::eval() {
    Element result;
    result.type = Element::ElementType::INTEGER;
    result.intVal = value;
    return result;
}

Element qwq::Real::eval() {
    Element result;
    result.type = Element::ElementType::DOUBLE;
    result.doubleVal = value;
    return result;
}
