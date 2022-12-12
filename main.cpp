#include <iostream>
#include "Expression.h"
#include "ProgramBlock.h"
#include <string.h>

extern qwq::ProgramBlock* programBlock;
extern int yyparse();
extern int yylex_destroy();
extern FILE* yyin;
void usage();

int main(int argc, char** argv) {
    std::string fileName = "";
    bool printTree = false;

    if (argc == 1) {
        fileName = "/home/qingyue/data/cpp/myPL/examples/test_array_2d.qwq";
    } else {
        for (int i = 1; i < argc; i++) {
            if (!strcmp(argv[i] , "-t")) {
                printTree = true;
            } else if (!strcmp(argv[i] , "-h")) {
                usage();
                return 0;
            } else {
                if (fileName.length() == 0) {
                    fileName = argv[i];
                } else {
                    // 出现了两个非参数的变量,错误
                    std::cout << "参数错误" << "\n";
                    usage();
                    return 1;
                }
            }
        }
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
    std::cout << "grammaAnalyze success" << std::endl;
    // 如果输入了-t参数，需要输出语法树
    if (printTree) {
        std::cout << "ast:" << std::endl;
        programBlock->printAst(0);
        std::cout << "ast-end" << std::endl;
    }
    std::cout << "start executing" << std::endl;
    programBlock->eval();
    std::cout << "finished" << std::endl;
    fclose(yyin);
    yylex_destroy();
    return 0;
}

void usage()
{
   std::cout << "Usage:\n";
   std::cout << "./myPL filename -t -h\n";
   std::cout << "\t-h this help text.\n";
   std::cout << "\t-t tell qwq to print ast.\n";
}