// https://leetcode.com/problems/majority-element/
// ✅ Find the element that appears more than ⌊n/2⌋ times in the array

// ✅ Optimized using Boyer-Moore Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;   // stores possible majority element
        int count = 0;       // counter

        for (int i = 0; i < nums.size(); i++) {
            // If count becomes zero, select new candidate
            if (count == 0) {
                candidate = nums[i];
            }

            // Update count
            if (nums[i] == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;   // final candidate is the majority element
    }
};

/*
🧩 Approach:
----------------------------------------
We use Boyer-Moore Voting Algorithm.

Idea:
- Majority element appears more than n/2 times.
- Every time we see a different element, we cancel one count.
- The majority element always survives.

Steps:
1. Start with count = 0.
2. When count becomes 0, choose current element as candidate.
3. If current element equals candidate → increment count.
4. Else → decrement count.
5. At the end, candidate is the majority element.

Example:
nums = [3,3,4,3,3,2,3]

Process:
candidate = 3, count = 1
candidate = 3, count = 2
candidate = 3, count = 1
candidate = 3, count = 2
candidate = 3, count = 3
candidate = 3, count = 2
candidate = 3, count = 3

✅ Output: 3

----------------------------------------
⏱️ Time Complexity:  O(n)
   - Single traversal of array.

💾 Space Complexity: O(1)
   - No extra memory used.
----------------------------------------
*/








✅ Better Approach
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;   // Stores frequency of each element
        int n = nums.size();

        // Step 1: Count frequency of each element
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        // Step 2: Find the element whose frequency > n/2
        for (auto it : freq) {
            if (it.second > n / 2) {
                return it.first;       // Majority element found
            }
        }

        // Safety return (problem guarantees majority exists)
        return -1;
    }
};

/*
🧩 Approach
----------------------------------------
We use a HashMap (unordered_map) to count how many times each number appears.

Steps:
1. Traverse the array and store the frequency of each element in a hashmap.
2. Traverse the hashmap and check which element has a count greater than n/2.
3. Return that element as the majority element.

Example:
nums = [2, 2, 1, 1, 1, 2, 2]

Frequency Map:
2 -> 4
1 -> 3

Since 2 appears more than n/2 times (n = 7, n/2 = 3),
✅ Output: 2

----------------------------------------
⏱️ Time Complexity: O(n)
   - One pass to build the hashmap.
   - One pass to find the majority element.

💾 Space Complexity: O(n)
   - HashMap stores up to n elements in the worst case.
----------------------------------------
*/
