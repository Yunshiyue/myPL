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
        fileName = "/home/qingyue/data/cpp/myPL/examples/test_array_2d.qwq";
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
    std::cout << "gramma analyze success" << std::endl;
    std::cout << "ast:" << std::endl;
    programBlock->printAst(1);
    std::cout << "ast-end" << std::endl;
    std::cout << "start executing" << std::endl;
    programBlock->eval();
    std::cout << "finished" << std::endl;
    fclose(yyin);
    yylex_destroy();
    return 0;
}