# Google Test And Debugging Writeup

## Things I Thought To Test
1. `swap`
2. `copy_array`
3. `min_index_of_array`
4. `make_sorted`
5. `get_sorted`
6. `parse_args`

## Bugs

### Bug 1

### swap.cpp

Line 17

```c++
void make_sorted(int* ar, int len) {
  /**
 * Sort the given array in place.
 * @param ar: The array to be sorted.
 * @param len: The length of the array to be sorted.
 */
  for (int i = 0; i < len; ++i) {
    int min_index = min_index_of_array(ar + i, len);
    swap(ar + i, ar + min_index);
  }
}
```

### How the bug was located

The bug was found through testing make_sorted. 

### Description

A mismatch of the header file versus what the main file actually declared.


### Fix 

I changed the type from void to int.

```c++
int *make_sorted(int* ar, int len) {
  /**
 * Sort the given array in place.
 * @param ar: The array to be sorted.
 * @param len: The length of the array to be sorted.
 */
  for (int i = 0; i < len; ++i) {
    int min_index = min_index_of_array(ar + i, len);
    swap(ar + i, ar + min_index);
  }
  return ar;
}

```

### Bug 2

### main.cpp

Line 16

```c++
    parse_args(argc, argv, given_numbers, &len);
```

### How the bug was located

testing parse args through a simple test was enough to catch the bug.
### Description

given_numbers was not initialized.

### Fix

Initialized it

```c++
 int* given_numbers = nullptr;
```

