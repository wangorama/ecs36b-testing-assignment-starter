#include <cstdlib>
#include <vector>
#include <algorithm>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "sorting.h"
#include "test_helpers.h"
#include "rapidcheck/gtest.h"

TEST(CopyArrayTests, SimpleValuesAreSame) {
    /*
     * Check that the values in the copy are the same as the values in the original array.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int original[] = {2, 3, 6 , 7};
    int snap[] = {2, 3, 6 , 7};
    int n = 4;
    int* result = copy_array(original, n);
    for (int i = 0; i < n; i++) {
        EXPECT_EQ(original[i], snap[i]);
    }
    free(result);

}

TEST(CopyArrayTests, SimpleOriginalDoesNotChange) {
    /*
     * Check that the  values in the original array did not change.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int original[] = {2, 3, 6 , 7};
    int snap[] = {2, 3, 6 , 7};
    int n = 4;
    int* result = copy_array(original, n);
    for (int i = 0; i < n; i++) {
        EXPECT_EQ(original[i], snap[i]);
    }
    free(result);

}

TEST(CopyArrayTests, SimpleCopyWasMade) {
    /*
     * Check that a copy was actually made
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int simple_array[] = {7, 6, 3 ,6, 2};
    int n = 5;
    int* result = copy_array(simple_array, n);
    EXPECT_NE(result, simple_array);
    free(result);


}


RC_GTEST_PROP(CopyArrayTests,
              PropertyValuesAreSame,
              (const std::vector<int>& values)
) {
    /*
     * Check that the values in the copy are the same as the values in the original array.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int n = values.size();
    std::vector<int> generated_array(values);
    int* result = copy_array(generated_array.data(), n);
    for (int i = 0; i < n; i++) {
        RC_ASSERT(result[i] == generated_array[i]);
    }
    free(result);


}

RC_GTEST_PROP(CopyArrayTests,
              PropertyOriginalDoesNotChange,
              (const std::vector<int>&values)
) {
    /*
     * Check that the  values in the original array did not change.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int n = values.size();
    const std::vector<int> original_array(values);
    std::vector<int> copy_original(values);
    int* result = copy_array(copy_original.data(), n);
    for (int i = 0; i < n; i++) {
        RC_ASSERT(original_array[i] == copy_original[i]);
    }
    free(result);

}

RC_GTEST_PROP(CopyArrayTests,
              PropertyCopyWasMade,
              (const std::vector<int>&values)
) {
    /*
  * Check that a copy was actually made
  * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
  * Don't forget to free any memory that was dynamically allocated as part of your test.
  */
    int n = values.size();
    std::vector<int> ar (values);
    int* result = copy_array(ar.data(), n);
    RC_ASSERT(result != ar.data());
    free(result);


}



