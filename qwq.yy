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
    qwq::VariableDeclarationAssign *varDeclAssign;
    qwq::ArithmeticExpression *arithExpr;
    qwq::LogicalExpression *logicalExpr;

    qwq::VariableList *varList;
    qwq::StatementList *stmtList;
    qwq::ExpressionList *exprList;
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

// 定义非终结符
// TODO: 定义非终结符的类型
%type <astNode> program
%type <cDeclare> class-decl
%type <classHead> class-head
%type <cStatement> common-stmt if-stmt while-stmt jump-stmt for-stmt return-stmt expr-stmt var-decl-stmt
%type <forStatement> c-like-for py-like-for range-for
%type <expr> expr assign-expr func-expr relation-expr slice-expr  arr-access
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
%type <varDeclAssign> var-decl var-decl-assign

%type <arithExpr> arithmetic-expr
%type <logicalExpr> logical-expr
// 列表
%type <varList> fp-list
%type <stmtList> stmt-list
%type <exprList> ap-list
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
%%
// TODO: 完成语法
//程序
program : program stmt { $1 = $2; }
        | stmt { $$ = $1;}
        ;

//语句
stmt  : func-decl { $$ = $1; }
      | class-decl { $$ = $1; }
      | common-stmt { $$ = $1; }
      ;

type  : val-type { $$ = $1; }
      | ident { $$ = $1; } //只能是class类型的
      ;

//基本类型
val-type  : TBOOLTK { $$ = new BooleanType(TBOOLTK); }
          | TINTTK { $$ = new IntType(TINTTK); }
          | TDOUBLETK { $$ = new DoubleType(TDOUBLETK); }
          | TCHARTK { $$ = new CharType(TCHARTK); }
          | TSTRTK { $$ = new StringType(TSTRTK); }
          | TARRTK '<' type ',' TINTEGER'>' { $$ = new ArrayType(TARRTK, $3, $5); }
          ;

//模板
//template  : TTEMP '<' TTYNAME ident '>'
//          ;
//以下是statement的4部分
//函数声明
func-decl : func-head block { $$ = new FunctionDeclaration(std::shared_ptr<FunctionHead>($1), 
                                                            std::shared_ptr<Block>($2)); }
          ;

func-head : TDEF ident '(' fp-list ')' { $$ = new FunctionHead(std::shared_ptr<Identifier>($2), std::shared_ptr<VariableList>($4), nullptr); }
          | TTEMP '<' TTYNAME ident '>' TDEF ident '(' fp-list ')' { $$ = new FunctionHead(std::shared_ptr<Identifier>($7), std::shared_ptr<VariableList>($9), nullptr, std::shared_ptr<Identifier>($4)); }
          | TDEF ident '(' fp-list ')' TARROW type { $$ = new FunctionHead(std::shared_ptr<Identifier>($2), std::shared_ptr<VariableList>($4), std::shared_ptr<Type>($7)); }
          | TTEMP '<' TTYNAME ident '>' TDEF ident '(' fp-list ')' TARROW type { $$ = new FunctionHead(std::shared_ptr<Identifier>($7), std::shared_ptr<VariableList>($9), std::shared_ptr<Type>($12), std::shared_ptr<Identifier>($4)); }
          ; //bug?

fp-list : %empty { $$ = new VariableList(); }
        | var-decl { $$ = new VariableList(); $$->push_back(std::shared_ptr<VariableDeclaration>($1)); }
        | fp-list ',' var-decl { $1->push_back(std::shared_ptr<VariableDeclaration>($3)); }
        ;

stmt-list : %empty { $$ = new StatementList(); }
          | common-stmt { $$ = new StatementList(); $$->push_back(std::shared_ptr<CommonStatement>($1)); }
          | stmt-list common-stmt { $1->push_back(std::shared_ptr<CommonStatement>($2)); }
          ; //这里可能有bug，书上写了

block : '{' stmt-list '}' { $$ = new Block(std::shared_ptr<StatementList>($2)); } // $1 改为 $2
      ;

//类声明
class-decl  : class-head block { $$ = new ClassDeclaration(std::shared_ptr<ClassHead>($1), std::shared_ptr<Block>($2)); }
            ; //应该只有var和func的声明

class-head  : TCLASS ident { $$ = new ClassHead(std::shared_ptr<Identifier>($2), nullptr, nullptr); }
            | TTEMP '<' TTYNAME ident '>' TCLASS ident { $$ = new ClassHead(std::shared_ptr<Identifier>($7), std::shared_ptr<Identifier>($4), nullptr); }
            | TCLASS ident TEXTEND ident { $$ = new ClassHead(std::shared_ptr<Identifier>($2), nullptr, std::shared_ptr<Identifier>($4)); }
            | TTEMP '<' TTYNAME ident '>' TCLASS ident TEXTEND ident { $$ = new ClassHead(std::shared_ptr<Identifier>($7), std::shared_ptr<Identifier>($4), std::shared_ptr<Identifier>($9)); }
            ; //有点复杂，bug?

