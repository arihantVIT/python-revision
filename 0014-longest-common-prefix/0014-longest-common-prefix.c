#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {

    if (strsSize == 0) {
        char *empty = malloc(1);
        empty[0] = '\0';
        return empty;
    }

    int len = strlen(strs[0]);

    for (int i = 1; i < strsSize; i++) {

        int j = 0;

        while (j < len && strs[i][j] != '\0' && strs[0][j] == strs[i][j]) {
            j++;
        }

        len = j;

        if (len == 0) break;
    }

    // create new string for answer
    char *result = (char*)malloc((len + 1) * sizeof(char));

    for (int i = 0; i < len; i++) {
        result[i] = strs[0][i];
    }

    result[len] = '\0';

    return result;
}
