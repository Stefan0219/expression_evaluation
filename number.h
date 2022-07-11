//
// Created by piggy on 7/11/22.
//

#ifndef EXPR_NUMBER_H
#define EXPR_NUMBER_H

#include <stdio.h>
#include <string>
using namespace std;
class number{
private:
public:
    string literal;
     number(char *s){
        this->literal = s;
    }
    number(){}
    virtual void output(){

     }
};
class real_number: public number{
public:
    bool isHexnum;
    int value;
    real_number(char *s1) : number(s1) {
        if(s1[0] == '0'&&s1[1]=='x'){
            sscanf(this->literal.c_str(),"%x",&this->value);
            this->isHexnum = true;
        } else{
            sscanf(this->literal.c_str(),"%u",&this->value);
            this->isHexnum = false;
        }
    }
    real_number(int v){
        this->value = v;
    }
    void output(){
        if (isHexnum)
            printf("0x%x\n",value);
        else
            printf("%d\n",value);
    }
};
class imag_number: public number{
public:
    float realpart;
    float imaginarypart;
    imag_number(char* s1): number(s1){

    }
    imag_number(int real,int ima){
        this->realpart = real;
        this->imaginarypart = ima;
    }
    void output(){
        if(imaginarypart>=0)
            printf("%.2f + %.2fi\n",realpart,imaginarypart);
        else
            printf("%.2f %.2fi\n",realpart,imaginarypart);
    }
};
#endif //EXPR_NUMBER_H
