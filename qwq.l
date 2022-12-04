%{
    #include <string>
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
    #include "qwq_parser.hpp"
    //#include "qwq.hpp"

    // 保存identifier的具体名�?
    #define SAVE_IDENTIFIER yylval.string = new std::string(yytext, yyleng)
    // 保存整数具体的�?
    #define SAVE_INTEGER yylval.integer = std::stoll(std::string(yytext, yyleng))
    // 保存小数具体的�?
    #define SAVE_REAL yylval.real = std::stod(std::string(yytext, yyleng))
    // 保存bool变量具体的�?,不需要在此进行判�?
    //#define SAVE_BOOLEAN yylval.boolean = std::string(yytext, yyleng) == "true" ? true : false
    // 保存关键字对应的touken�?
    #define SAVE_TOKEN(t) (yylval.token = t)
    // 字符串以及字符的值的保存在状�?<STR>以及<CHARACTER>中已经实现了

    int yylcolumn = 1;

    std::string g_str;

%}

%option noyywrap yylineno

%x STR
%x CHARACTER

digit       [0-9]
integer     [+-]?{digit}+
real        [+-]?{digit}+\.{digit}+
letter      [a-zA-Z]
identifier  [{letter}_]?[{letter}{digit}_]+

%%

 /* 字符串以及字符（需要改进）*/
"\""        {
                g_str = "";
                BEGIN(STR);
            }
"'"         {
                g_str = "";
                BEGIN(CHARACTER);
            }
<STR>"\""   {
                BEGIN(INITIAL);
                yylval.string = new std::string(g_str);
                return TSTRING;
            }
<CHARACTER>"'"  {
                    BEGIN(INITIAL);
                    yylval.character = g_str[0];
                    return TCHAR;
                }
<STR>[^"]       {
                    g_str += std::string(yytext);
                }
<CHARACTER>[^'] {
                    g_str += std::string(yytext);
                }

 /* 关键�?(29个关键字)
    控制关键�? */
"if"            return SAVE_TOKEN(TIF);
"else"          return SAVE_TOKEN(TELSE);
"elif"          return SAVE_TOKEN(TELIF);
"for"           return SAVE_TOKEN(TFOR);
"while"         return SAVE_TOKEN(TWHILE);
"this"          return SAVE_TOKEN(TTHIS);
"public"        return SAVE_TOKEN(TPUBLIC);
"private"       return SAVE_TOKEN(TPRIVATE);
"protected"     return SAVE_TOKEN(TPROTECTED);
"extends"       return SAVE_TOKEN(TEXTEND);
"def"           return SAVE_TOKEN(TDEF);
"class"         return SAVE_TOKEN(TCLASS);
"return"        return SAVE_TOKEN(TRETURN);
"break"         return SAVE_TOKEN(TBREAK);
"continue"      return SAVE_TOKEN(TCONTINUE);
"in"            return SAVE_TOKEN(TIN);
 /* 类型关键�? */
"int"           return SAVE_TOKEN(TINTTK);
"bool"          return SAVE_TOKEN(TBOOLTK);
"double"        return SAVE_TOKEN(TDOUBLETK);
"char"          return SAVE_TOKEN(TCHARTK);
"string"        return SAVE_TOKEN(TSTRTK);
"array"         return SAVE_TOKEN(TARRTK);
 /* 模板 */
"template"      return SAVE_TOKEN(TTEMP);
"typename"      return SAVE_TOKEN(TTYNAME);
 /* 字符串操�? */
"substr"        return SAVE_TOKEN(TSUBS);
"reverse"       return SAVE_TOKEN(TREVS);
"title"         return SAVE_TOKEN(TTITLES);
"uppercase"     return SAVE_TOKEN(TUPS);
"lowercase"     return SAVE_TOKEN(TLOWS);


 /* 运算�? */
 /* 算数运算�? */
"**"            return SAVE_TOKEN(TPOWER);
"//"            return SAVE_TOKEN(TEDIV);
"++"            return SAVE_TOKEN(TSADD);
"--"            return SAVE_TOKEN(TSSUB);
"+"             return SAVE_TOKEN(TADD);
"-"             return SAVE_TOKEN(TSUB);
"*"             return SAVE_TOKEN(TMUL);
"/"             return SAVE_TOKEN(TDIV);
"%"             return SAVE_TOKEN(TMOD);
 /* 逻辑运算�? */
"||"            return SAVE_TOKEN(TOR);
"&&"            return SAVE_TOKEN(TAND);
"!"             return SAVE_TOKEN(TNOT);
 /* 关系运算�? */
"=="            return SAVE_TOKEN(TEQ);
"!="            return SAVE_TOKEN(TNE);
">="            return SAVE_TOKEN(TGE);
"<="            return SAVE_TOKEN(TLE);
"<"             return SAVE_TOKEN(TLT);
">"             return SAVE_TOKEN(TGT);

 /* 其它运算�?(函数定义) */
"->"            return SAVE_TOKEN(TARROW);

 /* 除char、string之外的字面量 */
"true"          {
                    yylval.boolean = 1;
                    return TBOOL;
                }
"false"         {
                    yylval.boolean = 0;
                    return TBOOL;
                }
{integer}       {
                    SAVE_INTEGER;
                    return TINTEGER;
                }
{real}          {
                    SAVE_REAL;
                    return TREAL;
                }
 /* 不需要进行额外处理的字符 */
"("             return '(';
")"             return ')';
"["             return '[';
"]"             return ']';
"{"             return '{';
"}"             return '}';
"."             return '.';
","             return ',';
":"             return ':';
"="             return '=';
 /* 需要忽略的空白�? */
[ \t\n\r]
 /* 标识�? */
{identifier}    {
                    SAVE_IDENTIFIER;
                    return TIDENTIFIER;
                }
 /* 对未知字符的处理 */
.               {
                    printf("line %d, len %d Unknown token %s !\n", yylineno, yyleng, yytext);
                    yyterminate();
                }
%%