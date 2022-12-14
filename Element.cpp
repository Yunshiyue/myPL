//
// Created by QQY on 2022/12/3.
//

#include "Element.h"

Element Element::operator+(const Element &rhs) const {
    Element result;
    // 2个至少有一个数组
    if (type == ElementType::ARRAY || rhs.type == ElementType::ARRAY) {
        std::cerr << "can't add array" << std::endl;
        exit(1);
    }
    // 字符串
    else if (type == ElementType::STRING && rhs.type == ElementType::STRING) {
        result.type = ElementType::STRING;
        result.strVal = strVal + rhs.strVal;
    }
    // double + double
    else if (type == ElementType::DOUBLE && rhs.type == ElementType::DOUBLE) {
        result.type = ElementType::DOUBLE;
        result.doubleVal = doubleVal + rhs.doubleVal;
    }
    // int + double（自动类型转化）
    else if (type == ElementType::INTEGER && rhs.type == ElementType::DOUBLE) {
        result.type = ElementType::DOUBLE;
        result.doubleVal = intVal + rhs.doubleVal;
    }
    // double + int（自动类型转换）
    else if (type == ElementType::DOUBLE && rhs.type == ElementType::INTEGER) {
        result.type = ElementType::DOUBLE;
        result.doubleVal= doubleVal + rhs.intVal;
    }
    // int + int
    else if (type == ElementType::INTEGER && rhs.type == ElementType::INTEGER) {
        result.type = ElementType::INTEGER;
        result.intVal = intVal + rhs.intVal;
    }
    else {
        std::cerr << "not implement + operation for these two type" << std::endl;
    }
    return result;
}

Element Element::operator-(const Element &rhs) const {
    Element result;
    // 2个至少有一个数组
    if (type == ElementType::ARRAY || rhs.type == ElementType::ARRAY) {
        std::cerr << "can't sub array" << std::endl;
        exit(1);
    }
    // 字符串
    else if (type == ElementType::STRING || rhs.type == ElementType::STRING) {
        std::cerr << "can't sub string" << std::endl;
        exit(1);
    }
    // double - double
    else if (type == ElementType::DOUBLE && rhs.type == ElementType::DOUBLE) {
        result.type = ElementType::DOUBLE;
        result.doubleVal = doubleVal - rhs.doubleVal;
    }
    // int - double（自动类型转化）
    else if (type == ElementType::INTEGER && rhs.type == ElementType::DOUBLE) {
        result.type = ElementType::DOUBLE;
        result.doubleVal = intVal - rhs.doubleVal;
    }
    // double - int（自动类型转换）
    else if (type == ElementType::DOUBLE && rhs.type == ElementType::INTEGER) {
        result.type = ElementType::DOUBLE;
        result.doubleVal= doubleVal - rhs.intVal;
    }
    // int - int
    else if (type == ElementType::INTEGER && rhs.type == ElementType::INTEGER) {
        result.type = ElementType::INTEGER;
        result.intVal = intVal - rhs.intVal;
    }
    else {
        std::cerr << "not implement - operation for these two type" << std::endl;
        exit(1);
    }
    return result;
}

Element Element::operator*(const Element &rhs) const {
    Element result;
    // 2个至少有一个数组
    if (type == ElementType::ARRAY || rhs.type == ElementType::ARRAY) {
        std::cerr << "can't * array" << std::endl;
        exit(1);
    }
    // 字符串
    else if (type == ElementType::STRING || rhs.type == ElementType::STRING) {
        std::cerr << "can't * string" << std::endl;
        exit(1);
    }
    // double * double
    else if (type == ElementType::DOUBLE && rhs.type == ElementType::DOUBLE) {
        result.type = ElementType::DOUBLE;
        result.doubleVal = doubleVal * rhs.doubleVal;
    }
    // int * double（自动类型转化）
    else if (type == ElementType::INTEGER && rhs.type == ElementType::DOUBLE) {
        result.type = ElementType::DOUBLE;
        result.doubleVal = intVal * rhs.doubleVal;
    }
    // double * int（自动类型转换）
    else if (type == ElementType::DOUBLE && rhs.type == ElementType::INTEGER) {
        result.type = ElementType::DOUBLE;
        result.doubleVal= doubleVal * rhs.intVal;
    }
    // int * int
    else if (type == ElementType::INTEGER && rhs.type == ElementType::INTEGER) {
        result.type = ElementType::INTEGER;
        result.intVal = intVal * rhs.intVal;
    }
    else {
        std::cerr << "not implement * operation for these two type" << std::endl;
        exit(1);
    }
    return result;
}

