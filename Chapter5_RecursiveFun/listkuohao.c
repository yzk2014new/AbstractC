#include <stdio.h>
#include <string.h>

#define STRING_LENGTH 64

void listKuoHao(int n) {
    if (n <= 0 || n > STRING_LENGTH / 2) {
        printf("number is invalid.\n");
        return;
    }
    char *str = (char *)malloc(STRING_LENGTH);
    if (str == 0) {
        printf("alloc memory failed.\n");
        return;
    }
    str[0] = '\0';
    printKuoHao(str, n);
    free(str);
}

void printKuoHao(char *str, int n) {
    if (str == 0 || n < 0 || n > STRING_LENGTH / 2) {
        printf("input is invalid.\n");
        return;
    }
    if (n == 0) {
        printf("%s\n", str);
    } else {
        char *newStr1 = (char *)malloc(STRING_LENGTH);
        char *newStr2 = (char *)malloc(STRING_LENGTH);
        if (newStr1 == 0 || newStr2 == NULL) {
            printf("alloc memory failed.\n");
            return;
        }
        strcpy(newStr1, str);
        strcat(newStr1, "()");
        strcpy(newStr2, "()");
        strcat(newStr2, str);
        printf("n: %d, str1: %s, str2: %s, cmp: %d\n", n, newStr1, newStr2, strcmp(newStr1, newStr2));
        if (strcmp(newStr1, newStr2) == 0) {
            printKuoHao(newStr1, n - 1);
        } else {
            printKuoHao(newStr1, n - 1);
            printKuoHao(newStr2, n - 1);
        }
        free(newStr1);

        newStr2[0] = '\0';
        strcpy(newStr2, "(");
        strcat(newStr2, str);
        strcat(newStr2, ")");
        printKuoHao(newStr2, n - 1);
        free(newStr2);
    }
}

int main() {
    printf("Hello world!\n");
    listKuoHao(2);
}
