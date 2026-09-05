class Solution {
public:
    int firstStableIndex(vector<int>& v, int k) {
        int n = v.size();
        vector<int> minv(n,INT_MAX);
        int mi=v[n-1];
        for(int j=n-1 ;j>=0;j--) {
            mi=min(mi,v[j]);
            minv[j] = mi;
        }
        int maxi=-1;
        for(int i = 0 ; i < n; i++) {
            maxi = max(maxi,v[i]);
            if(maxi-minv[i] <= k) return i;
        }
        return -1;
    }
};