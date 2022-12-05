#include <iostream>
#include "Expression.h"
#include "ProgramBlock.h"

extern qwq::ProgramBlock* programBlock;
extern int yyparse();
extern int yylex_destroy();
extern FILE* yyin;

int main(int argc, char** argv) {
    std::string fileName;

    if (argc == 1) {
        fileName = "/home/qingyue/data/cpp/myPL/examples/test_while.qwq";
    } else {
        fileName = argv[1];
    }

    yyin = fopen(fileName.c_str(), "r+");
    if (yyin == nullptr) {
        std::cout << "File " << fileName << "not found. Abort" << std::endl;
        return -1;
    }

    // TODO: 判断是否语法分析成功
    if (yyparse()) {
        std::cout << "fail" << std::endl;
        yylex_destroy();
        return 1;
    }
    std::cout << "grammaAnalyze success";
    fclose(yyin);
    yylex_destroy();
    return 0;
}