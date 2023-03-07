#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();
void s21_strcat_test();
void s21_strchr_test();
void s21_strstr_test();

int main() {
#ifdef strlen
    s21_strlen_test();
#endif
#ifdef strcmp
    s21_strcmp_test();
#endif
#ifdef strcpy
    s21_strcpy_test();
#endif
#ifdef strcat
    s21_strcat_test();
#endif
#ifdef strchr
    s21_strchr_test();
#endif
#ifdef strstr
    s21_strstr_test();
#endif
}

void s21_strlen_test() {
    char str1[7] = "Hello\0";
    char str2[11] = "asfghcxzb\0";
    char str3[2] = "\0";
    int string;

    printf("Hello\n");
    string = s21_strlen(str1);
    printf("%d\n", string);
    if (string == 5)
        printf("\nSUCCESS\n");
    else
        printf("\nFAIL\n");

    printf("qwertyuiop\n");
    string = s21_strlen(str2);
    printf("%d\n", string);
    if (string == 9)
        printf("\nSUCCESS\n");
    else
        printf("\nFAIL\n");

    printf(" ");
    string = s21_strlen(str3);
    printf(" \n");

    if (string == 0)
        printf("\nSUCCESS\n");
    else
        printf("\nFAIL\n");
}

void s21_strcmp_test() {
    char str[6] = "12345\0";
    char str1[6] = "12346\0";
    char str2[6] = "12344\0";
    char str3[6] = "1a345\0";
    int string;

    printf("\n12345\t12345");
    string = s21_strcmp(str, str);
    printf("\n%d", string);
    if (string == 0)
        printf("\nSUCCESS\n");
    else
        printf("\nFAIL\n");

    printf("\n12345\t12346");
    string = s21_strcmp(str, str1);
    printf("\n%d", string);

    if (string == -1)
        printf("\nSUCCESS\n");
    else
        printf("\nFAIL\n");

    printf("\n12346\t12344");
    string = s21_strcmp(str1, str2);
    printf("\n%d", string);

    if (string == 1)
        printf("\nSUCCESS\n");
    else
        printf("\nFAIL\n");

    printf("\n12345\t1a345");
    string = s21_strcmp(str, str3);
    printf("\n%d", string);

    if (string == -1)
        printf("\nSUCCESS\n");
    else
        printf("\nFAIL\n");
}

void s21_strcpy_test() {
    char str[10];
    char str1[7] = "1r,r46\0";
    char str2[6] = "\0";
    int string;

    printf("\nNULL, NULL");
    string = s21_strcpy(NULL, NULL);
    printf("\n%d", string);

    if (string == 1)
        printf("\nSUCCESS\n");
    else
        printf("\nFAIL\n");

    printf("\nstr, \"1r,r46\"");
    s21_strcpy(str, str1);
    printf("\n%s", str);

    if (s21_strcmp(str, str1) == 0)
        printf("\nSUCCESS\n");
    else
        printf("\nFAIL\n");

    printf("\nstr, \"\"");
    s21_strcpy(str, str2);
    printf("\n%s", str);

    if (s21_strcmp(str, str2) == 0)
        printf("\nSUCCESS\n");
    else
        printf("\nFAIL\n");
}

void s21_strcat_test() {
    char str[10];
    char str1[7] = "1r,r46\0";
    char str2[1] = "\0";
    int string;

    printf("test_1:\n");
    printf("\nstr, NULL");
    string = s21_strcat(str, NULL);
    printf("\n%d", string);

    if (string == 1)
        printf("\nSUCCESS\n");
    else
        printf("\nFAIL\n");

    printf("\n1r,r46");
    s21_strcat(str, str1);
    printf("\n%s", str);

    if (s21_strcmp(str, "1r,r46\0") == 0)
        printf("\nSUCCESS\n");
    else
        printf("\nFAIL\n");

    printf("\nstr, \"\"");
    s21_strcat(str, str2);
    printf("\n%s", str);

    if (s21_strcmp(str, "1r,r46\0") == 0)
        printf("\nSUCCESS\n");
    else
        printf("\nFAIL\n");
}

void s21_strchr_test() {
    char str[7] = "1r,r46\0";
    char *string;

    printf("\n\"1r,r46\", \'t\'");
    string = s21_strchr(str, 't');
    printf("\n%s", string);

    if (string == NULL)
        printf("\nSUCCESS\n");
    else
        printf("\nFAIL\n");

    printf("\n\"1r,r46\", \'6\'");
    string = s21_strchr(str, '6');
    printf("\n%d", (int)(string - str));

    if (string == str + 5)
        printf("\nSUCCESS\n");
    else
        printf("\nFAIL\n");

    printf("\n\"1r,r46\", \'\\0\'");
    string = s21_strchr(str, '\0');
    printf("\n%s", string);

    if (string == NULL)
        printf("\nSUCCESS\n");
    else
        printf("\nFAIL\n");
}

void s21_strstr_test() {
    char str[7] = "1r,r46\0";
    char *string;

    printf("\n\"1r,r46\", \"r,r\"");
    string = s21_strstr(str, "r,r\0");
    printf("\n%d", (int)(string - str));

    if (string == str + 1)
        printf("\n\tSUCCESS\n");
    else
        printf("\n\tFAIL\n");

    printf("\n\"1r,r46\", \"632\"");
    string = s21_strstr(str, "632\0");
    printf("\n%s", string);

    if (string == NULL)
        printf("\nSUCCESS\n");
    else
        printf("\nnFAIL\n");

    printf("\n\"1r,r46\", \"r\"");
    string = s21_strstr(str, "r\0");
    printf("\n%d", (int)(string - str));

    if (string == str + 1)
        printf("\n\tSUCCESS\n");
    else
        printf("\n\tFAIL\n");
}