//变量声明
var-decl  : type '<' type '>' ident { $$ = new VariableDeclaration(std::shared_ptr<Type>($1), std::shared_ptr<Type>($3), std::shared_ptr<Identifier>($5), @$); }
          | type ident { $$ = new VariableDeclaration(std::shared_ptr<Type>($1), std::shared_ptr<Type>($2)); }
          ;

var-decl-assign : type ident '=' expr { $$ = new VarDeclByExpr(std::shared_ptr<Type>($1), std::shared_ptr<Identifier>($2), std::shared_ptr<Expression>($4), @$); }
                | type '<' type '>' ident '=' expr { $$ = new VarDeclByExpr(std::shared_ptr<Type>($1), std::shared_ptr<Type>($3), std::shared_ptr<Identifier>($5), std::shared_ptr<Expression>($7), @$); }
                | type ident '(' ap-list ')' { $$ = new ObjectDeclaration(std::shared_ptr<Type>($1), nullptr, std::shared_ptr<Identifier>($2), std::shared_ptr<VariableList>($4), @$); }
                | type '<' type '>' ident '(' ap-list ')' { $$ = new ObjectDeclaration(std::shared_ptr<Type>($1), std::shared_ptr<Type>($3), std::shared_ptr<Identifier>($5), std::shared_ptr<VariableList>($7), @$); }
                ;

var-decl-stmt : var-decl ';' { $$ = new VarDeclAssignStmt($1); }
              | var-decl-assign ';' { $$ = new VarDeclAssignStmt($1); }
              ;

//普通语句
common-stmt : if-stmt { $$ = $1; }
            | while-stmt { $$ = $1; }
            | for-stmt { $$ = $1; }
            | var-decl-stmt { $$ = $1; }
            | return-stmt { $$ = $1; }
            | expr-stmt { $$ = $1; }
            | jump-stmt { $$ = $1; }
            ;
//以下是普通语句
//if语句
if-stmt : TIF '(' relation-expr ')' block { $$ = new IfStatement(std::shared_ptr<RelationalExpression>($3), std::shared_ptr<Block>($5)); }
        | TIF '(' relation-expr ')' block TELSE block { $$ = new IfStatement(std::shared_ptr<RelationalExpression>($3), std::shared_ptr<Block>($5), std::shared_ptr<Block>($7)); }
        ; 

//while语句
while-stmt  : TWHILE '(' relation-expr ')' block { $$ = new WhileStatement(std::shared_ptr<RelationalExpression>($3), 
                                                      std::shared_ptr<Block>($5)); }
            ;

//jump语句
jump-stmt : TBREAK ';' { $$ = new JumpStatement(TBREAK, @$); }
          | TCONTINUE ';' { $$ = new JumpStatement(TCONTINUE, @$); }
          ;

// TODO:for循环
// for 语句
for-stmt  : c-like-for  { $$ = $1; }
          | py-like-for { $$ = $1; }
          | range-for { $$ = $1; }
          ;
c-like-for  : TFOR '(' var-decl ';' relation-expr ';' assign-expr ')' block { $$ = new CLikeForStatement(std::shared_ptr<VariableDeclaration>($3), 
                  std::shared_ptr<RelationalExpression>($5), std::shared_ptr<AssignExpression>($7), 
                  std::shared_ptr<Block>($9));;}
            | TFOR '(' assign-expr ';' relation-expr ';' assign-expr ')' block { $$ = new CLikeForStatement(std::shared_ptr<AssignExpression>($3), 
                  std::shared_ptr<RelationalExpression>($5), std::shared_ptr<AssignExpression>($7), 
                  std::shared_ptr<Block>($9));;}
            ;

py-like-for : TFOR ident TIN '(' expr ',' expr ')' block { $$ = new PyLikeForStatement(std::shared_ptr<Identifier>($2), 
              std::shared_ptr<Expression>($5), std::shared_ptr<Expression>($7), std::shared_ptr<Block>($9)); }
            ;

range-for : TFOR '(' var-decl TIN ident ')' block { $$ = new RangeForStatement(std::shared_ptr<VariableDeclaration>($3), 
                                                    std::shared_ptr<Identifier>($5), std::shared_ptr<Block>($7)); }
            ;

//返回语句
return-stmt : TRETURN ';' { $$ = new ReturnStatement(@$); }
            | TRETURN expr-stmt ';' { $$ = new ReturnStatement(std::shared_ptr<Expression>(@1), @$); }
            ;

//表达式
expr  : logical-expr { $$ = $1; }
      | arithmetic-expr { $$ = $1; }
      | str-expr { $$ = $1; }
      | slice-expr { $$ = $1; }
      | assign-expr { $$ = $1; }
      ;

//表达式语句
expr-stmt : expr ';' { $$ = new ExpressionStatement(std::shared_ptr<Expression>($1), @$); }
          ;

//赋值表达式
assign-expr : ident '=' expr { $$ = new AssignmentExpression(std::shared_ptr<Identifier>($1), std::shared_ptr<Expression>($3), @$); }
            | arr-access '=' expr { $$ = new AssignmentExpression(std::shared_ptr<ArrayAccess>($1), std::shared_ptr<Expression>($3), @$); }
            ;

