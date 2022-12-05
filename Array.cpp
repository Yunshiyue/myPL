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
        result->sizeList.push_back(1);
    }
    // 维数不同，返回一个数组
    else {
        int num = sizeList.size() - index.size();
        for (int i = sizeList.size() - num; i < sizeList.size(); i++) {
            result->sizeList.push_back(sizeList[i]);
        }
    }

    return result;
}
