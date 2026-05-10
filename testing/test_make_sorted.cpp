#include <cstdlib>
#include <vector>
#include "gtest/gtest.h"
#include "sorting.h"
#include "rapidcheck/gtest.h"
#include "test_helpers.h"

TEST(MakeSortedTests, SimpleSortSortedArray) {
    /*
     * Check that we can sort an array that is already sorted.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    int* result = make_sorted(arr, n);

    for (int i = 0; i < n; i++) {
        EXPECT_EQ(result[i], arr[i]);
    }

    free(result);

}

TEST(MakeSortedTests, SimpleSortReverseSortedArray) {
    /*
     * Check that we can sort an array that is reverse sorted order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    int* result = make_sorted(arr, n);

    for (int i = 0; i < n; i++) {
        EXPECT_EQ(result[i], arr[i]);
    }

    free(result);
}


TEST(MakeSortedTests, SimpleSortAverageArray) {
    /*
     * Check that we can sort an array where the elements in it are in random order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    int* result = make_sorted(arr, n);

    for (int i = 0; i < n; i++) {
        EXPECT_EQ(result[i], arr[i]);
    }

    free(result);
}

TEST(MakeSortedTests, SimpleSortArrayWithDuplicates) {
    /*
     * Check that we can sort an array where there are duplicate elements in it.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    int* result = make_sorted(arr, n);

    for (int i = 0; i < n; i++) {
        EXPECT_EQ(result[i], arr[i]);
    }

    free(result);
}

RC_GTEST_PROP(MakeSortedTests,
              PropertyAfterSortingValuesAreInAscendingOrder,
              ( std::vector<int> values)
) {
    /* Test that after sorting an array, the values are in ascending order
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int n = values.size();
    int* ar = values.data();
    int* result = get_sorted(ar, n);
    for (int i = 0; i < n - 1; i++) {
        RC_ASSERT(result[i] <= result[i + 1]);
    }
    free(result);
}
