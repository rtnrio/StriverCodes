# good but not optimal
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            maxi = max(nums[i], maxi);
        }

        vector<int> hash(maxi + 1, 0);

        for (int i = 0; i < n; i++) {
            hash[nums[i]]++;
        }

        for (int i = 0; i < n; i++) {
            if (hash[nums[i]] == 1)
                return nums[i];
        }

        return -1;
    }
};

Optimal
// https://leetcode.com/problems/single-number/
// ✅ Find the element that appears only once in an array
// where every other element appears twice.

#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr = 0;

        // XOR all elements
        for (int i = 0; i < nums.size(); i++) {
            xorr = xorr ^ nums[i];
        }

        return xorr;
    }
};

/*
🧩 Approach:
----------------------------------------
We use the XOR (^) bitwise operator, which has these key properties:
1. a ^ a = 0   → a number XOR itself becomes 0
2. a ^ 0 = a   → a number XOR 0 remains unchanged
3. XOR is both commutative and associative

Thus, when all numbers appear twice except one:
    (a ^ a) ^ (b ^ b) ^ c  =  0 ^ 0 ^ c  =  c

So the unique number remains after XORing all elements.

----------------------------------------
Example:
nums = [4, 1, 2, 1, 2]
→ XOR sequence: (((4 ^ 1) ^ 2) ^ 1) ^ 2
→ Simplifies to: (4 ^ (1 ^ 1) ^ (2 ^ 2))
→ (4 ^ 0 ^ 0) = 4 ✅

----------------------------------------
⏱️ Time Complexity:  O(n)
   - Single pass through the array.

💾 Space Complexity: O(1)
   - Only one integer variable used.
----------------------------------------
*/
