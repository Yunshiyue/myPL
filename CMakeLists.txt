cmake_minimum_required(VERSION 3.20)
project(myPL)

set(CMAKE_CXX_STANDARD 17)

find_package(BISON)
find_package(FLEX)

# BISON_TARGET(
#         Parser
#         parser.yy ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp
# )

# FLEX_TARGET(
#         Lexer
#         tokens.l ${CMAKE_CURRENT_BINARY_DIR}/tokens.cpp
# )

# ADD_FLEX_BISON_DEPENDENCY(Lexer Parser)

# include_directories(
#         ${CMAKE_CURRENT_SOURCE_DIR}
#         ${CMAKE_CURRENT_BINARY_DIR}
# )

add_executable(myPL 
#${BISON_Parser_OUTPUTS} 
#${FLEX_Lexer_OUTPUTS} 
        main.cpp
        AstNode.cpp
        Statement.cpp
        Expression.cpp
        FunctionDeclaration.cpp
        ClassDeclaration.cpp
        CommonStatement.cpp
        Literal.cpp
        Type.cpp
        StringExpression.cpp)
