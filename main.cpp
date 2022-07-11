#include <iostream>
#include "lexical_analysis.h"
#include <cassert>
using namespace std;
int main() {
    init_regex();
    bool make_token_success;
    char expression[1000];
    scanf("%[^\n]",expression);
    assert(make_token_success = make_token(expression));
}
