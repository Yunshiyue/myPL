//
// Created by QQY on 2022/12/3.
//

#include "Array.h"
#include "Element.h"

bool Array::operator==(const Array &rhs) const {
    // 检查类型
    if (type != rhs.type) {
        return false;
    }

    // 检查大小
    if (sizeList.size() != rhs.sizeList.size()) {
        return false;
    }

    // 检查每维维度是否一致
    for (int i = 0; i < sizeList.size(); i++) {
        if (sizeList[i] != rhs.sizeList[i]) {
            return false;
        }
    }

    // 检查每维度数据
    const int totalSize = getTotalLength();
    switch (type) {
        case ArrayType::INTEGER:
        case ArrayType::BOOL:
        case ArrayType::CHAR:
            for (int i = 0; i < totalSize; i++) {
                if (*intData[i] != *rhs.intData[i]) {
                    return false;
                }
            }
            break;
        case ArrayType::DOUBLE:
            for (int i = 0; i < totalSize; i++) {
                if (*doubleData[i] != *rhs.doubleData[i]) {
                    return false;
                }
            }
            break;
        case ArrayType::STRING:
            for (int i = 0; i < totalSize; i++) {
                if (*stringData[i] != *rhs.stringData[i]) {
                    return false;
                }
            }
            break;
    }
    return true;
}

bool Array::operator!=(const Array &rhs) const {
    return !operator==(rhs);
}

Array &Array::operator=(const Array &rhs) {
    if (type == ArrayType::NONE) {
        // 这里复制指针，不是值
        type = rhs.type;
        sizeList = rhs.sizeList;
        intData = rhs.intData;
        doubleData = rhs.doubleData;
        stringData = rhs.stringData;
        return *this;
    }

    if (type != rhs.type) {
        std::cerr << "two array have different type" << std::endl;
        exit(1);
    }

    // 检查大小
    if (sizeList.size() != rhs.sizeList.size()) {
        std::cerr << "two array have different size" << std::endl;
        exit(1);
    }

    // 检查每维维度是否一致
    for (int i = 0; i < sizeList.size(); i++) {
        if (sizeList[i] != rhs.sizeList[i]) {
            std::cerr << "two array have different size" << std::endl;
            exit(1);
        }
    }

    // 这里复制指针，不是值
    intData = rhs.intData;
    doubleData = rhs.doubleData;
    stringData = rhs.stringData;
    return *this;
}

int Array::getTotalLength() const {
    if (sizeList.empty()) {
        return 0;
    }
    int total = 1;
    for (const auto& num : sizeList) {
        total *= num;
    }
    return total;
}

std::shared_ptr<Array> Array::at(std::vector<int> index) {
    std::shared_ptr<Array> result = std::make_shared<Array>();
    result->type = type;

    // 计算大小
    if (sizeList.size() < index.size()) {
        std::cerr << "dimension out of bound" << std::endl;
        exit(1);
    }

    // 维数相同，只有一个元素
    if (sizeList.size() == index.size()) {
        // 只有1个元素，所以是1维
        result->sizeList.push_back(1);

        // 计算放入元素的索引，行主序
        int cIndex = 0;
        for (int i = 0; i < index.size() - 1; i++) {
            int c = index[i];
            for (int j = i + 1; j < sizeList.size(); j++) {
                c *= sizeList[j];
            }
            cIndex += c;
        }
        cIndex += index[index.size() - 1];

        // 放入
        if (type == ArrayType::INTEGER || type == ArrayType::BOOL || type == ArrayType::CHAR) {
            result->intData.push_back(intData[cIndex]);
        }
        else if (type == ArrayType::DOUBLE) {
            result->doubleData.push_back(doubleData[cIndex]);
        }
        else {
            result->stringData.push_back(stringData[cIndex]);
        }
    }
    // 维数不同，返回一个数组
    else {
        int num = sizeList.size() - index.size();
        // 加入维度
        for (int i = sizeList.size() - num; i < sizeList.size(); i++) {
            result->sizeList.push_back(sizeList[i]);
        }

        // 确定开始的索引
        int startIndex = 0;
        for (int i = 0; i < index.size() - 1; i++) {
            int c = index[i];
            for (int j = i + 1; j < sizeList.size(); j++) {
                c *= sizeList[j];
            }
            startIndex += c;
        }
        int length = result->getTotalLength();

        // 放入数据
        // 放入
        if (type == ArrayType::INTEGER || type == ArrayType::BOOL || type == ArrayType::CHAR) {
            for (int i = 0; i < length; i++)
                result->intData.push_back(intData[i]);
        }
        else if (type == ArrayType::DOUBLE) {
            for (int i = 0; i < length; i++)
                result->doubleData.push_back(doubleData[i]);
        }
        else {
            for (int i = 0; i < length; i++)
                result->stringData.push_back(stringData[i]);
        }
    }

    return result;
}

// void Array::push_size(int i) {
//     sizeList.push_back(i);
//     const int total = getTotalLength();
//     intData.reserve(total);
//     doubleData.reserve(total);
//     stringData.reserve(total);
// }

void Array::alloc_size() {
    const int total = getTotalLength();
    if (type == ArrayType::BOOL || type == ArrayType::CHAR || type == ArrayType::INTEGER) {
        intData.resize(total);
        for (auto& p : intData) {
            p = std::make_shared<int>(0);
        }
    }
    else if (type == ArrayType::DOUBLE) {
        doubleData.reserve(total);
        for (auto& p : doubleData) {
            p = std::make_shared<double>(0.0);
        }
    }
    else if (type == ArrayType::DOUBLE) {
        stringData.reserve(total);
        for (auto& p : stringData) {
            p = std::make_shared<std::string>("");
        }
    }
    else {
        std::cerr << "array has none type, cannot alloc memory" << std::endl;
        exit(1);
    }
}



std::ostream& operator<<(std::ostream& out, const Array& array) {
    if (array.type == Array::ArrayType::BOOL || array.type == Array::ArrayType::CHAR || array.type == Array::ArrayType::INTEGER) {
        for (const auto& a : array.intData) {
            std::cout << *a << "  ";
        }
    }
    else if (array.type == Array::ArrayType::DOUBLE) {
        for (const auto& a : array.doubleData) {
            std::cout << *a << "  ";
        }
    }
    else if (array.type == Array::ArrayType::STRING) {
        for (const auto& a : array.stringData) {
            std::cout << *a << "  ";
        }
    }
    else {
        std::cout << "empty array" << std::endl;
    }
    return out;
}

