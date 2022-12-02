#include <iostream>
#include "Expression.h"

extern int yyparse();
extern int yylex_destroy();

int main(int argc, char** argv) {
    std::string fileName;

    if (argc == 1) {
        fileName = "./examples/test_full.liq";
    } else {
        fileName = argv[1];
    }

    yyin == fopen(fileName.c_str(), "r+");
    if (yyin == nullptr) {
        std::cout << "File " << fileName << "not found. Abort" << std::endl;
        return -1
    }

    // TODO: 判断是否语法分析成功

    std::cout << "grammaAnalyze success";
    fclose(yyin);
    yylex_destroy();
    return 0;
}