#include <vector>
#include <algorithm>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "rapidcheck/gtest.h"
#include "sorting.h"

TEST(MinIndexOfArrayTests, SimpleMinIndexAtFrontOfArray) {
    /*
     * See if we can find the index of the minimum value when it is at the front of the array
     */
    int test_minimum_array [] = {4,5,6,7,8,9,10};
    int n = 6;

    int result = min_index_of_array(test_minimum_array, n);

    EXPECT_EQ(result, 0);

}

TEST(MinIndexOfArrayTests, SimpleMinIndexAtEndOfArray) {
    /*
     * See if we can find the index of the minimum value when it is at the end of the array
     */
    int test_minimum_array [] = {5,6,7,8,9,10,4};
    int n = 6;

    int result = min_index_of_array(test_minimum_array, n);

    EXPECT_EQ(result, 6);
}

TEST(MinIndexOfArrayTests, SimpleMinIndexAtMiddleOfArray) {
    /*
     * See if we can find the index of the minimum value when it is somewhere
     * in the "middle" of the array.
     */
    int test_minimum_array [] = {5,6,7,4,8,9,10};
    int n = 6;

    int result = min_index_of_array(test_minimum_array, n);

    EXPECT_EQ(result, 3);
}

TEST(MinIndexOfArrayTests, SimpleDuplicateMinimums) {
    /*
     * See if we return the index of the first minimum in the array
     * When there are multiple values that are the minimum.
     */
    int test_minimum_array [] = {4,5,6,4,7,8,10};
    int n = 6;

    int result = min_index_of_array(test_minimum_array, n);

    EXPECT_EQ(result, 0);
}

TEST(MinIndexOfArrayTests, SimpleArrayDoesNotChange) {
    /*
     * Check that finding the minimum of the array did not change the contents of the array.
     */

    int test_minimum_array [] = {4,5,6,7,8,9,10};
    int n = 6;
    int copy_of_test_array [] = {4,5,6,7,8,9,10};

    min_index_of_array(test_minimum_array, n);

    for (int i = 0; i < n; i++) {
        EXPECT_EQ(test_minimum_array[i], copy_of_test_array[i]);
    }

}


RC_GTEST_PROP(MinIndexOfArrayTests,
              PropertyFindMinIndex,
              ()) {
    /* Check that the value at the location of the minimum index
     * is not larger than any of the other values in the array
     */
    auto rc_vector =  *rc::gen::nonEmpty(rc::gen::container<std::vector<int>>(rc::gen::arbitrary<int>()));

    int result = min_index_of_array(rc_vector.data(), rc_vector.size());

    for (int i = 0; i < (int)rc_vector.size(); i++) {
        EXPECT_EQ(result, rc_vector[i]);
    }


}

RC_GTEST_PROP(MinIndexOfArrayTests,
              PropertyArrayDoesNotChange,
              ()) {
    /*
     * Check that finding the minimum of the array did not change the contents of the array.
     */
    auto rc_vector = *rc::gen::container<std::vector<int>>(rc::gen::arbitrary<int>());

    int result = min_index_of_array(rc_vector.data(), rc_vector.size());

    for (int i = 0; i < (int)rc_vector.size() ; i++) {
        EXPECT_EQ(result, rc_vector[i]);
    }

}
