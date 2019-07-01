#ifndef __CLOVER_TEST_H__
#define __CLOVER_TEST_H__

#include <cassert>

namespace clover {
    namespace test {
        inline void ensure(bool cond) {
            assert(cond);
            if (!cond) {
                throw "fail";
            }
        }

        template <typename T>
        class TestCase {
        public:
            TestCase() {
                run();
            }

            void ensure(bool cond) {
                clover::test::ensure(cond);
            }
            void run();
        };

#define __CLOVER_TEST_CONCATENATE_IMPL(s1, s2) s1##s2
#define __CLOVER_TEST_CONCATENATE(s1, s2) __CLOVER_TEST_CONCATENATE_IMPL(s1, s2)

#define __CLOVER_TEST(ClassName)                                                       \
    namespace {                                                                        \
        struct ClassName;                                                              \
    }                                                                                  \
    static clover::test::TestCase<ClassName> __CLOVER_TEST_CONCATENATE(s_, ClassName); \
    template <>                                                                        \
    void clover::test::TestCase<ClassName>::run()

#define CLOVER_TEST __CLOVER_TEST(__CLOVER_TEST_CONCATENATE(CLOVER_TEST_NAME, __LINE__))
    } // namespace test
} // namespace clover

#endif
