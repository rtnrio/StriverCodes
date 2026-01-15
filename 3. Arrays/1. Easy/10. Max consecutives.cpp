// https://leetcode.com/problems/max-consecutive-ones/
// ✅ Find the maximum number of consecutive 1's in a binary array
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;     // current streak of 1's
        int maxCount = 0;  // maximum streak so far

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;                 // extend current streak
                maxCount = max(maxCount, count);
            } else {
                count = 0;               // reset when 0 is found
            }
        }

        return maxCount;
    }
};

/*
🧩 Approach:
----------------------------------------
We perform a single scan through the array and keep track of:
- `count`: current number of consecutive 1's
- `maxCount`: the maximum number of consecutive 1's seen so far

Steps:
1. Iterate through the array.
2. When we see a `1`, increment `count`.
3. When we see a `0`, reset `count` to 0.
4. After each increment, update `maxCount` to store the largest streak.

Example:
nums = [1,1,0,1,1,1]
→ count sequence: 1 → 2 → 0 → 1 → 2 → 3
✅ Output: 3

----------------------------------------
⏱️ Time Complexity:  O(n)
   - Single pass through the array.

💾 Space Complexity: O(1)
   - Only two integer variables used.
----------------------------------------
*/
