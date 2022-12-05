cmake_minimum_required(VERSION 3.20)
project(myPL)

set(CMAKE_CXX_STANDARD 17)

find_package(BISON)
find_package(FLEX)

BISON_TARGET(
        Parser
        qwq.yy ${CMAKE_CURRENT_BINARY_DIR}/qwq_parser.cpp
        COMPILE_FLAGS --report=solved
        COMPILE_FLAGS -v
)

FLEX_TARGET(
        Lexer
        qwq.l ${CMAKE_CURRENT_BINARY_DIR}/qwq_tokens.cpp
)

ADD_FLEX_BISON_DEPENDENCY(Lexer Parser)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}
)

add_executable(myPL 
${BISON_Parser_OUTPUTS} 
${FLEX_Lexer_OUTPUTS} 
        main.cpp
        AstNode.cpp
        Statement.cpp
        Expression.cpp
        FunctionDeclaration.cpp
        ClassDeclaration.cpp
        CommonStatement.cpp
        Literal.cpp
        Type.cpp
        StringExpression.cpp VariableDeclaration.cpp VariableDeclaration.h SymbolManager.cpp SymbolManager.h Element.cpp Element.h Array.cpp Array.h)
