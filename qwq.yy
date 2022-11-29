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
%token <token>      TFOR TWHILE TIN
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
program : program stmt
        | stmt
        ;

//语句
stmt  : func-decl
      | class-decl
      | common-stmt
      ;

type  : val-type
      | ident //只能是class类型的
      ;

//模板
//template  : TTEMP '<' TTYNAME ident '>'
//          ;
//以下是statement的4部分
//函数声明
func-decl : func-head block
          ;

func-head : TDEF ident '(' fp-list ')'
          | TTEMP '<' TTYNAME ident '>' TDEF ident '(' fp-list ')'
          ; //bug?

fp-list : %empty
        | var-decl
        | fp-list ',' var-decl
        ;

stmt-list : %empty
          | common-stmt
          | stmt-list common-stmt
          ; //这里可能有bug，书上写了

block : '{' stmt-list '}'
      ;

//类声明
class-decl  : class-head block
            ; //应该只有var和func的声明

class-head  : TCLASS ident 
            | TTEMP '<' TTYNAME ident '>' TCLASS ident
            | TCLASS ident TEXTEND ident
            | TTEMP '<' TTYNAME ident '>' TCLASS ident TEXTEND ident
            ; //有点复杂，bug?

//变量声明
var-decl  : type '<' type '>' ident
          | type ident
          ;

var-decl-assign : type ident '=' expr
                | type '<' type '>' ident '=' expr
                | type ident '(' ap-list ')'
                | type '<' type '>' ident '(' ap-list ')'
                ;

var-decl-stmt : var-decl ';'
              | var-decl-assign ';'
              ;

//普通语句
common-stmt : if-stmt
            | while-stmt
            | for-stmt
            | var-decl-stmt
            | return-stmt
            | expr-stmt
            | jump-stmt
            ;
//以下是普通语句
//if语句
if-stmt : TIF '(' relation-expr ')' block
        | TIF '(' relation-expr ')' block TELSE '(' relation-expr ')' block
        ; 

//while语句
while-stmt  : TWHILE '(' relation-expr ')' block
            ;

//jump语句
jump-stmt : TBREAK ';'
          | TCONTINUE ';'
          ;

// TODO:for循环
// for 语句
for-stmt  : c-like-for 
          | py-like-for
          | range-for
          ;
c-like-for  : TFOR '(' var-decl ';' relation-expr ';' assign-expr ')' block
            | TFOR '(' assign-expr ';' relation-expr ';' assign-expr ')' block
            ;

py-like-for : TFOR ident TIN '(' expr ',' expr ')' block
            ;

range-for : TFOR '(' var-decl TIN ident ')' block
            ;

//返回语句
return-stmt : TRETURN ';'
            | TRETURN expr-stmt ';'
            ;

//表达式
expr  : logical-expr
      | arithmetic-expr
      | str-expr
      | slice-expr
      | assign-expr
      ;

//表达式语句
expr-stmt : expr ';'
          ;

//赋值表达式
assign-expr : ident '=' expr
            | arr-access '=' expr
            ;

//函数表达式
func-expr : ident '.' ident '(' ap-list ')'
          ;

ap-list : %empty
        | expr
        | ap-list expr
        ;

//字符串表达式
str-expr  : TSTRING
          | ident
          | str-operation
          | func-expr
          ;

str-operation : str-expr TADD str-expr
              | str-expr '.' TSUBS '(' expr ',' expr ')'
              | str-expr '.' TREVS
              | str-expr '.' TTITLES
              | str-expr '.' TUPS
              | str-expr '.' TLOWS
              ;

//切片表达式
slice-expr  : ident '[' expr ':' expr ']'
            ;

//算术表达式
arithmetic-expr : item
                | arithmetic-expr addition-opt item
                ;

addition-opt  : TADD
              | TSUB
              ;

//逻辑表达式
logical-expr  : factor
              | logical-expr logical-opt factor
              ;

logical-opt : TAND
            | TOR
            ;

//关系表达式
relation-expr : arithmetic-expr relation-opt arithmetic-expr
              ;

relation-opt  : TGT
              | TGE
              | TLT
              | TLE
              | TEQ
              | TNE
              ;

//项
item  : factor
      | item multi-opt factor
      ;

multi-opt : TMUL
          | TDIV
          | TMOD
          | TPOWER
          | TEDIV
          ;

//因子
factor  : ident
        | arr-access
        | '(' expr ')'
        | literal
        | func-expr
        | relation-expr
        ;

//数组访问
arr-access  : ident '[' expr ']'
            | arr-access '[' expr ']'
            ;

//基本类型
val-type  : TBOOLTK
          | TINTTK
          | TDOUBLETK
          | TCHARTK
          | TSTRTK
          | TARRTK
          ;

//标识符
ident : TIDENTIFIER
      ;

//字面值
literal : TCHAR
        | TBOOL
        | TINTEGER
        | TREAL
        ;
%%