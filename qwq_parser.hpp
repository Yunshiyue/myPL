/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_QWQ_PARSER_HPP_INCLUDED
# define YY_YY_QWQ_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "qwq.yy"


# define YYLTYPE_IS_DECLARED 1 /* alert the parser that we have our own definition */


#line 55 "qwq_parser.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TINTEGER = 258,                /* TINTEGER  */
    TREAL = 259,                   /* TREAL  */
    TBOOL = 260,                   /* TBOOL  */
    TCHAR = 261,                   /* TCHAR  */
    TSTRING = 262,                 /* TSTRING  */
    TIDENTIFIER = 263,             /* TIDENTIFIER  */
    TPOWER = 264,                  /* TPOWER  */
    TEDIV = 265,                   /* TEDIV  */
    TSADD = 266,                   /* TSADD  */
    TSSUB = 267,                   /* TSSUB  */
    TADD = 268,                    /* TADD  */
    TSUB = 269,                    /* TSUB  */
    TMUL = 270,                    /* TMUL  */
    TDIV = 271,                    /* TDIV  */
    TMOD = 272,                    /* TMOD  */
    TAND = 273,                    /* TAND  */
    TOR = 274,                     /* TOR  */
    TNOT = 275,                    /* TNOT  */
    TEQ = 276,                     /* TEQ  */
    TNE = 277,                     /* TNE  */
    TGE = 278,                     /* TGE  */
    TLE = 279,                     /* TLE  */
    TGT = 280,                     /* TGT  */
    TLT = 281,                     /* TLT  */
    TARROW = 282,                  /* TARROW  */
    TIF = 283,                     /* TIF  */
    TELSE = 284,                   /* TELSE  */
    TELIF = 285,                   /* TELIF  */
    TFOR = 286,                    /* TFOR  */
    TWHILE = 287,                  /* TWHILE  */
    TIN = 288,                     /* TIN  */
    TTHIS = 289,                   /* TTHIS  */
    TPUBLIC = 290,                 /* TPUBLIC  */
    TPRIVATE = 291,                /* TPRIVATE  */
    TPROTECTED = 292,              /* TPROTECTED  */
    TEXTEND = 293,                 /* TEXTEND  */
    TCLASS = 294,                  /* TCLASS  */
    TDEF = 295,                    /* TDEF  */
    TRETURN = 296,                 /* TRETURN  */
    TCONTINUE = 297,               /* TCONTINUE  */
    TBREAK = 298,                  /* TBREAK  */
    TINTTK = 299,                  /* TINTTK  */
    TBOOLTK = 300,                 /* TBOOLTK  */
    TDOUBLETK = 301,               /* TDOUBLETK  */
    TCHARTK = 302,                 /* TCHARTK  */
    TSTRTK = 303,                  /* TSTRTK  */
    TARRTK = 304,                  /* TARRTK  */
    TTEMP = 305,                   /* TTEMP  */
    TTYNAME = 306,                 /* TTYNAME  */
    TSUBS = 307,                   /* TSUBS  */
    TREVS = 308,                   /* TREVS  */
    TTITLES = 309,                 /* TTITLES  */
    TUPS = 310,                    /* TUPS  */
    TLOWS = 311                    /* TLOWS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 48 "qwq.yy"

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
    long long integer;
    double real;
    int boolean;
    char character;
    std::string *string; // 如果是string就是字符串的内容，如果是identifier就是标识符的名字
    int token;

#line 166 "qwq_parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_QWQ_PARSER_HPP_INCLUDED  */
