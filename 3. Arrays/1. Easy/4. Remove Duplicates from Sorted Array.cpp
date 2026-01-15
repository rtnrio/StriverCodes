
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// ✅ Remove Duplicates from Sorted Array
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;  // Edge case: empty array
        int i = 0; // slow pointer — marks position of last unique element
        for (int j = 1; j < nums.size(); ++j) {
            // If a new unique element is found
            if (nums[j] != nums[i]) {
                i++;              // Move to next unique position
                nums[i] = nums[j]; // Copy unique element forward
            }
        }
        return i + 1; // Number of unique elements
    }
};

/*
🧩 Approach:
----------------------------------------
We use the **Two Pointer Technique** because the array is sorted.

1. The first pointer `i` tracks the position of the last unique element.
2. The second pointer `j` scans through the array.
3. When a new unique number is found (`nums[j] != nums[i]`):
   - Increment `i`
   - Copy that unique number to `nums[i]`
4. After the loop, the first `i + 1` elements of `nums` are unique.
----------------------------------------
⏱️ Time Complexity:  O(n)
   - We traverse the array once.

💾 Space Complexity: O(1)
   - In-place modification; no extra space used.
----------------------------------------
*/