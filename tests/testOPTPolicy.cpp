//
// Created by thomas on 02/10/2019.
//

#include <gtest/gtest.h>
#include "../vmPrism/OPTPolicy.h"

TEST( OPTPolicy, BaseRunning ) {
    std::vector<size_t> refList =
            { 1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3, 6, 1, 2, 4, 3 };
    size_t cacheSize = 3;
    OPT cal(cacheSize, refList);

    ASSERT_FLOAT_EQ( 0.55000001, cal.hit_ratio() );
    ASSERT_FLOAT_EQ( 0.44999999, cal.miss_ratio() );
    ASSERT_FLOAT_EQ( 9, cal.page_fault() );
}