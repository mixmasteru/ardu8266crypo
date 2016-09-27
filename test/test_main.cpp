#include <BigNumber.h>
#include <DiffieHellman.h>
#include "unity.h"

#ifdef UNIT_TEST

DiffieHellman dh;

// void setUp(void) {
// // set stuff up here
// }

// void tearDown(void) {
// // clean stuff up here
// }

void test_exchange(void) {

    TEST_ASSERT_EQUAL(32, dh.exchange("1234"));
}

void process() {
    UNITY_BEGIN();
    RUN_TEST(test_exchange);
    UNITY_END();
}


int main(int argc, char **argv) {
    process();
    return 0;
}

#endif
