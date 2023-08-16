//
// Created by piggy on 7/12/22.
//
#include <syntatic_analysis.h>


bool check_parentheses(int p ,int q ,bool *good_expr){
    //一个变量 当遇到左括号时++ 遇到右括号时-- 一个bool记录是否遇到括号
    //当既遇到左括号bool为零时 返回正确 当未终止时为零 则记录bool为错误 当终止时变量不为零 则返回错误
    int num_par = 0;
    bool meetbr = false;//遇到括号
    bool check = false;//返回值
    bool surround  = true;//表达式最左最右有括号时 为真
    bool too_early  =false;
    *good_expr = true;
    if(tokens[p].type != '(' || tokens[q].type != ')'){//先检查最左边和最右边的括号
        surround = false;
    }
    for(int i = p;i<=q;i++){
        switch (tokens[i].type){
            case '(':
                num_par++;
                meetbr = true;
                break;
            case ')':
                num_par--;
                meetbr = true;
                break;
            default :
                break;
        }

        if(meetbr == true && num_par == 0 && i != q )//在未终止前就出现了和左括号数量相等的右括号
            too_early =true;


        if(meetbr == true && num_par < 0 && i != q ){
            too_early = true;
            *good_expr = false;
        }
    }

    if(num_par!=0){//没有完全匹配 表达式不合法
        check = false;
        *good_expr = false;
    }
    if(surround==true && too_early == false){
        check = true;
    }
    /*
    //test-----------------------------
    if(check)
    printf("good check\n");
    else
    printf("bad check\n");
    if(*good_expr)
    printf("good expressions.\n");
    else if(!*good_expr)
    printf("bad expressions.\n");
    //test----------------------------
     */
    return check;
}