// https://leetcode.com/problems/missing-number/
// ✅ Find the missing number in the range [0, n]

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();               // Total numbers expected: n + 1 (0 to n)
        int sum1 = n * (n + 1) / 2;        // Expected sum of numbers from 0 to n
        int sum2 = 0;                      // Actual sum of elements in nums

        // Compute actual sum
        for (int i = 0; i < n; i++) {
            sum2 += nums[i];
        }

        // The difference gives the missing number
        return sum1 - sum2;
    }
};

/*
🧩 Approach:
----------------------------------------
We use the **Mathematical Formula for Sum of First N Natural Numbers**.

Idea:
- The numbers are in the range [0, n].
- The expected sum of all numbers from 0 to n is:
     sum1 = n * (n + 1) / 2
- If one number is missing, the actual sum (sum2) of the array will be smaller.
- The difference between them gives the missing number:
     missing = sum1 - sum2

Example:
nums = [3, 0, 1]
n = 3
Expected sum = 3 * (3 + 1) / 2 = 6
Actual sum = 3 + 0 + 1 = 4
Missing = 6 - 4 = 2 ✅

----------------------------------------
⏱️ Time Complexity:  O(n)
   - Single pass to calculate the actual sum.

💾 Space Complexity: O(1)
   - Uses only constant extra space.
----------------------------------------
*/