//函数表达式
func-expr : ident '(' ap-list ')' { $$ = new FunctionCall(std::shared_ptr<Identifier>($1), std::shared_ptr<ExpressionList>($3), @$); }
          | ident '.' ident '(' ap-list ')' { $$ = new FunctionCall(std::shared_ptr<Identifier>($1), std::shared_ptr<Identifier>($3), std::shared_ptr<ExpressionList>($5), @$); }
          ;

ap-list : %empty { $$ = new ExpressionList(); }
        | expr { $$ = new ExpressionList(); $$->push_back(std::shared_ptr<Expression>($1)); }
        | ap-list expr { $1->push_back(std::shared_ptr<Expression>($2)); }
        ;

//字符串表达式
str-expr  : TSTRING { $$ = new StringLiteral(std::string($1)); }
          | ident { $$ = new StringIdentifier(std::shared_ptr<Identifier>($1)); }
          | str-operation { $$ = $1; }
          | func-expr { $$ = new StringFuncExpression(std::shared_ptr<FunctionCall>($1)); }
          ;

str-operation : str-expr TADD str-expr { $$ = new StringOperation(std::shared_ptr<StringExpression>($1), $2, std::shared_ptr<StringExpression>($3)); }
              | str-expr '.' TSUBS '(' expr ',' expr ')' { $$ = new StringOperation(std::shared_ptr<StringExpression>($1), $3, std::shared_ptr<Expression>($5), std::shared_ptr<Expression>($7)); }
              | str-expr '.' TREVS { $$ = new StringOperation(std::shared_ptr<StringExpression>($1), $3); }
              | str-expr '.' TTITLES { $$ = new StringOperation(std::shared_ptr<StringExpression>($1), $3); }
              | str-expr '.' TUPS { $$ = new StringOperation(std::shared_ptr<StringExpression>($1), $3); }
              | str-expr '.' TLOWS { $$ = new StringOperation(std::shared_ptr<StringExpression>($1), $3); }
              ;

//切片表达式
slice-expr  : ident '[' expr ':' expr ']' { $$ = new SliceExpression(std::shared_ptr<Identifier>($1), 
                                            std::shared_ptr<Expression>($3), std::shared_ptr<Expression>($5), @$); }
            ;

//算术表达式
arithmetic-expr : item { $$ = new ArithmeticExpression(std::shared_ptr<Item>($1), @$); }
                | arithmetic-expr addition-opt item { $$ = new ArithmeticExpression(std::shared_ptr<ArithmeticExpression>($1), std::shared_ptr<Item>($3), $2, @$); }
                ;

addition-opt  : TADD 
              | TSUB
              ;

//逻辑表达式
logical-expr  : factor { $$ = new LogicalExpression(std::shared_ptr<Factor>($1), @$); }
              | logical-expr logical-opt factor { $$ = new LogicalExpression(std::shared_ptr<LogicalExpression>($1), std::shared_ptr<Factor>($3), $2, @$); }
              ;

logical-opt : TAND
            | TOR
            ;

//关系表达式
relation-expr : arithmetic-expr relation-opt arithmetic-expr { $$ = new RelationalExpression(std::shared_ptr<ArithmeticExpression>($1),
                                      std::shared_ptr<ArithmeticExpression>($3), $2, @$); }
              ;

relation-opt  : TGT
              | TGE
              | TLT
              | TLE
              | TEQ
              | TNE
              ;

//项
item  : factor { $$ = new Item(std::shared_ptr<Factor>($1)); }
      | item multi-opt factor  { $$ = new Item(std::shared_ptr<Item>($1), 
                                  std::shared_ptr<Factor>($3), $2); }
      ;

multi-opt : TMUL
          | TDIV
          | TMOD
          | TPOWER
          | TEDIV
          ;

//因子
factor  : ident { $$ = new Factor(std::shared_ptr<Expression>($1)); }
        | arr-access { $$ = new Factor(std::shared_ptr<Expression>($1)); }
        | '(' expr ')' { $$ = new Factor(std::shared_ptr<Expression>($2)); }
        | literal { $$ = new Factor(std::shared_ptr<Expression>($1)); }
        | func-expr { $$ = new Factor(std::shared_ptr<Expression>($1)); }
        | relation-expr { $$ = new Factor(std::shared_ptr<Expression>($1)); }
        ;

//数组访问
arr-access  : ident '[' expr ']' { $$ = new ArrayAccess(std::shared_ptr<Identifier>($1), std::shared_ptr<Expression>($3), @$); }
            | arr-access '[' expr ']' { $$ = new ArrayAccess(std::shared_ptr<ArrayAccess>($1), std::shared_ptr<Expression>($3), @$); }
            ;



//标识符
ident : TIDENTIFIER { $$ = new Identifier(*$1, @1); }
      ;

//字面值
literal : TCHAR { $$ = new Character($1); }
        | TBOOL { $$ = new Boolean($1); }
        | TINTEGER { $$ = new Integer($1); }
        | TREAL { $$ = new Real($1); }
        ;
%%