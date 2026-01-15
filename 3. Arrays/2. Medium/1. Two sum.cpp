// Question-
// https://leetcode.com/problems/two-sum/

// Solution-
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> hashMap; // stores number -> index

        for (int i = 0; i < n; i++) {
            int currentNumber = nums[i];
            int neededNumber = target - currentNumber;

            // If we have already seen the neededNumber, we found a pair
            if (hashMap.find(neededNumber) != hashMap.end()) {
                return { hashMap[neededNumber], i };
            }

            // Store current number with its index
            hashMap[currentNumber] = i;
        }

        return {-1}; // Just a fallback (problem guarantees a solution)
    }
};

/*
# Approach (Simple Explanation):
We want two numbers whose sum equals the target.
While scanning the array:

1. For each element `nums[i]`, compute the number we still need:
       neededNumber = target - nums[i]

2. Check if this neededNumber is already in the map.
   - If yes → we have found the correct pair
     because neededNumber + currentNumber = target

3. If not, store the current number with its index in the map.
   This helps future elements use it as the "needed number".

This works because hashMap stores previously seen numbers,
and we only need to scan the array once.

# Example:
nums = [2, 7, 11, 15], target = 9
i = 0: current=2, need=7 (not found), store 2→0
i = 1: current=7, need=2 (found!), return {0,1}

# Time Complexity: O(n)
We loop once through the array, and map operations are O(1) average.

# Space Complexity: O(n)
In the worst case, we store all elements in the map.
*/
