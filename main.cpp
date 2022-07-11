#include <iostream>
#include "lexical_analysis.h"
using namespace std;
int main() {
    init_regex();
    bool make_token_success;
    char expression[1000];
    scanf("%s",expression);
    make_token_success = make_token(expression);
    cout<<make_token_success;
}