Element Element::operator/(const Element &rhs) const {
    Element result;
    // 2个至少有一个数组
    if (type == ElementType::ARRAY || rhs.type == ElementType::ARRAY) {
        std::cerr << "can't * array" << std::endl;
        exit(1);
    }
    // 字符串
    else if (type == ElementType::STRING || rhs.type == ElementType::STRING) {
        std::cerr << "can't / string" << std::endl;
        exit(1);
    }
    // double / double
    else if (type == ElementType::DOUBLE && rhs.type == ElementType::DOUBLE) {
        result.type = ElementType::DOUBLE;
        result.doubleVal = doubleVal / rhs.doubleVal;
    }
    // int / double（自动类型转化）
    else if (type == ElementType::INTEGER && rhs.type == ElementType::DOUBLE) {
        result.type = ElementType::DOUBLE;
        result.doubleVal = intVal / rhs.doubleVal;
    }
    // double / int（自动类型转换）
    else if (type == ElementType::DOUBLE && rhs.type == ElementType::INTEGER) {
        result.type = ElementType::DOUBLE;
        result.doubleVal= doubleVal / rhs.intVal;
    }
    // int / int
    else if (type == ElementType::INTEGER && rhs.type == ElementType::INTEGER) {
        result.type = ElementType::INTEGER;
        result.intVal = intVal / rhs.intVal;
    }
    else {
        std::cerr << "not implement / operation for these two type" << std::endl;
        exit(1);
    }
    return result;
}

Element Element::operator>(const Element & rhs) const {
    Element result;
    result.type = ElementType::BOOL;
    // 2个至少有一个数组
    if (type == ElementType::ARRAY || rhs.type == ElementType::ARRAY) {
        std::cerr << "can't compare array" << std::endl;
        exit(1);
    }
    // 字符串字典序比较
    else if (type == ElementType::STRING && rhs.type == ElementType::STRING) {
        result.intVal = strVal > rhs.strVal;
    }
    // 有一个不是字符串
    else if (type == ElementType::STRING || rhs.type == ElementType::STRING) {
        std::cerr << "can't compare string with other type" << std::endl;
        exit(1);
    }
    // double > double
    else if (type == ElementType::DOUBLE && rhs.type == ElementType::DOUBLE) {
        result.intVal = doubleVal > rhs.doubleVal;
    }
    // int > double（自动类型转化）
    else if (type == ElementType::INTEGER && rhs.type == ElementType::DOUBLE) {
        result.intVal = intVal > rhs.doubleVal;
    }
    // double > int（自动类型转换）
    else if (type == ElementType::DOUBLE && rhs.type == ElementType::INTEGER) {
        result.intVal = doubleVal > rhs.intVal;
    }
    // 其他整数类型
    else {
        result.intVal = intVal > rhs.intVal;
    }
    return result;
}

Element Element::operator<(const Element & rhs) const {
    Element result;
    result.type = ElementType::BOOL;
    // 2个至少有一个数组
    if (type == ElementType::ARRAY || rhs.type == ElementType::ARRAY) {
        std::cerr << "can't compare array" << std::endl;
        exit(1);
    }
        // 字符串字典序比较
    else if (type == ElementType::STRING && rhs.type == ElementType::STRING) {
        result.intVal = strVal < rhs.strVal;
    }
        // 有一个不是字符串
    else if (type == ElementType::STRING || rhs.type == ElementType::STRING) {
        std::cerr << "can't compare string with other type" << std::endl;
        exit(1);
    }
    // double < double
    else if (type == ElementType::DOUBLE && rhs.type == ElementType::DOUBLE) {
        result.intVal = doubleVal < rhs.doubleVal;
    }
    // int < double（自动类型转化）
    else if (type == ElementType::INTEGER && rhs.type == ElementType::DOUBLE) {
        result.intVal = intVal < rhs.doubleVal;
    }
    // double > int（自动类型转换）
    else if (type == ElementType::DOUBLE && rhs.type == ElementType::INTEGER) {
        result.intVal = doubleVal < rhs.intVal;
    }
    // 其他整数类型
    else {
        result.intVal = intVal < rhs.intVal;
    }
    return result;
}

