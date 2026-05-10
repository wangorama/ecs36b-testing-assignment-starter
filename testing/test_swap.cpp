#include <cstdlib>
#include <vector>
#include <algorithm>
#include "test_helpers.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "sorting.h"
#include "rapidcheck/gtest.h"

TEST(SwapTests, SimpleSwapTwoValues) {
    /*
     * Swap two values and see if the swap was successful.
     */
    int a = 1, b = 2;
    std::swap(a, b);
    EXPECT_EQ(a, 2);
    EXPECT_EQ(b, 1);

}

TEST(SwapTests, SimpleSwapValuesInArray) {
    /*
     * Swap a few values in an array.
     * Check that the ones that swapped did swap and the ones that didn't swap
     * are still at the same locations
     */
    std::vector<int> vector;
    vector[0] = 1;
    vector[1] = 2;
    std::swap (vector[0], vector[1]);
    EXPECT_EQ(vector[0], 2);
    EXPECT_EQ(vector[1], 1);

}

RC_GTEST_PROP(SwapTests,
              PropertySwapTwoValues,
              (int a_start, int b_start)
) {
    /*
     * Swap two values and see if the swap was successful.
     */
    int &a = a_start;
    int &b = b_start;
    std::swap(a, b);
    EXPECT_EQ(a, b_start);
    EXPECT_EQ(b, a_start);
}


RC_GTEST_PROP(SwapTests,
              PropertySwapValuesInArray,
              (const std::vector<int>& values)
) {
    /*
     * Swap two values in an array. See that they swapped and the others did not
     */

    std::vector<int> arr = values;
    std::swap(arr[0], arr[1]);

    // The swapped positions should have exchanged values
    EXPECT_EQ(arr[0], values[1]);
    EXPECT_EQ(arr[1], values[0]);

    // All other elements should be unchanged
    for (size_t i = 2; i < arr.size(); i++) {
        EXPECT_EQ(arr[i], values[i]);
    }


}
