#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValid(char* s) {
    int n = strlen(s);
    char *stack = (char*)malloc(n);
    int top = -1;

    for(int i = 0; i < n; i++) {
        char c = s[i];

        if(c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } else {
            if(top == -1) return false;

            char t = stack[top--];

            if((c == ')' && t != '(') ||
               (c == '}' && t != '{') ||
               (c == ']' && t != '['))
                return false;
        }
    }

    return top == -1;
}