//
// Created by cubazis on 24.05.18.
//
#include <check.h>
#include "stack.h"

START_TEST (test_pop)
    {
        //Test 0
        int res = push(1);
        ck_assert_int_eq(res, 0);

        //Test 1
        for (int i = 0; i < 49; ++i) {
            push(i);
        }
        res = push(55);
        ck_assert_int_eq(res, 1);
    }
END_TEST


START_TEST (test_peek)
    {
        //Test 0
        ck_assert_double_eq(pick(), -INFINITY);

        //Test 1
        push(5);
        ck_assert_double_eq(pick(), 5);

        push(-12);
        ck_assert_double_eq(pick(), -12);
        ck_assert_double_eq(pick(), -12);
        ck_assert_double_eq(pick(), -12);
    }
END_TEST

START_TEST (test_push)
    {
        //Test 0
        push(15);
        ck_assert_double_eq(pop(), 15);
        ck_assert_double_eq(pop(), -INFINITY);

        //Test 1
        for (int i = 0; i < 20; ++i) {
            push(i);
        }
        ck_assert_double_eq(pop(), 19);

        //Test 2
        for (int i = 18; i >= 0; --i) {
            ck_assert_double_eq(pop(), i);
        }
    }
END_TEST

Suite *str_suite(void) {
    Suite *suite = suite_create("stack");
    TCase *tcase = tcase_create("case");
    tcase_add_test(tcase, test_push);
    tcase_add_test(tcase, test_pop);
    tcase_add_test(tcase, test_peek);
    suite_add_tcase(suite, tcase);
    return suite;
}

int main(int argc, char *argv[]) {
    int number_failed;
    Suite *suite = str_suite();
    SRunner *runner = srunner_create(suite);
    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return number_failed;
}