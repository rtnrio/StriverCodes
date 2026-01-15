// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
// Check if an array is sorted in non-decreasing order and rotated at most once.
#include <vector>
using namespace std;
class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            // Compare each element with the next one (wrap around at the end)
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }

            // If the order breaks more than once, it’s not sorted and rotated
            // One break is allowed because it represents the rotation point
            if (count > 1) return false;
        }

        return true;
    }
};

/*
# Intuition:
A sorted and rotated array looks like a sorted array that was "cut" once and
the two parts were swapped. For example:
   Sorted:  [1, 2, 3, 4, 5]
   Rotated: [3, 4, 5, 1, 2]

Because of this cut, there is exactly ONE place where the order decreases
(e.g., 5 → 1). That single decrease represents the rotation point.

# Why not check `count > 0`?
- A fully sorted array has 0 drops.
- A sorted and rotated array has exactly 1 drop.
- If we checked `count > 0`, valid rotated arrays would be rejected.
- Therefore, we only return false when the drop happens more than once.

# Approach:
1. Traverse the array once.
2. Count how many times an element is greater than the next element.
   - Use `(i + 1) % n` to compare the last element with the first (circular check).
3. If this count becomes greater than 1, return false.
4. Otherwise, return true.

# Example:
   Input: [3, 4, 5, 1, 2]
   Steps:
     3 < 4  ✅
     4 < 5  ✅
     5 > 1  ❌ (count = 1)
     1 < 2  ✅
     2 < 3  ✅
   Only one drop → return true

# Time Complexity: O(n)
   Each element is checked once.

# Space Complexity: O(1)
   Only constant extra space is used.
*/
