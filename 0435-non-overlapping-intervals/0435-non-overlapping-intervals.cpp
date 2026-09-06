class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), comp);
        int count = 1;
        int fTime = nums[0][1];
        for (int i = 1; i < n; i++) {
            if (nums[i][0] >= fTime) {
                fTime = nums[i][1];
                count++;
            }
        }
        return n - count;
    }
};