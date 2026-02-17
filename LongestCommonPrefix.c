#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";

    int i = 0;

    while (1) {
        char c = strs[0][i];
        if (c == '\0') break;

        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] != c)
                goto end;
        }
        i++;
    }

end:
    char* res = (char*)malloc(i + 1);
    strncpy(res, strs[0], i);
    res[i] = '\0';
    return res;
}
