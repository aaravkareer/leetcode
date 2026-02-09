char* convert(char* s, int numRows) {
    int len = strlen(s);

    if (numRows == 1 || numRows >= len) {
        char* out = malloc(len + 1);
        strcpy(out, s);
        return out;
    }

    char** rows = malloc(numRows * sizeof(char*));
    int* sizes = calloc(numRows, sizeof(int));

    for (int i = 0; i < numRows; i++) {
        rows[i] = malloc(len + 1);
    }

    int currRow = 0;
    int dir = 1;

    for (int i = 0; i < len; i++) {
        rows[currRow][sizes[currRow]++] = s[i];

        if (currRow == 0)
            dir = 1;
        else if (currRow == numRows - 1)
            dir = -1;

        currRow += dir;
    }

    char* result = malloc(len + 1);
    int k = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            result[k++] = rows[i][j];
        }
        free(rows[i]);
    }

    result[k] = '\0';

    free(rows);
    free(sizes);

    return result;
}