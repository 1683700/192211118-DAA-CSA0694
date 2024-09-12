#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ALPHABET_SIZE 26
int charIndex(char c) 
{
    return c - 'a';
}
char** maxNumOfSubstrings(char* s, int* returnSize) {
    int n = strlen(s);
    int left[ALPHABET_SIZE];
    int right[ALPHABET_SIZE];
    int i, j;
    for (i = 0; i < ALPHABET_SIZE; i++) {
        left[i] = n;
        right[i] = -1;
    }
    for (i = 0; i < n; i++) 
	{
        int index = charIndex(s[i]);
        if (left[index] > i) left[index] = i;
        if (right[index] < i) right[index] = i;
    }
    char** result = (char**)malloc(n * sizeof(char*));
    *returnSize = 0;
    int r = -1;
    for (i = 0; i < n; i++) {
        if (i != left[charIndex(s[i])]) continue;
        int new_r = right[charIndex(s[i])];
        int k = i + 1;
        while (k <= new_r) {
            if (left[charIndex(s[k])] < i) {
                new_r = n;
                break;
            }
            new_r = (new_r > right[charIndex(s[k])]) ? new_r : right[charIndex(s[k])];
            k++;
        }
        if (new_r < n && (i > r || new_r < right[charIndex(s[r])])) {
            if (i > r) {
                result[*returnSize] = (char*)malloc((new_r - i + 2) * sizeof(char));
                strncpy(result[*returnSize], s + i, new_r - i + 1);
                result[*returnSize][new_r - i + 1] = '\0';
                (*returnSize)++;
            } else {
                free(result[*returnSize - 1]);
                result[*returnSize - 1] = (char*)malloc((new_r - i + 2) * sizeof(char));
                strncpy(result[*returnSize - 1], s + i, new_r - i + 1);
                result[*returnSize - 1][new_r - i + 1] = '\0';
            }
            r = new_r;
        }
    }

    return result;
}
int main() {
    char s[1000];
    int returnSize;
    printf("Enter the string: ");
    fgets(s, sizeof(s), stdin);
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
    char** result = maxNumOfSubstrings(s, &returnSize);
    printf("Result:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);

    return 0;
}

