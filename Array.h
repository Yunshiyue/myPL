//
// Created by QQY on 2022/12/3.
//

#ifndef MYPL_ARRAY_H
#define MYPL_ARRAY_H

#include <vector>
#include <memory>


class Array {
public:
    enum class ArrayType { INTEGER, DOUBLE, CHAR, BOOL, STRING };

    Array() = default;
    bool operator==(const Array& rhs) const;
    bool operator!=(const Array& rhs) const;
    Array& operator=(const Array& rhs);

    ArrayType type;
    std::vector<int> sizes;  // 记录每一维的size
    std::vector<int> intData;
    std::vector<double> doubleData;
    std::vector<std::string> stringData;
};


#endif //MYPL_ARRAY_H
