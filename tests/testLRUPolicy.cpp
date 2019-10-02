//
// Created by thomas on 02/10/2019.
//

#include <gtest/gtest.h>
#include "../vmPrism/LRUPolicy.h"

TEST( LRUPolicy, BaseRunning ) {
    std::vector<size_t> refList =
            { 1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3, 6, 1, 2, 4, 3 };
    size_t cacheSize = 3;
    LRU cal(cacheSize, refList);

    ASSERT_FLOAT_EQ( 0.45, cal.hit_ratio() );
    ASSERT_FLOAT_EQ( 0.55, cal.miss_ratio() );
    ASSERT_FLOAT_EQ( 11, cal.page_fault() );
}