//
// Created by piggy on 7/11/22.
//

#ifndef EXPR_LEXICAL_ANALYSIS_H
#define EXPR_LEXICAL_ANALYSIS_H
#include <regex.h>
#include "util.h"
using namespace std;
void init_regex();
bool make_token(char *e);
void move_tokens(int pos,int dir,int * nr_token);
void reverse_sign(char * num);
typedef struct Mytoken{
    int type;
    char str[32];
} Token;

namespace T_P{
    enum TOKEN_TYPE{
        TK_NOTYPE = 256,TK_EQ,TK_NUM,TK_HEX,TK_IMG_NUM
    };
}
#endif //EXPR_LEXICAL_ANALYSIS_H
