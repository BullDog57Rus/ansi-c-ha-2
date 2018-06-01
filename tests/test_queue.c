#include <check.h>
#include "priority_queue.h"

START_TEST (test_insert)
    {
        //Test 0
        ck_assert_int_eq(insert(5, 1), 0);

        //Test 1
        ck_assert_int_eq(insert(6, 2), 0);
        ck_assert_int_eq(insert(2, 2), 0);
        ck_assert_int_eq(insert(21, 2), 0);
        ck_assert_int_eq(insert(1, 3), 0);


        //Test 3
        for (int i = 5; i < 100; ++i) {
            insert(i, i);
        }
        ck_assert_int_eq(insert(1, 1), 1);

    }
END_TEST

START_TEST (test_min)
    {
        //Test 0
        ck_assert_double_eq(extract_min(), 5);
        ck_assert_double_eq(extract_min(), 6);
        ck_assert_double_eq(extract_min(), 2);
        ck_assert_double_eq(extract_min(), 21);
        ck_assert_double_eq(extract_min(), 1);
        ck_assert_double_eq(extract_min(), 5);

        //Test 1

    }
END_TEST

Suite *str_suite(void) {
    Suite *suite = suite_create("priority queue");
    TCase *tcase = tcase_create("case");
    tcase_add_test(tcase, test_insert);
    tcase_add_test(tcase, test_min);
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