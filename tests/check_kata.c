#include <stdlib.h>
#include <check.h>
#include "../src/kata.h"

START_TEST(test_kata_atoi)
{
  ck_assert_int_eq(kata_atoi("I"), 1);
}
END_TEST

START_TEST(test_kata_itoa)
{
  char resbuf[KATA_MAXLEN];
  ck_assert_str_eq(kata_itoa(1, resbuf), "I");
}
END_TEST

Suite *
kata_all(void)
{
  Suite *suite;
  TCase *tc;

  suite = suite_create("kata");

  tc = tcase_create("all");
  tcase_add_test(tc, test_kata_atoi);
  suite_add_tcase(suite, tc);

  tc = tcase_create("all_b");
  tcase_add_test(tc, test_kata_itoa);
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
