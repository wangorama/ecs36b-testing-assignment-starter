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
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    int* result = min_index_of_array(arr, n);

    for (int i = 0; i < n; i++) {
        EXPECT_EQ(result[i], arr[i]);
    }

    free(result);

}

TEST(MinIndexOfArrayTests, SimpleMinIndexAtEndOfArray) {
    /*
     * See if we can find the index of the minimum value when it is at the end of the array
     */
}

TEST(MinIndexOfArrayTests, SimpleMinIndexAtMiddleOfArray) {
    /*
     * See if we can find the index of the minimum value when it is somewhere
     * in the "middle" of the array.
     */
}

TEST(MinIndexOfArrayTests, SimpleDuplicateMinimums) {
    /*
     * See if we return the index of the first minimum in the array
     * When there are multiple values that are the minimum.
     */
}

TEST(MinIndexOfArrayTests, SimpleArrayDoesNotChange) {
    /*
     * Check that finding the minimum of the array did not change the contents of the array.
     */
}


RC_GTEST_PROP(MinIndexOfArrayTests,
              PropertyFindMinIndex,
              ()) {
    /* Check that the value at the location of the minimum index
     * is not larger than any of the other values in the array
     */
    int n = values.size();
    int* ar = values.data();
    int* result = get_sorted(ar, n);
    for (int i = 0; i < n - 1; i++) {
        RC_ASSERT(result[i] <= result[i + 1]);
    }
    free(result);
}

RC_GTEST_PROP(MinIndexOfArrayTests,
              PropertyArrayDoesNotChange,
              ()) {
    /*
     * Check that finding the minimum of the array did not change the contents of the array.
     */
    int n = values.size();
    int* ar = values.data();
    int* result = get_sorted(ar, n);
    for (int i = 0; i < n - 1; i++) {
        RC_ASSERT(result[i] <= result[i + 1]);
    }
    free(result);
}
