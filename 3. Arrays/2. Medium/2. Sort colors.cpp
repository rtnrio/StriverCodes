// Question: Sort Colors
// https://leetcode.com/problems/sort-colors/
// ========================================================================================
// OPTIMAL APPROACH — Dutch National Flag Algorithm** (Three-Pointer Technique).
// ========================================================================================
#include <vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0;
        int high = nums.size() - 1;

        // Traverse the array
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

/*
🧩 Approach:
----------------------------------------

Idea:
- Maintain three pointers:
  - `low`  → position where the next 0 should go.
  - `mid`  → current element being processed.
  - `high` → position where the next 2 should go.

Rules:
- If nums[mid] == 0:
    Swap nums[low] and nums[mid],
    then increment both `low` and `mid`.
- If nums[mid] == 1:
    It's already in the correct position,
    so just move `mid`.
- If nums[mid] == 2:
    Swap nums[mid] and nums[high],
    then decrement `high`.
    (Do NOT increment `mid` because the swapped value must be checked.)

Array Partition:
[0 ... low-1]     → all 0s  
[low ... mid-1]   → all 1s  
[mid ... high]    → unknown  
[high+1 ... end]  → all 2s  

Example:
nums = [2, 0, 2, 1, 1, 0]

Final Output:
[0, 0, 1, 1, 2, 2]

----------------------------------------
⏱️ Time Complexity: O(n)

- The array is scanned only once using the `mid` pointer.
- Each element is processed at most one time.
- Pointer movements (`low`, `mid`, `high`) are monotonic and never reset.
- Swaps are constant-time operations.

Total operations grow linearly with input size.

----------------------------------------
💾 Space Complexity: O(1)

- No extra data structures are used.
- Only three integer variables are required.
- Sorting is performed in-place.

----------------------------------------
*/








// ========================================================
// BETTER APPROACH — Counting Method
// ========================================================
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c0 = 0, c1 = 0, c2 = 0;

        // Count number of 0s, 1s and 2s
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)       c0++;
            else if (nums[i] == 1)  c1++;
            else                    c2++;
        }

        // Place all 0s
        for (int i = 0; i < c0; i++) {
            nums[i] = 0;
        }

        // Place all 1s
        for (int i = c0; i < c0 + c1; i++) {
            nums[i] = 1;
        }

        // Place all 2s
        for (int i = c0 + c1; i < nums.size(); i++) {
            nums[i] = 2;
        }
    }
};

/*
🧩 Approach:
----------------------------------------
We use a **Counting Technique**.

Idea:
1. Traverse the array and count how many 0s, 1s, and 2s exist.
2. Overwrite the array in order:
   - First `c0` positions → 0
   - Next `c1` positions → 1
   - Remaining positions → 2

This works because only three distinct values exist.

Example:
nums = [2, 0, 2, 1, 1, 0]

Count:
c0 = 2, c1 = 2, c2 = 2

After filling:
[0, 0, 1, 1, 2, 2]

----------------------------------------
⏱️ Time Complexity: O(n)

- First pass counts the elements → O(n)
- Second pass rewrites the array → O(n)
- Total time remains linear.

----------------------------------------
💾 Space Complexity: O(1)

- Only three counters are used.
- No extra arrays or memory allocation.

----------------------------------------
*/
