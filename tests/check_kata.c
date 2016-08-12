#include <stdlib.h>
#include <check.h>
#include "../src/kata.h"

/*
 * kata_atoi tests
 */
START_TEST(test_kata_atoi_single_digit)
{
  ck_assert_int_eq(kata_atoi("I"), 1);
}
END_TEST

START_TEST(test_kata_atoi_lesser_before_bigger)
{
  ck_assert_int_eq(kata_atoi("IV"), 4);
}
END_TEST

START_TEST(test_kata_atoi_lesser_before_bigger_after_bigger)
{
  ck_assert_int_eq(kata_atoi("XIV"), 14);
}
END_TEST

START_TEST(test_kata_atoi_max_number)
{
  ck_assert_int_eq(kata_atoi("MMMCMXCIX"), 3999);
}
END_TEST

/*
 * kata_itoa tests
 */
START_TEST(test_kata_itoa)
{
  char resbuf[KATA_MAXLEN];
  ck_assert_str_eq(kata_itoa(1, resbuf), "I");
}
END_TEST

/*
 * kata_add tests
 */
START_TEST(test_kata_add_one_plus_one)
{
  char resbuf[KATA_MAXLEN];
  kata_add("I", "I", resbuf);
  ck_assert_str_eq(resbuf, "II");
}
END_TEST

/*
 * data_sub tests
 */
START_TEST(test_kata_sub_two_minus_one)
{
  char resbuf[KATA_MAXLEN];
  kata_sub("II", "I", resbuf);
  ck_assert_str_eq(resbuf, "I");
}
END_TEST


/*
 * test suites
 */
Suite *
kata_all(void)
{
  Suite *suite;
  TCase *tc;

  suite = suite_create("kata");

  tc = tcase_create("test_kata_atoi_single_digit");
  tcase_add_test(tc, test_kata_atoi_single_digit);
  suite_add_tcase(suite, tc);

  tc = tcase_create("test_kata_atoi_lesser_before_bigger");
  tcase_add_test(tc, test_kata_atoi_lesser_before_bigger);
  suite_add_tcase(suite, tc);

  tc = tcase_create("test_kata_atoi_lesser_before_bigger_after_bigger");
  tcase_add_test(tc, test_kata_atoi_lesser_before_bigger_after_bigger);
  suite_add_tcase(suite, tc);

  tc = tcase_create("test_kata_atoi_max_number");
  tcase_add_test(tc, test_kata_atoi_max_number);
  suite_add_tcase(suite, tc);

  tc = tcase_create("test_kata_itoa");
  tcase_add_test(tc, test_kata_itoa);
  suite_add_tcase(suite, tc);

  tc = tcase_create("test_kata_add_one_plus_one");
  tcase_add_test(tc, test_kata_add_one_plus_one);
  suite_add_tcase(suite, tc);

  tc = tcase_create("test_kata_sub_two_minus_one");
  tcase_add_test(tc, test_kata_sub_two_minus_one);
  suite_add_tcase(suite, tc);

  return suite;
}

int
main(int argc, char **argv)
{
  int nfailures;
  Suite *suite;
  SRunner *runner;

  suite = kata_all();
  runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);
  nfailures = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (nfailures == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
