#include "Ref.h"
#include <iostream>
#include "CloverTest.h"
#include "ScopeGuard.h"
#include "FlatMap.h"
#include "intrusive_ptr.h"

CLOVER_TEST {
    void *p = nullptr;
    {
        p = malloc(1000);
        ON_SCOPE_EXIT {
            free(p);
            p = nullptr;
        };
    }
    ensure(p == nullptr);
}

CLOVER_TEST {
    typedef clover::FlatMap<uint32_t, std::string, 11> MapType;
    MapType::Item items[] = {
        {2, "2"},
        {1, "1"},
        {4, "4"},
    };

    MapType testMap;
    testMap.init(items);

    auto iter = testMap.find(1);
    ensure(iter != testMap.end() && iter->first == 1 && iter->second == "1");

    iter = testMap.find(4);
    ensure(iter != testMap.end() && iter->first == 4 && iter->second == "4");

    iter = testMap.find(3);
    ensure(iter == testMap.end());
}

class Test : public clover::Ref<Test> {
public:
    ~Test() {
        printf("Test::~Test()\n");
    }
};

CLOVER_TEST {
    auto test = clover::makeRef<Test>();
    auto test2 = clover::makeRef<Test>();
}

int main(int argc, const char *argv[]) {

    return 0;
}
