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
    int already_sorted_array[] = {2, 4, 7, 8, 10};
    int expect[] = {2, 4, 7, 8, 10};
    int n = 5;

    make_sorted(already_sorted_array, n);

    for (int i = 0; i < n; i++) {
        EXPECT_EQ(already_sorted_array[i], expect[i]);
    }


}

TEST(MakeSortedTests, SimpleSortReverseSortedArray) {
    /*
     * Check that we can sort an array that is reverse sorted order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int reverse_sorted_array[] = {7, 3, 2, 1};
    int expected_result[] = {1, 2, 3, 7};
    int n = 4;

    make_sorted(reverse_sorted_array, n);

    for (int i = 0; i < n; i++) {
        EXPECT_EQ(reverse_sorted_array[i], expected_result[i]);
    }

}


TEST(MakeSortedTests, SimpleSortAverageArray) {
    /*
     * Check that we can sort an array where the elements in it are in random order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int randomly_sorted_array[] = {7, 2, 1, 3};
    int expected_result[] = {1, 2, 3, 7};
    int n = 4;

    make_sorted(randomly_sorted_array, n);

    for (int i = 0; i < n; i++) {
        EXPECT_EQ(randomly_sorted_array[i], expected_result[i]);
    }

}

TEST(MakeSortedTests, SimpleSortArrayWithDuplicates) {
    /*
     * Check that we can sort an array where there are duplicate elements in it.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int array_with_duplicates[] = {7, 7, 2, 1, 3};
    int expected_result[] = {1, 2, 3, 7, 7};
    int n = 4;

    make_sorted(array_with_duplicates, n);

    for (int i = 0; i < n; i++) {
        EXPECT_EQ(array_with_duplicates[i], expected_result[i]);
    }

}

RC_GTEST_PROP(MakeSortedTests,
              PropertyAfterSortingValuesAreInAscendingOrder,
              ( std::vector<int> values)
) {
    /* Test that after sorting an array, the values are in ascending order
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

    int n = values.size();
    std::vector<int> ascending_order_array = values;
    int* result = make_sorted(ascending_order_array.data(), n);
    for (int i = 0; i < n - 1; i++) {
        RC_ASSERT(result[i] <= result[i + 1]);
    }

}
