// Find the Second Largest Element in an Array
// (Custom problem — similar to typical array interview questions)
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        if (nums.size() < 2) return -1; // Not enough elements

        int largestElement = INT_MIN;
        int sLargestElement = INT_MIN;

        for (auto num : nums) {
            if (num > largestElement) {
                // Update both largest and second largest
                sLargestElement = largestElement;
                largestElement = num;
            } 
            else if (num < largestElement && num > sLargestElement) {
                // Update second largest if it's smaller than current number
                sLargestElement = num;
            }
        }

        // If no second largest element exists
        return (sLargestElement == INT_MIN) ? -1 : sLargestElement;
    }
};

/*
# Approach:
1. Initialize two variables:
   - `largestElement` = INT_MIN
   - `sLargestElement` = INT_MIN
2. Traverse the array once:
   - If current number > largestElement:
       * Update `sLargestElement = largestElement`
       * Update `largestElement = num`
   - Else if current number < largestElement and num > sLargestElement:
       * Update `sLargestElement = num`
3. After traversal:
   - If `sLargestElement` remains INT_MIN → return -1 (no second largest found).
   - Otherwise → return `sLargestElement`.

# Example:
   Input: [10, 5, 20, 8]
   Process:
       largest = 10 → 20
       second largest = 5 → 10
   Output: 10
# Time Complexity: O(n)
   → Each element is visited once.

# Space Complexity: O(1)
   → Only constant extra variables are used.
*/