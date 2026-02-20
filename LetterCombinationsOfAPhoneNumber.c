#include <stdlib.h>
#include <string.h>

void backtrack(char *digits, int index, char *current,
               char **result, int *count, char **map) {
    
    if (digits[index] == '\0') {
        result[*count] = strdup(current);
        (*count)++;
        return;
    }

    char *letters = map[digits[index] - '0'];

    for (int i = 0; letters[i] != '\0'; i++) {
        current[index] = letters[i];
        backtrack(digits, index + 1, current, result, count, map);
    }
}

char** letterCombinations(char* digits, int* returnSize) {

    if (digits == NULL || strlen(digits) == 0) {
        *returnSize = 0;
        return NULL;
    }

    char *map[10] = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    int len = strlen(digits);

    char **result = (char**)malloc(256 * sizeof(char*));
    char current[5];
    current[len] = '\0';

    int count = 0;

    backtrack(digits, 0, current, result, &count, map);

    *returnSize = count;
    return result;
}