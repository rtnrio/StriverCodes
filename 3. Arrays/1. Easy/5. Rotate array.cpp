// https://leetcode.com/problems/rotate-array/
// ✅ Rotate the array to the right by k steps

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) return;     // Single element → nothing to rotate

        k = k % n;              // Handle cases where k > n
        if (k == 0) return;     // No rotation needed if k is multiple of n

        // Step 1: Reverse the entire array
        reverse(nums.begin(), nums.end());

        // Step 2: Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Step 3: Reverse the remaining n - k elements
        reverse(nums.begin() + k, nums.end());
    }
};

/*
🧩 Approach:
----------------------------------------
We use the **Reversal Algorithm** to rotate the array in-place.
Idea:
- A rotation by k steps means the last k elements move to the front.
- Instead of shifting one by one, we reverse parts of the array
  to efficiently rearrange them.

Algorithm:
1. Reverse the entire array.
2. Reverse the first k elements.
3. Reverse the remaining n - k elements.

Example:
nums = [1, 2, 3, 4, 5, 6, 7], k = 3
Step 1 → Reverse entire array:
         [7, 6, 5, 4, 3, 2, 1]
Step 2 → Reverse first k = 3 elements:
         [5, 6, 7, 4, 3, 2, 1]
Step 3 → Reverse remaining elements:
         [5, 6, 7, 1, 2, 3, 4]
✅ Output: [5, 6, 7, 1, 2, 3, 4]
----------------------------------------
⏱️ Time Complexity:  O(n)
   - Each reversal traverses the array once.

💾 Space Complexity: O(1)
   - In-place rotation, no extra memory used.
----------------------------------------
*/
