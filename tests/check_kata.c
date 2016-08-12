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
START_TEST(test_kata_itoa_one)
{
  char resbuf[KATA_MAXLEN];
  ck_assert_str_eq(kata_itoa(1, resbuf), "I");
}
END_TEST

START_TEST(test_kata_itoa_two)
{
  char resbuf[KATA_MAXLEN];
  ck_assert_str_eq(kata_itoa(2, resbuf), "II");
}
END_TEST

START_TEST(test_kata_itoa_max_number)
{
  char resbuf[KATA_MAXLEN];
  ck_assert_str_eq(kata_itoa(3999, resbuf), "MMMCMXCIX");
}
END_TEST

START_TEST(test_kata_itoa_overflow)
{
  char resbuf[KATA_MAXLEN];
  ck_assert_str_eq(kata_itoa(4000, resbuf), "");
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

START_TEST(test_kata_add_one_plus_two)
{
  char resbuf[KATA_MAXLEN];
  kata_add("I", "II", resbuf);
  ck_assert_str_eq(resbuf, "III");
}
END_TEST

START_TEST(test_kata_add_one_plus_lesser_before_bigger)
{
  char resbuf[KATA_MAXLEN];
  kata_add("I", "IX", resbuf);
  ck_assert_str_eq(resbuf, "X");
}
END_TEST

START_TEST(test_kata_add_single_plus_triple)
{
  char resbuf[KATA_MAXLEN];
  kata_add("X", "XXX", resbuf);
  ck_assert_str_eq(resbuf, "XL");
}
END_TEST

START_TEST(test_kata_add_double_plus_triple)
{
  char resbuf[KATA_MAXLEN];
  kata_add("CC", "CCC", resbuf);
  ck_assert_str_eq(resbuf, "D");
}
END_TEST

START_TEST(test_kata_add_overflow)
{
  char resbuf[KATA_MAXLEN];
  kata_add("MMMCMXCIX", "I", resbuf);
  ck_assert_str_eq(resbuf, "");
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

START_TEST(test_kata_sub_three_minus_one)
{
  char resbuf[KATA_MAXLEN];
  kata_sub("III", "I", resbuf);
  ck_assert_str_eq(resbuf, "II");
}
END_TEST

START_TEST(test_kata_sub_ten_minus_one)
{
  char resbuf[KATA_MAXLEN];
  kata_sub("X", "I", resbuf);
  ck_assert_str_eq(resbuf, "IX");
}
END_TEST

START_TEST(test_kata_sub_hundred_minus_one)
{
  char resbuf[KATA_MAXLEN];
  kata_sub("C", "I", resbuf);
  ck_assert_str_eq(resbuf, "XCIX");
}
END_TEST

START_TEST(test_kata_sub_thousand_minus_one)
{
  char resbuf[KATA_MAXLEN];
  kata_sub("M", "I", resbuf);
  ck_assert_str_eq(resbuf, "CMXCIX");
}
END_TEST

START_TEST(test_kata_sub_lesser_before_bigger_minus_lesser)
{
  char resbuf[KATA_MAXLEN];
  kata_sub("CD", "C", resbuf);
  ck_assert_str_eq(resbuf, "CCC");
}
END_TEST

START_TEST(test_kata_sub_triple_minus_single)
{
  char resbuf[KATA_MAXLEN];
  kata_sub("CCC", "C", resbuf);
  ck_assert_str_eq(resbuf, "CC");
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

  /* kata_atoi tests */
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

  /* kata_itoa tests */
  tc = tcase_create("test_kata_itoa_one");
  tcase_add_test(tc, test_kata_itoa_one);
  suite_add_tcase(suite, tc);

  tc = tcase_create("test_kata_itoa_two");
  tcase_add_test(tc, test_kata_itoa_two);
  suite_add_tcase(suite, tc);

  tc = tcase_create("test_kata_itoa_max_number");
  tcase_add_test(tc, test_kata_itoa_max_number);
  suite_add_tcase(suite, tc);

  tc = tcase_create("test_kata_itoa_overflow");
  tcase_add_test(tc, test_kata_itoa_overflow);
  suite_add_tcase(suite, tc);

  /* kata_add tests */
  tc = tcase_create("test_kata_add_one_plus_one");
  tcase_add_test(tc, test_kata_add_one_plus_one);
  suite_add_tcase(suite, tc);

  tc = tcase_create("test_kata_add_one_plus_two");
  tcase_add_test(tc, test_kata_add_one_plus_two);
  suite_add_tcase(suite, tc);

  tc = tcase_create("test_kata_add_one_plus_lesser_before_bigger");
  tcase_add_test(tc, test_kata_add_one_plus_lesser_before_bigger);
  suite_add_tcase(suite, tc);

  tc = tcase_create("test_kata_add_single_plus_triple");
  tcase_add_test(tc, test_kata_add_single_plus_triple);
  suite_add_tcase(suite, tc);

  tc = tcase_create("test_kata_add_double_plus_triple");
  tcase_add_test(tc, test_kata_add_double_plus_triple);
  suite_add_tcase(suite, tc);

  tc = tcase_create("test_kata_add_overflow");
  tcase_add_test(tc, test_kata_add_overflow);
  suite_add_tcase(suite, tc);

  /* kata_sub tests */
  tc = tcase_create("test_kata_sub_two_minus_one");
  tcase_add_test(tc, test_kata_sub_two_minus_one);
  suite_add_tcase(suite, tc);

  tc = tcase_create("test_kata_sub_three_minus_one");
  tcase_add_test(tc, test_kata_sub_three_minus_one);
  suite_add_tcase(suite, tc);

  tc = tcase_create("test_kata_sub_ten_minus_one");
  tcase_add_test(tc, test_kata_sub_ten_minus_one);
  suite_add_tcase(suite, tc);

  tc = tcase_create("test_kata_sub_hunded_minus_one");
  tcase_add_test(tc, test_kata_sub_hundred_minus_one);
  suite_add_tcase(suite, tc);

  tc = tcase_create("test_kata_sub_thousand_minus_one");
  tcase_add_test(tc, test_kata_sub_thousand_minus_one);
  suite_add_tcase(suite, tc);

  tc = tcase_create("test_kata_sub_lesser_before_bigger_minus_lesser");
  tcase_add_test(tc, test_kata_sub_lesser_before_bigger_minus_lesser);
  suite_add_tcase(suite, tc);

  tc = tcase_create("test_kata_sub_triple_minus_single");
  tcase_add_test(tc, test_kata_sub_triple_minus_single);
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
