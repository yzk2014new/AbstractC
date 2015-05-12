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
    //printf("printKuoHao: %s, %d\n", str, n);
    if (str == 0 || n < 0 || n > STRING_LENGTH / 2) {
        printf("input is invalid.\n");
        return;
    }
    if (n == 1 && strlen(str) == 0) {
        printf("()\n");
	} else if (n == 0) {
        printf("%s\n", str);
    } else {
        char *newStr1 = (char *)malloc(STRING_LENGTH);
        char *newStr2 = (char *)malloc(STRING_LENGTH);
        char *newStr3 = (char *)malloc(STRING_LENGTH);
        if (newStr1 == 0 || newStr2 == NULL || newStr3 == NULL) {
            printf("alloc memory failed.\n");
            return;
        }
        strcpy(newStr1, str);
        strcat(newStr1, "()");
        strcpy(newStr2, "()");
        strcat(newStr2, str);
        strcpy(newStr3, "(");
        strcat(newStr3, str);
        strcat(newStr3, ")");
        printKuoHao(newStr1, n - 1);
        if (strcmp(newStr1, newStr2) == 0) {
            if (strcmp(newStr1, newStr3) != 0) {
                printKuoHao(newStr3, n - 1);
            }
        } else {
            printKuoHao(newStr2, n - 1);
            if (strcmp(newStr1, newStr3) != 0 && strcmp(newStr2, newStr3) != 0) {
                printKuoHao(newStr3, n - 1);
            }
        }
        free(newStr1);
        free(newStr2);
        free(newStr3);
    }
}

int main() {
    printf("\n\n\nHello world!\n");
    listKuoHao(3);
}
