#include "printAst.h"

void io::print_empty_bay() {
    std::cout << " ";
}

void io::print_ident(int depth) {
    for (int i = 0; i < depth; i++) {
        std::cout << "  ";
    }
}

void io::print_endl() {
    std::cout << std::endl;
}