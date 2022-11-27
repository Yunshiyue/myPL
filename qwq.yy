${
    #include "AstNode.h"
    #include "ClassDeclaration.h"
    #include "CommonStatement.h"
    #include "Expression.h"
    #include "FunctionDeclaration.h"
    #include "Literal.h"
    #include "Statement.h"
    #include "StringExpression.h"
    #include "Type.h"

    #include <stdio.h>
    #include <string>

    extern int yylex();
    int yyerror(char const * s);

%}

// 定义yylval的类型，即我们能获取yylval的方式
%union {
    // TODO: 根据定义的节点class完善union
    long long integer;
    double real;
    int boolean;
    char character;
    std::string *string; // 如果是string就是字符串的内容，如果是identifier就是标识符的名字
    int token;
}

// 定义终结符
%token <integer>    TINTEGER
%token <real>       TREAL
%token <boolean>    TBOOL
%token <character>  TCHAR
%token <string>     TSTRING TIDENTIFIER
// 算数运算符
%token <token>      TPOWER TEDIV TSADD TSSUB TADD TSUB TMUL TDIV TMOD
// 逻辑运算符
%token <token>      TAND TOR TNOT
// 比较运算符
%token <token>      TEQ TNE TGE TLE TGT TLT
// 关键字
// 条件语句
%token <token>      TIF TELSE TELIF
// 循环语句
%token <token>      TFOR TWHILE
// 类
%token <token>      TTHIS TPUBLIC TPRIVATE TPROTECTED TEXTEND TCLASS
// 函数
%token <token>      TDEF TRETURN
// 跳出语句
%token <token>      TCONTINUE TBREAK
// 声明语句
%token <token>      TINTTK TBOOLTK TDOUBLETK TCHARTK TSTRTK TARRTK
// 模板
%token <token>      TTEMP TTYNAME
// 字符串操作
%token <token>      TSUBS TREVS TTITLES TUPS TLOWS

// 定义非终结符
// TODO: 定义非终结符的类型
// 定义优先级以及结合性
%right '='
%left TAND TOR
%nonassoc TNOT
%left TADD TSUB
%left TMUL TDIV TEDIV TMOD
%left TPOWER
%nonassoc TSADD TSSUB
// 定义开始的非终结符
%start program

%%
// TODO: 完成语法
%%