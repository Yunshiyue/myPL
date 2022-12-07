# qwq

北航研究生课程”程序设计语言原理“大作业，使用flex+bison+解释器完成

## 安装

### Prerequisite

+ flex
+ bison
+ cmake 3.12

### Build

1. Clone this repository.
   ```
   git clone git@github.com:Yunshiyue/myPL.git
   ```

2. Run cmake and generate the build files into the build directory `build`.
   ```
   cmake -B build
   ```

   Make sure all variables are set properly and then generate the build.

   One can use `ccmake` (GUI) to change or check the variables.

3. Run the make
   ```
   cd build
   make
   ```

4. That's it

## 使用方法

```c++
// in /build
./myPL fileName -h -t
/* where
-h	help: shows the usage.
-t	tree: tell qwq to print ast.
*/
```

## 文件结构

+ 文档
  + 包含课程提交的文档
+ build
  + build生成的文件
  + 其中
    + qwq_parser.cpp qwq_parser.hpp 由bison生成
    + qwq_tokens.cpp 由flex生成
    + qwq_parser.output 说明了语法分析器的详细状态转移方式
+ qwq.l
  + 生成词法分析器的文件
+ qwq.yy
  + 生成语法分析器的文件