Element Element::operator!=(const Element & rhs) const {
    Element result;
    result.type = ElementType::BOOL;
    // 数组
    if (type == ElementType::ARRAY && rhs.type == ElementType::ARRAY) {
        result.intVal = array != rhs.array;
    }
    // 一个是数组，而另一个不是
    if (type == ElementType::ARRAY || rhs.type == ElementType::ARRAY) {
        std::cerr << "can't compare array with other type" << std::endl;
        exit(1);
    }
    // 字符串字典序比较
    else if (type == ElementType::STRING && rhs.type == ElementType::STRING) {
        result.intVal = strVal != rhs.strVal;
    }
    // 有一个不是字符串
    else if (type == ElementType::STRING || rhs.type == ElementType::STRING) {
        std::cerr << "can't compare string with other type" << std::endl;
        exit(1);
    }
    // double != double
    else if (type == ElementType::DOUBLE && rhs.type == ElementType::DOUBLE) {
        result.intVal = doubleVal != rhs.doubleVal;
    }
    // int != double（自动类型转化）
    else if (type == ElementType::INTEGER && rhs.type == ElementType::DOUBLE) {
        result.intVal = intVal != rhs.doubleVal;
    }
    // double != int（自动类型转换）
    else if (type == ElementType::DOUBLE && rhs.type == ElementType::INTEGER) {
        result.intVal = doubleVal != rhs.intVal;
    }
    // 其他整数类型
    else {
        result.intVal = intVal != rhs.intVal;
    }
    return result;
}

Element Element::operator==(const Element & rhs) const {
    Element result;
    result.type = ElementType::BOOL;
    // 数组
    if (type == ElementType::ARRAY && rhs.type == ElementType::ARRAY) {
        result.intVal = array == rhs.array;
    }
    // 一个是数组，而另一个不是
    if (type == ElementType::ARRAY || rhs.type == ElementType::ARRAY) {
        std::cerr << "can't compare array with other type" << std::endl;
        exit(1);
    }
    // 字符串字典序比较
    else if (type == ElementType::STRING && rhs.type == ElementType::STRING) {
        result.intVal = strVal == rhs.strVal;
    }
    // 有一个不是字符串
    else if (type == ElementType::STRING || rhs.type == ElementType::STRING) {
        std::cerr << "can't compare string with other type" << std::endl;
        exit(1);
    }
    // double == double
    else if (type == ElementType::DOUBLE && rhs.type == ElementType::DOUBLE) {
        result.intVal = doubleVal != rhs.doubleVal;
    }
    // int == double（自动类型转化）
    else if (type == ElementType::INTEGER && rhs.type == ElementType::DOUBLE) {
        result.intVal = intVal != rhs.doubleVal;
    }
    // double != int（自动类型转换）
    else if (type == ElementType::DOUBLE && rhs.type == ElementType::INTEGER) {
        result.intVal = doubleVal == rhs.intVal;
    }
    // 其他整数类型
    else {
        result.intVal = intVal == rhs.intVal;
    }
    return result;
}

Element Element::operator>=(const Element & rhs) const {
    Element result;
    result.type = ElementType::BOOL;
    // 2个至少有一个数组
    if (type == ElementType::ARRAY || rhs.type == ElementType::ARRAY) {
        std::cerr << "can't compare array" << std::endl;
        exit(1);
    }
    // 字符串字典序比较
    else if (type == ElementType::STRING && rhs.type == ElementType::STRING) {
        result.intVal = strVal >= rhs.strVal;
    }
    // 有一个不是字符串
    else if (type == ElementType::STRING || rhs.type == ElementType::STRING) {
        std::cerr << "can't compare string with other type" << std::endl;
        exit(1);
    }
    // double >= double
    else if (type == ElementType::DOUBLE && rhs.type == ElementType::DOUBLE) {
        result.intVal = doubleVal >= rhs.doubleVal;
    }
    // int >= double（自动类型转化）
    else if (type == ElementType::INTEGER && rhs.type == ElementType::DOUBLE) {
        result.intVal = intVal >= rhs.doubleVal;
    }
    // double >= int（自动类型转换）
    else if (type == ElementType::DOUBLE && rhs.type == ElementType::INTEGER) {
        result.intVal = doubleVal >= rhs.intVal;
    }
    // 其他整数类型
    else {
        result.intVal = intVal >= rhs.intVal;
    }
    return result;
}

