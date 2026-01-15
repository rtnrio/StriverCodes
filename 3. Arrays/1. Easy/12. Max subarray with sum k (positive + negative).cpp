// Find the length of the longest subarray whose sum is equal to K
// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<long long, int> sumMap;  // stores prefixSum -> first index
        long long sum = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i]; // add current element to prefix sum

            // Case 1: if total sum from 0 to i is equal to k
            if (sum == k)
                maxLen = max(maxLen, i + 1);

            // Case 2: if there is a prefix with sum = sum - k
            long long remaining = sum - k;
            if (sumMap.find(remaining) != sumMap.end()) {
                int len = i - sumMap[remaining];
                maxLen = max(maxLen, len);
            }

            // Case 3: store prefix sum if it is not already in map
            if (sumMap.find(sum) == sumMap.end()) {
                sumMap[sum] = i;
            }
        }

        return maxLen;
    }
};

/*
# Approach:
1. We keep track of the running sum (prefix sum) while going through the array.
2. For each index, we check:
   - If the total sum so far is equal to k → we found a valid subarray.
   - Otherwise, check if (sum - k) has appeared before.
     If yes, then the subarray after that index up to the current index has sum = k.
3. We use a map to remember the first time each prefix sum appeared.
   This helps us get the longest possible subarray.

# Example:
   arr = [10, 5, 2, 7, 1, 9], k = 15
   Prefix sums = [10, 15, 17, 24, 25, 34]
   → sum = 15 at i = 1 → length = 2 ([10,5])
   → sum = 25 at i = 4 → 25 - 15 = 10 (exists at index 0) → length = 4 ([5,2,7,1])
   ✅ Longest length = 4

# Time Complexity:  O(n)
   We visit each element only once.

# Space Complexity: O(n)
   We use a map to store prefix sums.
*/
