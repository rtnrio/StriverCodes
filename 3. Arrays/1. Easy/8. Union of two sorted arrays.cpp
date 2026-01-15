// ✅ Find the Union of Two Sorted Arrays
// https://practice.geeksforgeeks.org/problems/union-of-two-sorted-arrays

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        // Step 1: Merge both arrays
        for (int i = 0; i < nums2.size(); i++) {
            nums1.push_back(nums2[i]);
        }

        // Step 2: Sort the merged array
        sort(nums1.begin(), nums1.end());

        // Step 3: Remove duplicates in-place
        int i = 0;
        for (int j = 1; j < nums1.size(); j++) {
            if (nums1[i] != nums1[j]) {
                i++;
                nums1[i] = nums1[j];
            }
        }

        // Step 4: Create a new vector with unique elements
        vector<int> final;
        for (int j = 0; j <= i; j++) {
            final.push_back(nums1[j]);
        }
        return final;
    }
};

/*
🧩 Approach:
----------------------------------------
We merge both arrays and then remove duplicates after sorting.

Steps:
1. Append all elements of nums2 into nums1.
2. Sort the combined array so that all duplicate elements are adjacent.
3. Use the two-pointer technique to remove duplicates in-place:
   - Maintain index `i` for the position of the last unique element.
   - Iterate with `j`, and whenever nums1[i] != nums1[j],
     increment `i` and copy nums1[j] to nums1[i].
4. Copy the first (i + 1) unique elements into a new vector and return it.

Example:
nums1 = [3,4,6,7,9,9]
nums2 = [1,5,7,8,8]

After merging: [3,4,6,7,9,9,1,5,7,8,8]
After sorting: [1,3,4,5,6,7,7,8,8,9,9]
After removing duplicates: [1,3,4,5,6,7,8,9]

✅ Output: [1,3,4,5,6,7,8,9]

----------------------------------------
⏱️ Time Complexity: O((n1 + n2) * log(n1 + n2))
   - Sorting dominates the complexity.

💾 Space Complexity: O(1) (ignoring the output vector)
   - Duplicate removal is done in-place.
----------------------------------------
*/
