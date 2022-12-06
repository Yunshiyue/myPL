//
// Created by QQY on 2022/12/3.
//

#ifndef MYPL_ARRAY_H
#define MYPL_ARRAY_H

#include <utility>
#include <vector>
#include <memory>
#include <string>


class Array {
public:
    enum class ArrayType { NONE, INTEGER, DOUBLE, CHAR, BOOL, STRING };

    Array() = default;
    explicit Array(ArrayType type, std::vector<int> sizes)
    : type(type)
    , sizeList(std::move(sizes)) {}

    bool operator==(const Array& rhs) const;
    bool operator!=(const Array& rhs) const;
    Array& operator=(const Array& rhs);

    std::shared_ptr<Array> at(std::vector<int> index);
    int getTotalLength() const;



    ArrayType type = ArrayType::NONE;
    std::vector<int> sizeList;  // 记录每一维的size
    std::vector<std::shared_ptr<int>> intData;
    std::vector<std::shared_ptr<double>> doubleData;
    std::vector<std::shared_ptr<std::string>> stringData;
private:
};


#endif //MYPL_ARRAY_H
