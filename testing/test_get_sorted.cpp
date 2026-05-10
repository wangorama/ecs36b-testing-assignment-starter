#include <cstdlib>
#include "gtest/gtest.h"
#include "sorting.h"
#include "test_helpers.h"
#include "rapidcheck/gtest.h"

TEST(GetSortedTests, SimpleSortSortedArray) {
    /*
     * Check that we can sort an array that is already sorted.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int simple_array[] = {2, 3, 6 , 7};
    int n = 4;
    int* result = get_sorted(simple_array, n);
    for (int i = 0; i < n; i++) {
        EXPECT_EQ(simple_array[i], result[i]);
    }
    free(result);
}

TEST(GetSortedTests, SimpleSortReverseSortedArray) {
    /*
     * Check that we can sort an array that is reverse sorted order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int simple_array[] = {2, 3, 6 , 7};
    int reverse_simple_array[] = {7, 6, 3 , 2};
    int n = 4;
    int* result = get_sorted(simple_array, n);
    for (int i = 0; i < n; i++) {
        EXPECT_EQ(reverse_simple_array[i], result[i]);
    }
    free(result);


}

TEST(GetSortedTests, SimpleSortAverageArray) {
    /*
     * Check that we can sort an array where the elements in it are in random order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int simple_array[] = {2, 7, 3, 6, 4};
    int average_random_simple_array[] = {2, 3, 4, 6, 7};
    int n = 5;
    int* result = get_sorted(simple_array, n);
    for (int i = 0; i < n; i++) {
        EXPECT_EQ(average_random_simple_array[i], result[i]);
    }
    free(result);



}

TEST(GetSortedTests, SimpleSortArrayWithDuplicates) {
    /*
     * Check that we can sort an array where there are duplicate elements in it.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int simple_array[] = {2, 3, 6 , 7, 6};
    int reverse_simple_array[] = {7, 6, 3 ,6, 2};
    int n = 5;
    int* result = get_sorted(reverse_simple_array, n);
    for (int i = 0; i < n; i++) {
        EXPECT_EQ(simple_array[i], result[i]);
    }
    free(result);



}

TEST(GetSortedTests, SimpleOriginalDoesNotChange) {
    /*
     * Check that the original array was not modified.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int original[] = {2, 3, 6 , 7};
    int snap[] = {2, 3, 6 , 7};

    int n = 4;
    for (int i = 0; i < n; i++) {
        EXPECT_EQ(original[i], snap[i]);
    }

}

TEST(GetSortedTests, SimpleCopyWasMade) {
    /*
     * Check that the sorted array is copy of the original array in sorted order.
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int simple_array[] = {7, 6, 3 ,6, 2};
    int n = 5;
    int* result = get_sorted(simple_array, n);
    EXPECT_NE(result, simple_array);
    free(result);

}


RC_GTEST_PROP(GetSortedTests,
              PropertyAfterSortingValuesAreInAscendingOrder,
              ( std::vector<int> values)
) {
    /* Check that after sorting an array, the values are in ascending order
     * Don't forget to free any memory that was dynamically allocated as part of this test
     */
    int n = values.size();
    int* ascending_order_array = values.data();
    int* result = get_sorted(ascending_order_array, n);
    for (int i = 0; i < n - 1; i++) {
        RC_ASSERT(result[i] <= result[i + 1]);
    }
    free(result);


}

RC_GTEST_PROP(GetSortedTests,
              PropertyOriginalDoesNotChange,
              (const std::vector<int>&values)
) {
    /*
     * Check that the original array was not modified.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int n = values.size();
    int* ar = values.data();
    int* result = get_sorted(ar, n);
    for (int i = 0; i < n - 1; i++) {
        RC_ASSERT(result[i] <= result[i + 1]);
    }
    free(result);
    ;
}

RC_GTEST_PROP(GetSortedTests,
              PropertyCopyWasMade,
              (const std::vector<int>&values)
) {
    /*
     * Check that the sorted array is copy of the original array in sorted order.
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int n = values.size();
    int* result = get_sorted(ar, n);
    for (int i = 0; i < n - 1; i++) {
        RC_ASSERT(result[i] <= result[i + 1]);
    }
    free(result);

}











