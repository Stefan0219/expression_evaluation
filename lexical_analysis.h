//
// Created by piggy on 7/11/22.
//

#ifndef EXPR_LEXICAL_ANALYSIS_H
#define EXPR_LEXICAL_ANALYSIS_H
#include <regex.h>
#include <cstdio>
#include <iostream>
using namespace std;
void init_regex();
bool make_token(char *e);
void move_tokens(int pos,int dir,int * nr_token);
void reverse_sign(char * num);
#endif //EXPR_LEXICAL_ANALYSIS_H
