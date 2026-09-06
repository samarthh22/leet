class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> v;
        int i = 0;
        while(i < n && nums1[i][1] < nums2[0]) {
            v.push_back(nums1[i]);
            i++;
        }
        while(i < n && nums1[i][0] <= nums2[1]) {
            nums2[0] = min(nums2[0],nums1[i][0]);
            nums2[1] = max(nums2[1],nums1[i][1]);
            i++;
        }
        v.push_back(nums2);
        while(i < n ) {
            v.push_back(nums1[i]);
            i++;
        }
        return v;
    }
};