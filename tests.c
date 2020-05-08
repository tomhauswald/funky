#include "funky.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void linebreak() { putchar('\n'); }

typedef struct _string_list {
    char const* text;
    struct _string_list* pNext;
} string_list_t;

string_list_t* string_list_create(size_t num_strings) {
    string_list_t* pList = malloc(sizeof(string_list_t));
    string_list_t* pCurr = pList;
    for(size_t i = 1; i < num_strings; ++i) {
        pCurr->pNext = malloc(sizeof(string_list_t));
        pCurr = pCurr->pNext;
    }
    return pList;
}

void string_list_set(string_list_t* pList, size_t index, char const* text) {
    for(size_t i = 0; i < index; ++i) {
        pList = pList->pNext;
    }
    pList->text = text;
}

void string_list_free(string_list_t* pList) {
    while(pList) {
        string_list_t* pPrev = pList;
        pList = pPrev->pNext;
        free(pPrev);
    }
}

static const char hello[] = "hello, world";
static string_list_t* pList;

void setup() {
    pList = string_list_create(3);
    string_list_set(pList, 0, "hello");
    string_list_set(pList, 1, ", ");
    string_list_set(pList, 2, "world");
} 

void teardown() {
    string_list_free(pList);
    pList = NULL;
}

void testcase_start(char const* name, char const* expected_stdout) {
    printf("+--------------------------------------+\n");
    printf("| Running testcase: '%s'\n", name);
    printf("| Expected output:\n");
    printf("| '%s'\n", expected_stdout);
    printf("+--------------------------------------+\n");
    printf("| '");
}

void testcase_end() {
    printf("'\n");
    printf("+--------------------------------------+\n\n");
}

void test_foreach() {
    testcase_start("foreach_linear", "hello");
    fk_foreach_linear(hello, hello + 5, c, putchar(c));
    testcase_end();

    testcase_start("foreach_ntimes", "hello, wor");
    fk_foreach_ntimes(hello, 10, c, putchar(c));
    testcase_end();

    testcase_start("foreach_static", "hello, world");
    fk_foreach_static(hello, c, putchar(c));
    testcase_end();

    testcase_start("foreach_nullterm", "hello, world");
    fk_foreach_nullterm(pList, _fk_iter=_fk_iter->pNext, str, printf("%s", str.text));
    testcase_end();
}

void test_any() {
    testcase_start("any_linear", "true");
    printf("%s", fk_any_linear(hello, hello + 5, c, c == 'h') ? "true" : "false");
    testcase_end();

    testcase_start("any_ntimes", "false");
    printf("%s", fk_any_ntimes(hello, 10, c, c == 'd') ? "true" : "false");
    testcase_end();

    testcase_start("any_static", "true");
    printf("%s", fk_any_static(hello, c, c == ',') ? "true" : "false");
    testcase_end();

    testcase_start("any_nullterm", "true");
    printf("%s", fk_any_nullterm(pList, (_fk_iter = _fk_iter->pNext), str, !strcmp(str.text, "hello")
    ) ? "true" : "false");
    testcase_end();
}

void test_all() {
    testcase_start("all_linear", "true");
    printf("%s", fk_all_linear(hello, hello + 5, c, c >= 'e' && c <= 'o') ? "true" : "false");
    testcase_end();
    
    testcase_start("all_ntimes", "false");
    printf("%s", fk_all_ntimes(hello, 10, c, c >= 'e' && c <= 'o') ? "true" : "false");
    testcase_end();
    
    testcase_start("all_static", "true");
    printf("%s", fk_all_static(hello, c, c != '.') ? "true" : "false");
    testcase_end();
    
    testcase_start("all_nullterm", "false");
    printf("%s", fk_all_nullterm(pList, (_fk_iter = _fk_iter->pNext), str, !strcmp(str.text, "hello")
    ) ? "true" : "false");
    testcase_end();
}

void test_sum() {
}

void test_count() {
    testcase_start("count_linear", "3");
    printf("%ld", fk_count_linear(hello, hello + 5, c, c != 'l'));
    testcase_end();

    testcase_start("count_ntimes", "1");
    printf("%ld", fk_count_ntimes(hello, 10, c, c == ','));
    testcase_end();

    testcase_start("count_static", "10");
    printf("%ld", fk_count_static(hello, c, c >= 'a' && c <= 'z'));
    testcase_end();

    testcase_start("count_nullterm", "1");
    printf("%ld", fk_count_nullterm(pList, (_fk_iter = _fk_iter->pNext), str, !strcmp(str.text, "hello")));
    testcase_end();
}

int main() {
    setup();

    test_foreach();
    test_any();
    test_all();
    test_sum();
    test_count();

    teardown();
    return 0;
}