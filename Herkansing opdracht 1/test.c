
#include <stdio.h>
#include "munit.h"
#include "cli.h"
/* This is just to disable an MSVC warning about conditional
 * expressions being constant, which you shouldn't have to do for your
 * code.  It's only here because we want to be able to do silly things
 * like assert that 0 != 1 for our demo. */
#if defined(_MSC_VER)
#pragma warning(disable: 4127)
#endif


static MunitResult
test_command_parameters_should_return_default_value(const MunitParameter params[], void* user_data){
    (void) params;
    (void) user_data;

    char *bogus = NULL;
    parameters result_value = command_parameters(bogus);
    char* command = result_value.command;
    int value = result_value.value;
    char* color = result_value.color;
    bool exact = result_value.exact;
    bool valid = result_value.valid;
    munit_assert_false(exact);
    munit_assert_int(exact, ==, 1);
    munit_assert_ptr_equal(color, NULL);
    munit_assert_int(value, ==, -1);
    munit_assert_false(valid);
    return MUNIT_OK;
}

static MunitResult
test_command_parameters_rood_one_should_return_valid_parameter(const MunitParameter params[], void* user_data){
    (void) params;
    (void) user_data;

    char *rood = "rood 1";
    parameters result_value = command_parameters(rood);
    char* command = result_value.command;
    int value = result_value.value;
    char* color = result_value.color;
    bool exact = result_value.exact;
    bool valid = result_value.valid;
    munit_assert_true(exact);
    munit_assert_string_equal(color, "rood");
    munit_assert_int(value, ==, 1);
    munit_assert_true(valid);
    return MUNIT_OK;
}

static MunitResult
test_command_parameters_rood_zero_should_return_valid_parameter(const MunitParameter params[], void* user_data){
    (void) params;
    (void) user_data;

    char *rood = "rood 0";
    parameters result_value = command_parameters(rood);
    char* command = result_value.command;
    int value = result_value.value;
    char* color = result_value.color;
    bool exact = result_value.exact;
    bool valid = result_value.valid;
    munit_assert_true(exact);
    munit_assert_string_equal(color, "rood");
    munit_assert_int(value, ==, 0);
    munit_assert_true(valid);
    return MUNIT_OK;
}

static MunitResult
test_command_parameters_groen_one_should_return_valid_parameter(const MunitParameter params[], void* user_data){
    (void) params;
    (void) user_data;

    char *rood = "groen 1";
    parameters result_value = command_parameters(rood);
    char* command = result_value.command;
    int value = result_value.value;
    char* color = result_value.color;
    bool exact = result_value.exact;
    bool valid = result_value.valid;
    munit_assert_true(exact);
    munit_assert_string_equal(color, "groen");
    munit_assert_int(value, ==, 1);
    munit_assert_true(valid);
    return MUNIT_OK;
}

static MunitResult
test_command_parameters_groen_zero_should_return_valid_parameter(const MunitParameter params[], void* user_data){
    (void) params;
    (void) user_data;

    char *rood = "groen 0";
    parameters result_value = command_parameters(rood);
    char* command = result_value.command;
    int value = result_value.value;
    char* color = result_value.color;
    bool exact = result_value.exact;
    bool valid = result_value.valid;
    munit_assert_true(exact);
    munit_assert_string_equal(color, "groen");
    munit_assert_int(value, ==, 0);
    munit_assert_true(valid);
    return MUNIT_OK;
}

static MunitResult
test_command_parameters_geel_one_should_return_valid_parameter(const MunitParameter params[], void* user_data){
    (void) params;
    (void) user_data;

    char *rood = "geel 1";
    parameters result_value = command_parameters(rood);
    char* command = result_value.command;
    int value = result_value.value;
    char* color = result_value.color;
    bool exact = result_value.exact;
    bool valid = result_value.valid;
    munit_assert_true(exact);
    munit_assert_string_equal(color, "geel");
    munit_assert_int(value, ==, 1);
    munit_assert_true(valid);
    return MUNIT_OK;
}

static MunitResult
test_command_parameters_geel_zero_should_return_valid_parameter(const MunitParameter params[], void* user_data){
    (void) params;
    (void) user_data;

    char *rood = "geel 0";
    parameters result_value = command_parameters(rood);
    char* command = result_value.command;
    int value = result_value.value;
    char* color = result_value.color;
    bool exact = result_value.exact;
    bool valid = result_value.valid;
    munit_assert_true(exact);
    munit_assert_string_equal(color, "geel");
    munit_assert_int(value, ==, 0);
    munit_assert_true(valid);
    return MUNIT_OK;
}

static MunitResult
test_command_parameters_led_naam_waarde_should_return_valid_parameter(const MunitParameter params[], void* user_data){
    (void) params;
    (void) user_data;

    char *rood = "led groen 0";
    parameters result_value = command_parameters(rood);
    char* command = result_value.command;
    int value = result_value.value;
    char* color = result_value.color;
    int exact = result_value.exact;
    bool valid = result_value.valid;
    munit_assert_int(exact, ==, 1);
    munit_assert_string_equal(color, "groen");
    munit_assert_int(value, ==, 0);
    munit_assert_true(valid);
    return MUNIT_OK;
}

