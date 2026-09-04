class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi= nums[0],mini=nums[0];
        int n = nums.size();
        int x = nums[0];
        for(int i = 1 ; i < n ; i++) {
            if(nums[i] <0) swap(mini,maxi);
            maxi = max(nums[i], maxi*nums[i]);
            mini = min(nums[i],mini*nums[i]);
            x = max(maxi,x);
        }
        return x;
    }
};