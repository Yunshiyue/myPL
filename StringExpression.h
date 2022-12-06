//
// Created by Qingyue on 2022/11/26.
//

#ifndef MYPL_STRINGEXPRESSION_H
#define MYPL_STRINGEXPRESSION_H

#include "Expression.h"

#include <utility>
#include <algorithm>

namespace qwq {


    class StringExpression : public Expression {

    };

    class StringLiteral : public StringExpression {
    public:
        // 字符串字面值
        explicit StringLiteral(std::string s) : value(std::move(s)) {}
        Element eval() override;

    private:
        std::string value;
    };

    class StringIdentifier : public StringExpression {
    public:
        explicit StringIdentifier(std::shared_ptr<Identifier> id) : id(std::move(id)) {}
        Element eval() override;

    private:
        std::shared_ptr<Identifier> id;
    };

    class StringOperation : public StringExpression {
    public:
        // 根据op判断操作类型
        // 除+和subStr外的其他操作
        StringOperation(std::shared_ptr<StringExpression> strExpr, int op) : strExpr(std::move(strExpr)), op(op) {}
        StringOperation(std::shared_ptr<StringIdentifier> strId, int op) : strId(std::move(strId)), op(op) {}


        // subStr操作
        StringOperation(std::shared_ptr<StringExpression> strExpr, int op, std::shared_ptr<Expression> leftRange,
                        std::shared_ptr<Expression> rightRange)
                : strExpr(std::move(strExpr)), op(op), leftRange(std::move(leftRange)),
                  rightRange(std::move(rightRange)) {}
        StringOperation(std::shared_ptr<StringIdentifier> strId, int op, std::shared_ptr<Expression> leftRange,
            std::shared_ptr<Expression> rightRange)
                : strId(std::move(strId)), op(op), leftRange(std::move(leftRange)),
                    rightRange(std::move(rightRange)) {}

        // +操作
        StringOperation(std::shared_ptr<StringExpression> lhs, int op, std::shared_ptr<StringExpression> rhs)
        : strExpr(std::move(lhs))
        , op(op)
        , rhs(std::move(rhs)) {}
        Element eval() override;

    private:
        std::shared_ptr<StringIdentifier> strId = nullptr;
        std::shared_ptr<StringExpression> strExpr = nullptr;
        int op;
        std::shared_ptr<Expression> leftRange = nullptr;  // substr left
        std::shared_ptr<Expression> rightRange = nullptr;  // substr right
        std::shared_ptr<StringExpression> rhs = nullptr;
    };

    class StringFuncExpression : public StringExpression {
    public:
        explicit StringFuncExpression(std::shared_ptr<FunctionCall> funcExpr) : funcExpr(std::move(funcExpr)) {}
        Element eval() override;

    private:
        std::shared_ptr<FunctionCall> funcExpr;
    };

}

#endif //MYPL_STRINGEXPRESSION_H

