// Question-
// https://leetcode.com/problems/sort-colors/

// Solution-

#include <vector>
using namespace std;

// Question:
// https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c0 = 0, c1 = 0, c2 = 0;

        // Count number of 0s, 1s and 2s
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)      c0++;
            else if (nums[i] == 1) c1++;
            else                   c2++;
        }

        // Place all 0s
        for (int i = 0; i < c0; i++) {
            nums[i] = 0;
        }

        // Place all 1s
        for (int i = c0; i < c0 + c1; i++) {
            nums[i] = 1;
        }

        // Place all 2s
        for (int i = c0 + c1; i < nums.size(); i++) {
            nums[i] = 2;
        }
    }
};

/*
================================
Approach (Simple Explanation):
================================
We need to sort an array containing only 0s, 1s, and 2s.

1. Traverse the array and count how many 0s, 1s, and 2s exist.
2. Overwrite the array:
   - First c0 positions with 0
   - Next c1 positions with 1
   - Remaining positions with 2

This works because only three distinct values exist.

================================
Example:
================================
nums = [2, 0, 2, 1, 1, 0]

Count:
c0 = 2
c1 = 2
c2 = 2

After filling:
[0, 0, 1, 1, 2, 2]

================================
Time Complexity:
================================
O(n)
We traverse the array twice — once for counting and once for filling.

================================
Space Complexity:
================================
O(1)
Only constant extra variables are used.
*/
