//
// Created by QQY on 2022/11/29.
//

#ifndef MYPL_VARIABLEDECLARATION_H
#define MYPL_VARIABLEDECLARATION_H

#include <utility>

#include "CommonStatement.h"

namespace qwq {

    class VariableDeclaration : public Expression {
    public:
        // 形如：int a;
        VariableDeclaration(std::shared_ptr<Type> type, std::shared_ptr<Identifier> id, YYLTYPE loc)
                : type(std::move(type)), id(std::move(id)), loc(std::move(loc)) {}

//        // 形如：int a = exp;
//        VariableDeclaration(std::shared_ptr<Type> type, std::shared_ptr<Identifier> id,
//                            std::shared_ptr<Expression> assignmentExpr, YYLTYPE loc)
//                : type(std::move(type)), id(std::move(id)), assignmentExpr(std::move(assignmentExpr)),
//                  loc(std::move(loc)) {}

        // 形如：A<int> a;
        VariableDeclaration(std::shared_ptr<Type> type, std::shared_ptr<Type> templateType,
                            std::shared_ptr<Identifier> id, YYLTYPE loc)
                : type(std::move(type)), id(std::move(id)), templateType(std::move(templateType)),
                  loc(std::move(loc)) {}

//        // 形如：A<int> a = b;
//        VariableDeclaration(std::shared_ptr<Type> type, std::shared_ptr<Identifier> id,
//                            std::shared_ptr<Expression> assignmentExpr, std::shared_ptr<Type> templateType, YYLTYPE loc)
//                : type(std::move(type)), id(std::move(id)), assignmentExpr(std::move(assignmentExpr)),
//                  templateType(std::move(templateType)), loc(std::move(loc)) {}

        YYLTYPE getLocation() { return loc; }
        virtual Element eval() override;

    private:
        std::shared_ptr<Type> type;
        std::shared_ptr<Identifier> id;
        std::shared_ptr<Expression> assignmentExpr = nullptr;
        std::shared_ptr<Type> templateType = nullptr;
        YYLTYPE loc;
    };

    class VariableDeclarationAssign : public Expression {
    public:
        VariableDeclarationAssign(std::shared_ptr<Type> type, std::shared_ptr<Identifier> id, std::shared_ptr<Type> templateType,
                                  YYLTYPE loc)
                                  : type(std::move(type))
                                  , id(std::move(id))
                                  , templateType(std::move(templateType))
                                  , loc(std::move(loc)) {}
        virtual Element eval() override;

    protected:
        std::shared_ptr<Type> type;
        std::shared_ptr<Identifier> id;
        std::shared_ptr<Type> templateType = nullptr;
        YYLTYPE loc;
    };

    class VarDeclByExpr : public VariableDeclarationAssign {
    public:
        // 形如：int a = exp;
        VarDeclByExpr(std::shared_ptr<Type> type, std::shared_ptr<Identifier> id,
                      std::shared_ptr<Expression> assignmentExpr, YYLTYPE loc)
                : VariableDeclarationAssign(std::move(type), std::move(id), nullptr, std::move(loc))
                , assignmentExpr(std::move(assignmentExpr)) {}
        // 形如：A<int> a = b;
        VarDeclByExpr(std::shared_ptr<Type> type, std::shared_ptr<Type> templateType, std::shared_ptr<Identifier> id,
                      std::shared_ptr<Expression> assignmentExpr, YYLTYPE loc)
                : VariableDeclarationAssign(std::move(type), std::move(id), std::move(templateType), std::move(loc))
                , assignmentExpr(std::move(assignmentExpr)) {}
        virtual Element eval() override;

    private:
        std::shared_ptr<Expression> assignmentExpr = nullptr;
    };

    class ObjectDeclaration : public VariableDeclarationAssign {
    public:
        ObjectDeclaration(std::shared_ptr<Type> type, std::shared_ptr<Type> templateType, std::shared_ptr<Identifier> id,
                          std::shared_ptr<ExpressionList> expressionList, YYLTYPE loc)
                     : VariableDeclarationAssign(std::move(type), std::move(id), std::move(templateType), std::move(loc))
                     , expressionList(std::move(expressionList)) {}
        virtual Element eval() override;

    private:
        std::shared_ptr<ExpressionList> expressionList;
    };

    class VarDeclAssignStmt : public CommonStatement {
    public:
        explicit VarDeclAssignStmt(std::shared_ptr<Expression> variableDeclarationAssign)
        : variableDeclarationAssign(std::move(variableDeclarationAssign)) {}
        virtual Element eval() override;

        // explicit VarDeclAssignStmt(std::shared_ptr<VariableDeclarationAssign> variableDeclarationAssign)
        // : variableDeclarationAssign(std::move(variableDeclarationAssign)) {}
    private:
        std::shared_ptr<Expression> variableDeclarationAssign;
    };
}



#endif //MYPL_VARIABLEDECLARATION_H
