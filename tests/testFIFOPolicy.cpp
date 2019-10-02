//
// Created by thomas on 01/10/2019.
//

#include <gtest/gtest.h>
#include "../vmPrism/FIFOPolicy.h"

TEST( FIFOPolicy, BaseRunning ) {
    std::vector<size_t> refList =
            { 1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3, 6, 1, 2, 4, 3 };
    size_t cacheSize = 3;
    FIFO cal(cacheSize, refList);

    ASSERT_FLOAT_EQ( 0.3, cal.hit_ratio() );
    ASSERT_FLOAT_EQ( 0.7, cal.miss_ratio() );
    ASSERT_FLOAT_EQ( 14, cal.page_fault() );
}