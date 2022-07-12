//
// Created by piggy on 7/12/22.
//
#include "util.h"
#include "syntatic_analysis.h"
#include "lexical_analysis.h"
void test(){
    cout<<"number of tokens are: "<<nr_token<<" \n";
    for (int i = 0; i < nr_token; ++i) {
        cout<<tokens[i].str<<" ";
    }
}