static MunitResult
test_command_parameters_led_naam_waarde_should_return_invalid_parameter(const MunitParameter params[], void* user_data){
    (void) params;
    (void) user_data;

    char *rood = "led green 0";
    parameters result_value = command_parameters(rood);
    char* command = result_value.command;
    int value = result_value.value;
    char* color = result_value.color;
    int exact = result_value.exact;
    bool valid = result_value.valid;
    munit_assert_int(exact, ==, 1);
    munit_assert_string_equal(color, "green");
    munit_assert_int(value, ==, 0);
    munit_assert_false(valid);
    return MUNIT_OK;
}


static MunitResult
test_int_value_invalid_value_should_return_minus_one(const MunitParameter params[], void* user_data){
    (void) params;
    (void) user_data;

    char *bogus = "hello";
    int result_value = int_value(bogus);
    munit_assert_int(result_value, ==, -1);
    return MUNIT_OK;
}

static MunitResult
test_int_value_zero_value_should_return_zero(const MunitParameter params[], void* user_data){
    (void) params;
    (void) user_data;

    char *bogus = "0";
    int result_value = int_value(bogus);
    munit_assert_int(result_value, ==, 0);
    return MUNIT_OK;
}

static MunitResult
test_int_value_one_value_should_return_one(const MunitParameter params[], void* user_data){
    (void) params;
    (void) user_data;

    char *bogus = "1";
    int result_value = int_value(bogus);
    munit_assert_int(result_value, ==, 1);
    return MUNIT_OK;
}

static MunitResult
test_int_value_two_value_should_return_two(const MunitParameter params[], void* user_data){
    (void) params;
    (void) user_data;

    char *bogus = "2";
    int result_value = int_value(bogus);
    munit_assert_int(result_value, ==, 2);
    return MUNIT_OK;
}

static MunitResult
test_int_value_three_value_should_return_three(const MunitParameter params[], void* user_data){
    (void) params;
    (void) user_data;

    char *bogus = "3";
    int result_value = int_value(bogus);
    munit_assert_int(result_value, ==, 3);
    return MUNIT_OK;
}

static MunitResult
test_int_value_four_value_should_return_four(const MunitParameter params[], void* user_data){
    (void) params;
    (void) user_data;

    char *bogus = "4";
    int result_value = int_value(bogus);
    munit_assert_int(result_value, ==, 4);
    return MUNIT_OK;
}


static MunitResult
test_int_value_five_value_should_return_five(const MunitParameter params[], void* user_data){
    (void) params;
    (void) user_data;

    char *bogus = "5";
    int result_value = int_value(bogus);
    munit_assert_int(result_value, ==, 5);
    return MUNIT_OK;
}

static MunitResult
test_int_value_six_value_should_return_six(const MunitParameter params[], void* user_data){
    (void) params;
    (void) user_data;

    char *bogus = "6";
    int result_value = int_value(bogus);
    munit_assert_int(result_value, ==, 6);
    return MUNIT_OK;
}


static MunitResult
test_int_value_seven_value_should_return_seven(const MunitParameter params[], void* user_data){
    (void) params;
    (void) user_data;

    char *bogus = "7";
    int result_value = int_value(bogus);
    munit_assert_int(result_value, ==, 7);
    return MUNIT_OK;
}


static MunitResult
test_command_parameters_should_return_command_value(const MunitParameter params[], void* user_data){
    (void) params;
    (void) user_data;

    char *bogus = "bogus";
    parameters result_value = command_parameters(bogus);
    char* command = result_value.command;
    int value = result_value.value;
    char* color = result_value.color;
    int exact = result_value.exact;
    munit_assert_ptr_not_equal(command, NULL);
    munit_assert_int(value, ==, -1);
    munit_assert_ptr_equal(color, NULL);
    munit_assert_int(exact, ==, 1);
    return MUNIT_OK;
}
// /* The setup function, if you provide one, for a test will be run
//  * before the test, and the return value will be passed as the sole
//  * parameter to the test function. */
// static void*
// test_compare_setup(const MunitParameter params[], void* user_data) {
//   (void) params;

// //   munit_assert_string_equal(user_data, "µnit");
//   return (void*) (uintptr_t) 0xdeadbeef;
// }

// /* To clean up after a test, you can use a tear down function.  The
//  * fixture argument is the value returned by the setup function
//  * above. */
// static void
// test_compare_tear_down(void* fixture) {
//   munit_assert_ptr_equal(fixture, (void*)(uintptr_t)0xdeadbeef);
// }


/* Creating a test suite is pretty simple.  First, you'll need an
 * array of tests: */
