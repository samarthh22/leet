#define ll long long
class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int i = 0;
        ll lsum = 0,tsum = 0;
        int n = nums.size();
        for(i = 0 ; i < n; i++) {
            tsum += nums[i];
        }
        for(i = 0; i < n/2; i++) {
            lsum += nums[i];
        }
        int j = i;
        i=0;
        int count = 0;
        while(i < n) {
            if(j == n) j%=n; 
             if(lsum > tsum - lsum) count++;
            lsum += nums[j];
            lsum -= nums[i];
            i++;
            j++;
        }
        return count;
    }
};