# Intro
This program is used for expression evaluation.
It can calculate nested expressions including complex number and hexdecimal number.
For convience, complex numbers in this program have to obey the format of {complex number}, e.g. {1+2i} is allowed but 1+2i is prohibited.

# Example
```shell
make
./expr
Input the expression you wanna evaluate:
{1+2i}*3*(123+12)
The value of the expression is:
405.00 + 810.00i
```

# Structure
```shell
.
├── Makefile
├── README.md
├── include
│   ├── evaluation.h
│   ├── lexical_analysis.h
│   ├── number.h
│   ├── syntatic_analysis.h
│   └── util.h
└── src
    ├── evaluation.cc
    ├── lexical_analysis.cc
    ├── main.cc
    ├── number.cc
    └── syntatic_analysis.cc

3 directories, 12 files
```