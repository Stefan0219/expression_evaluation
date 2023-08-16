//
// Created by piggy on 7/12/22.
//

#ifndef EXPR_SYNTATIC_ANALYSIS_H
#define EXPR_SYNTATIC_ANALYSIS_H
#include <lexical_analysis.h>
extern Token tokens[32];
extern int nr_token;
bool check_parentheses(int p ,int q ,bool* good_expr);

#endif //EXPR_SYNTATIC_ANALYSIS_H