static MunitTest test_suite_tests[] = {
//   {
//     /* The name is just a unique human-readable way to identify the
//      * test. You can use it to run a specific test if you want, but
//      * usually it's mostly decorative. */
//     (char*) "/example/compare",
//     /* You probably won't be surprised to learn that the tests are
//      * functions. */
//     test_compare,
//     /* If you want, you can supply a function to set up a fixture.  If
//      * you supply NULL, the user_data parameter from munit_suite_main
//      * will be used directly.  If, however, you provide a callback
//      * here the user_data parameter will be passed to this callback,
//      * and the return value from this callback will be passed to the
//      * test function.
//      *
//      * For our example we don't really need a fixture, but lets
//      * provide one anyways. */
//     test_compare_setup,
//     /* If you passed a callback for the fixture setup function, you
//      * may want to pass a corresponding callback here to reverse the
//      * operation. */
//     test_compare_tear_down,
//     /* Finally, there is a bitmask for options you can pass here.  You
//      * can provide either MUNIT_TEST_OPTION_NONE or 0 here to use the
//      * defaults. */
//     MUNIT_TEST_OPTION_NONE,
//     NULL
//   },
  { (char*) "/cli/command_parameters/default_value", test_command_parameters_should_return_default_value, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
   { (char*) "/cli/command_parameters/command_value", test_command_parameters_should_return_command_value, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
   { (char*) "/cli/command_parameters/rood_value_one", test_command_parameters_rood_one_should_return_valid_parameter, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
   { (char*) "/cli/command_parameters/rood_value_zero", test_command_parameters_rood_zero_should_return_valid_parameter, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
   { (char*) "/cli/command_parameters/groen_value_one", test_command_parameters_groen_one_should_return_valid_parameter, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
   { (char*) "/cli/command_parameters/groen_value_zero", test_command_parameters_groen_zero_should_return_valid_parameter, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
   { (char*) "/cli/command_parameters/geel_value_one", test_command_parameters_geel_one_should_return_valid_parameter, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
   { (char*) "/cli/command_parameters/geel_value_zero", test_command_parameters_geel_zero_should_return_valid_parameter, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
   { (char*) "/cli/command_parameters/led_naam_waarde", test_command_parameters_led_naam_waarde_should_return_valid_parameter, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
   { (char*) "/cli/command_parameters/led_naam_waarde_invalid", test_command_parameters_led_naam_waarde_should_return_invalid_parameter, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
   { (char*) "/cli/int_value/invalid_value", test_command_parameters_rood_zero_should_return_valid_parameter, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
   { (char*) "/cli/int_value/zero_value", test_int_value_zero_value_should_return_zero, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
   { (char*) "/cli/int_value/one_value", test_int_value_zero_value_should_return_zero, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
   { (char*) "/cli/int_value/two_value", test_int_value_one_value_should_return_one, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
   { (char*) "/cli/int_value/three_value", test_int_value_three_value_should_return_three, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
   { (char*) "/cli/int_value/four_value", test_int_value_four_value_should_return_four, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
   { (char*) "/cli/int_value/five_value", test_int_value_five_value_should_return_five, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
   { (char*) "/cli/int_value/six_value", test_int_value_six_value_should_return_six, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
   { (char*) "/cli/int_value/seven_value", test_int_value_seven_value_should_return_seven, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  /* To tell the test runner when the array is over, just add a NULL
   * entry at the end. */
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

/* If you wanted to have your test suite run other test suites you
 * could declare an array of them.  Of course each sub-suite can
 * contain more suites, etc. */
/* static const MunitSuite other_suites[] = { */
/*   { "/second", test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE }, */
/*   { NULL, NULL, NULL, 0, MUNIT_SUITE_OPTION_NONE } */
/* }; */

/* Now we'll actually declare the test suite.  You could do this in
 * the main function, or on the heap, or whatever you want. */
static const MunitSuite test_suite = {
  /* This string will be prepended to all test names in this suite;
   * for example, "/example/rand" will become "/µnit/example/rand".
   * Note that, while it doesn't really matter for the top-level
   * suite, NULL signal the end of an array of tests; you should use
   * an empty string ("") instead. */
  (char*) "",
  /* The first parameter is the array of test suites. */
  test_suite_tests,
  /* In addition to containing test cases, suites can contain other
   * test suites.  This isn't necessary in this example, but it can be
   * a great help to projects with lots of tests by making it easier
   * to spread the tests across many files.  This is where you would
   * put "other_suites" (which is commented out above). */
  NULL,
  /* An interesting feature of µnit is that it supports automatically
   * running multiple iterations of the tests.  This is usually only
   * interesting if you make use of the PRNG to randomize your tests
   * cases a bit, or if you are doing performance testing and want to
   * average multiple runs.  0 is an alias for 1. */
  1,
  /* Just like MUNIT_TEST_OPTION_NONE, you can provide
   * MUNIT_SUITE_OPTION_NONE or 0 to use the default settings. */
  MUNIT_SUITE_OPTION_NONE
};

/* This is only necessary for EXIT_SUCCESS and EXIT_FAILURE, which you
 * *should* be using but probably aren't (no, zero and non-zero don't
 * always mean success and failure).  I guess my point is that nothing
 * about µnit requires it. */
#include <stdlib.h>

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  /* Finally, we'll actually run our test suite!  That second argument
   * is the user_data parameter which will be passed either to the
   * test or (if provided) the fixture setup function. */
  return munit_suite_main(&test_suite, (void*) "µnit", argc, argv);
}