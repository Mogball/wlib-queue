#ifndef __WLIB_QUEUE_DEFS_H__
#define __WLIB_QUEUE_DEFS_H__

#include <wlib/queue>

extern "C" int printf(const char *msg, ...);

#define STRINGIFY_(x) #x
#define STRINGIFY(x) STRINGIFY_(x)

#define ASSERT_TRUE(stmt)           \
    if (false == (stmt)) {          \
        printf("\tFailed at line %d: %s\n", \
            __LINE__, STRINGIFY(stmt));     \
        return false; }

#define DEFINE_TEST(x) \
static bool test_##x(void)

#define RUN_TEST(x)                 \
    printf("Test %d\n", x);         \
    if (false == test_##x()) {      \
        printf("-> Failed\n");      \
        return -1; }                \
    printf("-> Passed\n");

typedef wlp::queue<int, 16> tqueue_t;

#endif
