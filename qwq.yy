%code requires {

# define YYLTYPE_IS_DECLARED 1 /* alert the parser that we have our own definition */

}

%{
    #include "AstNode.h"
    #include "ClassDeclaration.h"
    #include "CommonStatement.h"
    #include "Expression.h"
    #include "FunctionDeclaration.h"
    #include "Literal.h"
    #include "Statement.h"
    #include "StringExpression.h"
    #include "Type.h"
    #include "VariableDeclaration.h"
    #include "ProgramBlock.h"
    #include <stdio.h>
    #include <string>

    qwq::ProgramBlock* programBlock;
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
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)

%}

// 定义yylval的类型，即我们能获取yylval的方式
%union {
    // TODO: 根据定义的节点class完善union
    qwq::AstNode *astNode;
    qwq::ClassDeclaration *cDeclare;
    qwq::ClassHead *classHead;
    qwq::CommonStatement *cStatement;
    qwq::ForStatement *forStatement;
    qwq::Expression *expr;
    qwq::ArrayAccess *arrAcc;
    qwq::RelationalExpression *relationExpr;
    qwq::SliceExpression *sliceExpr;
    qwq::FunctionCall *funcExpr;
    qwq::AssignExpression *assignExpr;
    qwq::FunctionDeclaration *fDeclare;
    qwq::FunctionHead *fHead;
    qwq::Literal *literal;
    qwq::Statement *stmt;
    qwq::StringExpression *sExpr;
    qwq::Block *block;
    qwq::Type *type;
    qwq::Identifier *ident;
    qwq::Item *item;
    qwq::Factor *factor;
    qwq::VariableDeclaration* varDecl;
    qwq::VariableDeclarationAssign *varDeclAssign;
    qwq::ArithmeticExpression *arithExpr;
    qwq::LogicalExpression *logicalExpr;
    qwq::VariableList *varList;
    qwq::StatementList *stmtList;
    qwq::ExpressionList *exprList;
    qwq::ProgramBlock *allStmts;
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
// 其它运算符
%token <token>      TARROW
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

%token <token>      PRINT

// 定义非终结符
// TODO: 定义非终结符的类型
%type <astNode> program
%type <cDeclare> class-decl
%type <classHead> class-head
%type <cStatement> common-stmt if-stmt while-stmt jump-stmt for-stmt return-stmt expr-stmt var-decl-stmt print-stmt
%type <forStatement> c-like-for py-like-for range-for
%type <expr> expr

%type <arrAcc> arr-access
%type <relationExpr> relation-expr 
%type <sliceExpr> slice-expr
%type <funcExpr> func-expr
%type <assignExpr> assign-expr

%type <fDeclare> func-decl
%type <fHead> func-head
%type <literal> literal
%type <stmt> stmt 
%type <sExpr> str-expr str-operation
%type <block> block
%type <type> type val-type
%type <ident> ident
%type <item> item
%type <factor> factor
%type <varDecl> var-decl
%type <varDeclAssign> var-decl-assign

%type <arithExpr> arithmetic-expr
%type <logicalExpr> logical-expr
// 列表
%type <varList> fp-list
%type <stmtList> stmt-list
%type <exprList> ap-list
%type <allStmts> all-stmt-list
// 操作符
%type <token> addition-opt
%type <token> multi-opt
%type <token> relation-opt
%type <token> logical-opt
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
%locations
%%
// TODO: 完成语法
//程序
/*
program : program stmt { $1 = $2; }
        | stmt { $$ = $1;}
        ;*/

program : %empty { $$ = new qwq::ProgramBlock(); }
        | all-stmt-list { programBlock = $1; }
        ;

all-stmt-list : stmt { $$ = new qwq::ProgramBlock(); $$->stmts->push_back(std::shared_ptr<qwq::Statement>($1)); }
              | all-stmt-list stmt { $1->stmts->push_back(std::shared_ptr<qwq::Statement>($2));  $$ = $1; }
              ;

//语句
stmt  : func-decl { $$ = $1; }
      | class-decl { $$ = $1; }
      | common-stmt { $$ = $1; }
      ;

type  : val-type { $$ = $1; }
      /* | ident { $$ = new qwq::ClassType(TCLASS, std::shared_ptr<qwq::Identifier>($1)); } //只能是class类型的 */
      ;

//基本类型
val-type  : TBOOLTK { $$ = new qwq::BooleanType(TBOOLTK); }
          | TINTTK { $$ = new qwq::IntType(TINTTK); }
          | TDOUBLETK { $$ = new qwq::DoubleType(TDOUBLETK); }
          | TCHARTK { $$ = new qwq::CharType(TCHARTK); }
          | TSTRTK { $$ = new qwq::StringType(TSTRTK); }
          | TARRTK '<' type ',' TINTEGER'>' { $$ = new qwq::ArrayType(TARRTK, std::shared_ptr<qwq::Type>$3, $5); }
          ;

//模板
//template  : TTEMP '<' TTYNAME ident '>'
//          ;
//以下是statement的4部分
//函数声明
func-decl : func-head block { $$ = new qwq::FunctionDeclaration(std::shared_ptr<qwq::FunctionHead>($1), 
                                                                std::shared_ptr<qwq::Block>($2)); }
          ;

func-head : TDEF ident '(' fp-list ')' { $$ = new qwq::FunctionHead(nullptr, std::shared_ptr<qwq::Identifier>($2), std::shared_ptr<qwq::VariableList>($4), nullptr); }
          | TTEMP '<' TTYNAME type '>' TDEF ident '(' fp-list ')' { $$ = new qwq::FunctionHead(std::shared_ptr<qwq::Type>($4), std::shared_ptr<qwq::Identifier>($7), std::shared_ptr<qwq::VariableList>($9), nullptr); }
          | TDEF ident '(' fp-list ')' TARROW type { $$ = new qwq::FunctionHead(nullptr, std::shared_ptr<qwq::Identifier>($2), std::shared_ptr<qwq::VariableList>($4), std::shared_ptr<qwq::Type>($7)); }
          | TTEMP '<' TTYNAME type '>' TDEF ident '(' fp-list ')' TARROW type { $$ = new qwq::FunctionHead(std::shared_ptr<qwq::Type>($4), std::shared_ptr<qwq::Identifier>($7), std::shared_ptr<qwq::VariableList>($9), std::shared_ptr<qwq::Type>($12)); }
          ; //bug?

fp-list : %empty { $$ = new qwq::VariableList(); }
        | var-decl { $$ = new qwq::VariableList(); $$->push_back(std::shared_ptr<qwq::VariableDeclaration>($1)); }
        | fp-list ',' var-decl { $1->push_back(std::shared_ptr<qwq::VariableDeclaration>($3)); }
        ;

stmt-list : %empty { $$ = new qwq::StatementList(); }
          | common-stmt { $$ = new qwq::StatementList(); $$->push_back(std::shared_ptr<qwq::CommonStatement>($1)); }
          | stmt-list ',' common-stmt { $1->push_back(std::shared_ptr<qwq::CommonStatement>($3)); $$ = $1; }
          ; //这里可能有bug，书上写了

block : '{' stmt-list '}' { $$ = new qwq::Block(std::shared_ptr<qwq::StatementList>($2)); } // $1 改为 $2
      ;

//类声明
class-decl  : class-head block { $$ = new qwq::ClassDeclaration(std::shared_ptr<qwq::ClassHead>($1), std::shared_ptr<qwq::Block>($2)); }
            ; //应该只有var和func的声明

class-head  : TCLASS ident { $$ = new qwq::ClassHead(std::shared_ptr<qwq::Identifier>($2), nullptr, nullptr); }
            | TTEMP '<' TTYNAME ident '>' TCLASS ident { $$ = new qwq::ClassHead(std::shared_ptr<qwq::Identifier>($7), std::shared_ptr<qwq::Identifier>($4), nullptr); }
            | TCLASS ident TEXTEND ident { $$ = new qwq::ClassHead(std::shared_ptr<qwq::Identifier>($2), nullptr, std::shared_ptr<qwq::Identifier>($4)); }
            | TTEMP '<' TTYNAME ident '>' TCLASS ident TEXTEND ident { $$ = new qwq::ClassHead(std::shared_ptr<qwq::Identifier>($7), std::shared_ptr<qwq::Identifier>($4), std::shared_ptr<qwq::Identifier>($9)); }
            ; //有点复杂，bug?

//变量声明
var-decl  : type '<' type '>' ident { $$ = new qwq::VariableDeclaration(std::shared_ptr<qwq::Type>($1), std::shared_ptr<qwq::Type>($3), std::shared_ptr<qwq::Identifier>($5), @$); }
          | type ident { $$ = new qwq::VariableDeclaration(std::shared_ptr<qwq::Type>($1), std::shared_ptr<qwq::Identifier>($2), @$); }
          ;

var-decl-assign : type ident '=' expr { $$ = new qwq::VarDeclByExpr(std::shared_ptr<qwq::Type>($1), std::shared_ptr<qwq::Identifier>($2), std::shared_ptr<qwq::Expression>($4), @$); }
                | type '<' type '>' ident '=' expr { $$ = new qwq::VarDeclByExpr(std::shared_ptr<qwq::Type>($1), std::shared_ptr<qwq::Type>($3), std::shared_ptr<qwq::Identifier>($5), std::shared_ptr<qwq::Expression>($7), @$); }
                | type ident '(' ap-list ')' { $$ = new qwq::ObjectDeclaration(std::shared_ptr<qwq::Type>($1), nullptr, std::shared_ptr<qwq::Identifier>($2), std::shared_ptr<qwq::ExpressionList>($4), @$); }
                | type '<' type '>' ident '(' ap-list ')' { $$ = new qwq::ObjectDeclaration(std::shared_ptr<qwq::Type>($1), std::shared_ptr<qwq::Type>($3), std::shared_ptr<qwq::Identifier>($5), std::shared_ptr<qwq::ExpressionList>($7), @$); }
                ;

var-decl-stmt : var-decl ';' { $$ = new qwq::VarDeclAssignStmt(std::shared_ptr<qwq::VariableDeclaration>($1)); }
              | var-decl-assign ';' { $$ = new qwq::VarDeclAssignStmt(std::shared_ptr<qwq::VariableDeclarationAssign>($1)); }
              ;

//普通语句
common-stmt : if-stmt { $$ = $1; }
            | while-stmt { $$ = $1; }
            | for-stmt { $$ = $1; }
            | var-decl-stmt { $$ = $1; }
            | return-stmt { $$ = $1; }
            | expr-stmt { $$ = $1; }
            | jump-stmt { $$ = $1; }
            | print-stmt { $$ = $1; }
            ;
//以下是普通语句
//if语句
if-stmt : TIF '(' relation-expr ')' block { $$ = new qwq::IfStatement(std::shared_ptr<qwq::RelationalExpression>($3), std::shared_ptr<qwq::Block>($5)); }
        | TIF '(' relation-expr ')' block TELSE block { $$ = new qwq::IfStatement(std::shared_ptr<qwq::RelationalExpression>($3), std::shared_ptr<qwq::Block>($5), std::shared_ptr<qwq::Block>($7)); }
        ; 

//while语句
while-stmt  : TWHILE '(' relation-expr ')' block { $$ = new qwq::WhileStatement(std::shared_ptr<qwq::RelationalExpression>($3), 
                                                      std::shared_ptr<qwq::Block>($5)); }
            ;

//jump语句
jump-stmt : TBREAK ';' { $$ = new qwq::JumpStatement(TBREAK, @$); }
          | TCONTINUE ';' { $$ = new qwq::JumpStatement(TCONTINUE, @$); }
          ;

// TODO:for循环
// for 语句
for-stmt  : c-like-for  { $$ = $1; }
          | py-like-for { $$ = $1; }
          | range-for { $$ = $1; }
          ;
c-like-for  : TFOR '(' var-decl-assign ';' relation-expr ';' assign-expr ')' block { $$ = new qwq::CLikeForStatement(std::shared_ptr<qwq::VariableDeclarationAssign>($3), 
                  std::shared_ptr<qwq::RelationalExpression>($5), std::shared_ptr<qwq::AssignExpression>($7), 
                  std::shared_ptr<qwq::Block>($9));;}
            | TFOR '(' assign-expr ';' relation-expr ';' assign-expr ')' block { $$ = new qwq::CLikeForStatement(std::shared_ptr<qwq::AssignExpression>($3), 
                  std::shared_ptr<qwq::RelationalExpression>($5), std::shared_ptr<qwq::AssignExpression>($7), 
                  std::shared_ptr<qwq::Block>($9));;}
            ;

py-like-for : TFOR ident TIN '(' expr ',' expr ')' block { $$ = new qwq::PyLikeForStatement(std::shared_ptr<qwq::Identifier>($2), 
              std::shared_ptr<qwq::Expression>($5), std::shared_ptr<qwq::Expression>($7), std::shared_ptr<qwq::Block>($9)); }
            ;

range-for : TFOR '(' var-decl TIN ident ')' block { $$ = new qwq::RangeForStatement(std::shared_ptr<qwq::VariableDeclaration>($3), 
                                                    std::shared_ptr<qwq::Identifier>($5), std::shared_ptr<qwq::Block>($7)); }
            ;

//返回语句
return-stmt : TRETURN ';' { $$ = new qwq::ReturnStatement(@$); }
            | TRETURN expr ';' { $$ = new qwq::ReturnStatement(std::shared_ptr<qwq::Expression>($2), @$); }
            ;

//表达式
expr  : logical-expr { $$ = $1; }
      | arithmetic-expr { $$ = $1; }
      | str-expr { $$ = $1; }
      | slice-expr { $$ = $1; }
      | assign-expr { $$ = $1; }
      ;

//表达式语句
expr-stmt : expr ';' { $$ = new qwq::ExpressionStatement(std::shared_ptr<qwq::Expression>($1), @$); }
          ;

//赋值表达式
assign-expr : ident '=' expr { $$ = new qwq::AssignExpression(std::shared_ptr<qwq::Identifier>($1), std::shared_ptr<qwq::Expression>($3), @$); }
            | arr-access '=' expr { $$ = new qwq::AssignExpression(std::shared_ptr<qwq::ArrayAccess>($1), std::shared_ptr<qwq::Expression>($3), @$); }
            ;

//函数表达式
func-expr : ident '(' ap-list ')' { $$ = new qwq::FunctionCall(std::shared_ptr<qwq::Identifier>($1), std::shared_ptr<qwq::ExpressionList>($3), @$); }
          //| ident '.' ident '(' ap-list ')' { $$ = new qwq::FunctionCall(std::shared_ptr<qwq::Identifier>($1), std::shared_ptr<qwq::Identifier>($3), std::shared_ptr<qwq::ExpressionList>($5), @$); }
          ;

ap-list : %empty { $$ = new qwq::ExpressionList(); }
        | expr { $$ = new qwq::ExpressionList(); $$->push_back(std::shared_ptr<qwq::Expression>($1)); }
        | ap-list expr { $1->push_back(std::shared_ptr<qwq::Expression>($2)); }
        ;

//字符串表达式
str-expr  : TSTRING { $$ = new qwq::StringLiteral(std::string(*$1)); }
          | ident { $$ = new qwq::StringIdentifier(std::shared_ptr<qwq::Identifier>($1)); }
          | str-operation { $$ = $1; }
          /* | func-expr { $$ = new qwq::StringFuncExpression(std::shared_ptr<qwq::FunctionCall>($1)); } */
          ;

str-operation : str-expr TADD str-expr { $$ = new qwq::StringOperation(std::shared_ptr<qwq::StringExpression>($1), 1, std::shared_ptr<qwq::StringExpression>($3)); }
              | str-expr '.' TSUBS '(' expr ',' expr ')' { $$ = new qwq::StringOperation(std::shared_ptr<qwq::StringExpression>($1), 2, std::shared_ptr<qwq::Expression>($5), std::shared_ptr<qwq::Expression>($7)); }
              | str-expr '.' TREVS { $$ = new qwq::StringOperation(std::shared_ptr<qwq::StringExpression>($1), 3); }
              | str-expr '.' TTITLES { $$ = new qwq::StringOperation(std::shared_ptr<qwq::StringExpression>($1), 4); }
              | str-expr '.' TUPS { $$ = new qwq::StringOperation(std::shared_ptr<qwq::StringExpression>($1), 5); }
              | str-expr '.' TLOWS { $$ = new qwq::StringOperation(std::shared_ptr<qwq::StringExpression>($1), 6); }
              ;

//切片表达式
slice-expr  : ident '[' expr ':' expr ']' { $$ = new qwq::SliceExpression(std::shared_ptr<qwq::Identifier>($1), 
                                            std::shared_ptr<qwq::Expression>($3), std::shared_ptr<qwq::Expression>($5), @$); }
            ;

//算术表达式
arithmetic-expr : item { $$ = new qwq::ArithmeticExpression(std::shared_ptr<qwq::Item>($1), @$); }
                | arithmetic-expr addition-opt item { $$ = new qwq::ArithmeticExpression(std::shared_ptr<qwq::ArithmeticExpression>($1), std::shared_ptr<qwq::Item>($3), $2, @$); }
                ;

addition-opt  : TADD  { $$ = 1; }
              | TSUB { $$ = 2; }
              ;

//逻辑表达式
logical-expr  : factor { $$ = new qwq::LogicalExpression(std::shared_ptr<qwq::Factor>($1), @$); }
              | logical-expr logical-opt factor { $$ = new qwq::LogicalExpression(std::shared_ptr<qwq::LogicalExpression>($1), std::shared_ptr<qwq::Factor>($3), $2, @$); }
              ;

logical-opt : TAND { $$ = 1; }
            | TOR { $$ = 2; }
            ;

//关系表达式
relation-expr : arithmetic-expr relation-opt arithmetic-expr { $$ = new qwq::RelationalExpression(std::shared_ptr<qwq::ArithmeticExpression>($1),
                                      std::shared_ptr<qwq::ArithmeticExpression>($3), $2, @$); }
              ;

relation-opt  : TGT { $$ = 1; }
              | TGE { $$ = 2; }
              | TLT { $$ = 3; }
              | TLE { $$ = 4; }
              | TEQ { $$ = 5; }
              | TNE { $$ = 6; }
              ;

//项
item  : factor { $$ = new qwq::Item(std::shared_ptr<qwq::Factor>($1)); }
      | item multi-opt factor  { $$ = new qwq::Item(std::shared_ptr<qwq::Item>($1), 
                                  std::shared_ptr<qwq::Factor>($3), $2); }
      ;

multi-opt : TMUL { $$ = 1; }
          | TDIV { $$ = 2; }
          | TMOD { $$ = 3; }
          | TPOWER { $$ = 4; }
          | TEDIV { $$ = 5; }
          ;

//因子
factor  : ident { $$ = new qwq::Factor(std::shared_ptr<qwq::Expression>($1)); }
        | arr-access { $$ = new qwq::Factor(std::shared_ptr<qwq::Expression>($1)); }
        | '(' expr ')' { $$ = new qwq::Factor(std::shared_ptr<qwq::Expression>($2)); }
        | literal { $$ = new qwq::Factor(std::shared_ptr<qwq::Expression>($1)); }
        | func-expr { $$ = new qwq::Factor(std::shared_ptr<qwq::Expression>($1)); }
        | relation-expr { $$ = new qwq::Factor(std::shared_ptr<qwq::Expression>($1)); }
        ;

//数组访问
arr-access  : ident '[' expr ']' { $$ = new qwq::ArrayAccess(std::shared_ptr<qwq::Identifier>($1), std::shared_ptr<qwq::Expression>($3), @$); }
            | arr-access '[' expr ']' { $$ = new qwq::ArrayAccess(std::shared_ptr<qwq::ArrayAccess>($1), std::shared_ptr<qwq::Expression>($3), @$); }
            ;



//标识符
ident : TIDENTIFIER { $$ = new qwq::Identifier(*$1, @1); }
      ;

//字面值
literal : TCHAR { $$ = new qwq::Character($1); }
        | TBOOL { $$ = new qwq::Boolean($1); }
        | TINTEGER { $$ = new qwq::Integer($1); }
        | TREAL { $$ = new qwq::Real($1); }
        ;

print-stmt : PRINT '(' expr ')' ';' { $$ = new qwq::PrintStatement(std::shared_ptr<qwq::Expression>($3)); }
           ;
%%