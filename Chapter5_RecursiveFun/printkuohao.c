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
    printKuoHao(str, n, n);
    free(str);
}

void printKuoHao(char *str, int left, int right) {
    if (str == 0 || left < 0 || left > STRING_LENGTH / 2 || right < 0 || right > STRING_LENGTH / 2) {
        printf("input is invalid.\n");
        return;
    }
    if (right == 0) {
        printf("%s\n", str);
    } else if (left == right) {
        strcat(str, "(");
        printKuoHao(str, --left, right);
    } else if (left < right && left > 0) {
        char *newStr = (char *)malloc(STRING_LENGTH);
        if (newStr == 0) {
            printf("alloc memory failed.\n");
            return;
        }
        strcpy(newStr, str);
        strcat(str, "(");
        printKuoHao(str, --left, right);
        strcat(newStr, ")");
        printKuoHao(newStr, ++left, --right);
        free(newStr);
    } else if (left == 0) {
        strcat(str, ")");
        printKuoHao(str, left, --right);
    }
}

int main() {
    printf("\n\n\nHello world!\n");
    listKuoHao(3);
}