Element Element::operator<=(const Element & rhs) const {
    Element result;
    result.type = ElementType::BOOL;
    // 2个至少有一个数组
    if (type == ElementType::ARRAY || rhs.type == ElementType::ARRAY) {
        std::cerr << "can't compare array" << std::endl;
        exit(1);
    }
    // 字符串字典序比较
    else if (type == ElementType::STRING && rhs.type == ElementType::STRING) {
        result.intVal = strVal <= rhs.strVal;
    }
    // 有一个不是字符串
    else if (type == ElementType::STRING || rhs.type == ElementType::STRING) {
        std::cerr << "can't compare string with other type" << std::endl;
        exit(1);
    }
    // double <= double
    else if (type == ElementType::DOUBLE && rhs.type == ElementType::DOUBLE) {
        result.intVal = doubleVal <= rhs.doubleVal;
    }
    // int <= double（自动类型转化）
    else if (type == ElementType::INTEGER && rhs.type == ElementType::DOUBLE) {
        result.intVal = intVal <= rhs.doubleVal;
    }
    // double <= int（自动类型转换）
    else if (type == ElementType::DOUBLE && rhs.type == ElementType::INTEGER) {
        result.intVal = doubleVal <= rhs.intVal;
    }
    // 其他整数类型
    else {
        result.intVal = intVal <= rhs.intVal;
    }
    return result;
}

Element Element::operator&&(const Element &rhs) const {
    Element result;
    result.type = ElementType::BOOL;
    if (type != ElementType::BOOL || rhs.type != ElementType::BOOL) {
        std::cerr << "can only and two booleans" << std::endl;
        exit(1);
    }
    result.intVal = intVal & rhs.intVal;
    return result;
}

Element Element::operator||(const Element &rhs) const {
    Element result;
    result.type = ElementType::BOOL;
    if (type != ElementType::BOOL || rhs.type != ElementType::BOOL) {
        std::cerr << "can only and two booleans" << std::endl;
        exit(1);
    }
    result.intVal = intVal | rhs.intVal;
    return result;
}

Element Element::operator%(const Element &rhs) const {
    Element result;
    if (type == ElementType::INTEGER && rhs.type == ElementType::INTEGER) {
        result.type = ElementType::INTEGER;
        result.intVal = intVal % rhs.intVal;
    }
    else {
        std::cerr << "cannot % non-integer type" << std::endl;
        exit(1);
    }
    return result;
}

Element &Element::operator=(const Element &rhs) {
    if (type == ElementType::NONE) {
        type = rhs.type;
        array = rhs.array;
        strVal = rhs.strVal;
        doubleVal = rhs.doubleVal;
        intVal = rhs.intVal;
        return *this;
        
    }

    // array赋值
    if (type == ElementType::ARRAY && rhs.type == ElementType::ARRAY) {
        array = rhs.array;
    }
    // rhs is array but lhs is not
    else if (type != ElementType::ARRAY && rhs.type == ElementType::ARRAY) {
        if (rhs.array.getTotalLength() != 1) {
            std::cerr << "cannot assign array to a non-array" << std::endl;
            exit(1);
        }
        if (rhs.array.type != switchToArrayType(type)) {
            std::cerr << "type is not same" << std::endl;
            exit(1);
        }
        if (type == ElementType::BOOL || type == ElementType::INTEGER || type == ElementType::CHAR) {
            intVal = *rhs.array.intData[0];
        }
        else if (type == ElementType::DOUBLE) {
            doubleVal = *rhs.array.doubleData[0];
        }
        else if (type == ElementType::STRING) {
            strVal = *rhs.array.stringData[0];
        }
        else {
            std::cerr << "rhs is a none-type array" << std::endl;
            exit(1);
        }
    }
    // lhs is array but rhs is not
    else if(type == ElementType::ARRAY && rhs.type != ElementType::ARRAY) {
        if (array.getTotalLength() != 1) {
            std::cerr << "cannot assign array to a non-array2" << std::endl;
            exit(1);
        }
        if (array.type != switchToArrayType(rhs.type)) {
            std::cerr << "type is not same2" << std::endl;
            exit(1);
        }
        if (rhs.type == ElementType::BOOL || rhs.type == ElementType::INTEGER || rhs.type == ElementType::CHAR) {
            *array.intData[0] = rhs.intVal;
        }
        else if (rhs.type == ElementType::DOUBLE) {
            *array.doubleData[0] = rhs.doubleVal;
        }
        else if (rhs.type == ElementType::STRING) {
            *array.stringData[0] = rhs.strVal;
        }
        else {
            std::cerr << "rhs is a none-type array2" << std::endl;
            exit(1);
        }
    }
    // string赋值
    else if (type == ElementType::STRING && rhs.type == ElementType::STRING) {
        strVal = rhs.strVal;
    }
    // 一个是string，另一个不是
    else if (type == ElementType::STRING || rhs.type == ElementType::STRING) {
        std::cerr << "cannot assign string with other type" << std::endl;
        exit(1);
    }
    // double = double
    else if (type == ElementType::DOUBLE && rhs.type == ElementType::DOUBLE) {
        doubleVal = rhs.doubleVal;
    }
    // double = int
    else if (type == ElementType::DOUBLE && rhs.type == ElementType::INTEGER) {
        doubleVal = rhs.intVal;
    }
    // 其他整数类型
    else {
        intVal = rhs.intVal;
    }
    return *this;
}


