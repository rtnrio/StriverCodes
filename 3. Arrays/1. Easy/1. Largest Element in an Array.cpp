#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestElement(vector<int>& nums) {
        return *max_element(nums.begin(), nums.end());
    }
};