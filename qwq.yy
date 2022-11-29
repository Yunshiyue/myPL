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
    #define YYERROR_VERBOSE
    #define YYDEBUG 1

    #define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
          (Current).file_name = fileNames.top();            \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
          (Current).file_name = fileNames.top();            \
        }                                                               \
    while (0)

%}

// 定义yylval的类型，即我们能获取yylval的方式
%union {
    // TODO: 根据定义的节点class完善union
    qwq::AstNode *astNode;
    qwq::ClassDeclaration *cDeclare;
    qwq::CommonStatement *cStatement;
    qwq::Expression *expr;
    qwq::FunctionDeclaration *fDeclare;
    qwq::Literal *literal;
    qwq::Statement *stmt;
    qwq::StringExpression *sExpr;
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
%debug
%%
// TODO: 完成语法
//程序
program : program stmt {}
        | stmt {}
        ;

//语句
stmt  : func-decl
      | var-decl
      | class-decl
      | common-stmt
      ;

type  : val-type
      | ident //只能是class类型的
      ;

ident : TIDENTIFIER
      ;

//模板
//template  : TTEMP '<' TTYNAME ident '>'
//          ;
//以下是statement的4部分
//函数声明
func-decl : func-head func-body
          ;

func-head : TDEF ident '(' fp-list ')'
          | TTEMP '<' TTYNAME ident '>' TDEF ident '(' fp-list ')'
          ; //bug?

func-body : '{' stmt-list '}'
          ;

fp-list : %empty
        | type ident
        | fp-list ',' type ident
        ;

stmt-list : %empty
          | stmt
          | stmt-list stmt
          ; //这里可能有bug，书上写了

//类声明
class-decl  : class-head class-body
            ;

class-head  : TCLASS ident 
            | TTEMP '<' TTYNAME ident '>' TCLASS ident
            | TCLASS ident TEXTEND ident
            | TTEMP '<' TTYNAME ident '>' TCLASS ident TEXTEND ident
            ; //有点复杂，bug?

class-body  : block
            ; //应该只有var和func的声明

//普通语句
common-stmt : if-stmt
            | while-stmt
            | for-stmt
            | var-decl
            | return-stmt
            | expr-stmt
            | jump-stmt
            ;

if-stmt : TIF '(' relation-stmt ')' block
        | TIF '(' relation-stmt ')' block TELIF '(' relation-stmt ')' block TELSE '(' relation-stmt ')' block
        | TIF '(' relation-stmt ')' block TELSE '(' relation-stmt ')' block
        ; // elif 后面必须跟else

while-stmt  : TWHILE '(' relation-stmt ')' block
            ;
jump-stmt : TBREAK ';'
          | TCONTINUE ';'
          ;

// TODO:for循环

return-stmt : TRETURN ';'
            : TRETURN expr-stmt ';'

%%