Element Element::pow(const Element &rhs) const {
    Element result;
    // 2个至少有一个数组
    if (type == ElementType::ARRAY || rhs.type == ElementType::ARRAY) {
        std::cerr << "can't ** array" << std::endl;
        exit(1);
    }
    // 字符串
    else if (type == ElementType::STRING || rhs.type == ElementType::STRING) {
        std::cerr << "can't ** string" << std::endl;
        exit(1);
    }
    // double ** double
    else if (type == ElementType::DOUBLE && rhs.type == ElementType::DOUBLE) {
        result.type = ElementType::DOUBLE;
        result.doubleVal = std::pow(doubleVal, rhs.doubleVal);
    }
    // int ** double（自动类型转化）
    else if (type == ElementType::INTEGER && rhs.type == ElementType::DOUBLE) {
        result.type = ElementType::DOUBLE;
        result.doubleVal = std::pow(intVal, rhs.doubleVal);
    }
    // double ** int（自动类型转换）
    else if (type == ElementType::DOUBLE && rhs.type == ElementType::INTEGER) {
        result.type = ElementType::DOUBLE;
        result.doubleVal= std::pow(doubleVal, rhs.intVal);
    }
    // int ** int
    else if (type == ElementType::INTEGER && rhs.type == ElementType::INTEGER) {
        result.type = ElementType::INTEGER;
        result.intVal = std::pow(intVal, rhs.intVal);
    }
    else {
        std::cerr << "not implement ** operation for these two type" << std::endl;
        exit(1);
    }
    return result;
}

Element Element::ediv(const Element &rhs) const {
    Element result;
    result.type = ElementType::INTEGER;
    // 2个至少有一个数组
    if (type == ElementType::ARRAY || rhs.type == ElementType::ARRAY) {
        std::cerr << "can't // array" << std::endl;
        exit(1);
    }
    // 字符串
    else if (type == ElementType::STRING || rhs.type == ElementType::STRING) {
        std::cerr << "can't // string" << std::endl;
        exit(1);
    }
    // double // double
    else if (type == ElementType::DOUBLE && rhs.type == ElementType::DOUBLE) {
        result.doubleVal = static_cast<int>(doubleVal / rhs.doubleVal);
    }
    // int // double（自动类型转化）
    else if (type == ElementType::INTEGER && rhs.type == ElementType::DOUBLE) {
        result.doubleVal = static_cast<int>(intVal / rhs.doubleVal);
    }
    // double // int（自动类型转换）
    else if (type == ElementType::DOUBLE && rhs.type == ElementType::INTEGER) {
        result.doubleVal= static_cast<int>(doubleVal / rhs.intVal);
    }
    // int // int
    else if (type == ElementType::INTEGER && rhs.type == ElementType::INTEGER) {
        result.intVal = intVal / rhs.intVal;
    }
    else {
        std::cerr << "not implement // operation for these two type" << std::endl;
        exit(1);
    }
    return result;
}

Array::ArrayType switchToArrayType(Element::ElementType type) {
    switch (type) {
        case Element::ElementType::INTEGER:
            return Array::ArrayType::INTEGER;
        case Element::ElementType::CHAR:
            return Array::ArrayType::CHAR;
        case Element::ElementType::BOOL:
            return Array::ArrayType::BOOL;
        case Element::ElementType::DOUBLE:
            return Array::ArrayType::DOUBLE;
        case Element::ElementType::STRING:
            return Array::ArrayType::STRING;
    }
}