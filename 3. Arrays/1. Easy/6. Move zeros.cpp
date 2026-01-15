// https://leetcode.com/problems/move-zeroes/
// ✅ Move all zeros to the end while maintaining the order of non-zero elements.

#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZero = 0; // Position to place the next non-zero element

        // Traverse the array
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[lastNonZero++], nums[i]); 
            }
        }
    }
};

/*
🧩 Approach:
----------------------------------------
We use the **Two-Pointer Technique** to rearrange elements in-place.

Idea:
- Maintain one pointer `lastNonZero` that tracks the position
  where the next non-zero element should go.
- Traverse the array using another pointer `i`.
- Whenever we find a non-zero element at index `i`,
  we swap it with the element at index `lastNonZero`,
  then increment `lastNonZero`.

This effectively moves all non-zero elements to the front,
while pushing all zeros toward the end — in one pass.

Example:
nums = [0, 1, 0, 3, 12]

Step-by-step:
i = 0 → nums[0] = 0 → skip
i = 1 → nums[1] = 1 → swap(nums[0], nums[1]) → [1, 0, 0, 3, 12]
i = 2 → nums[2] = 0 → skip
i = 3 → nums[3] = 3 → swap(nums[1], nums[3]) → [1, 3, 0, 0, 12]
i = 4 → nums[4] = 12 → swap(nums[2], nums[4]) → [1, 3, 12, 0, 0]

✅ Output: [1, 3, 12, 0, 0]

----------------------------------------
⏱️ Time Complexity: O(n)
   - Single pass through the array.

💾 Space Complexity: O(1)
   - In-place swapping, no extra data structures used.
----------------------------------------
*/
