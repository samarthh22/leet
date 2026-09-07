class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        // dir
        // down=0,left=1, up=2, right=3
        // i,j,step,dir
        vector<vector<vector<vector<int>>>> dis(
            m, vector<vector<vector<int>>>(
                   n, vector<vector<int>>(k + 1, vector<int>(4, INT_MAX))));
        // cost,i,j,step,dir
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        pq.push({grid[0][0], 0, 0, 0, 4});
        int res = INT_MAX;
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, -1, 0, 1};
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int dist = top[0];
            int i = top[1];
            int j = top[2];
            int steps = top[3];
            int dir = top[4];
            if (i == m - 1 && j == n - 1)
                return dist;
            for (int x = 0; x < 4; x++) {
                int nrow = i + drow[x];
                int ncol = j + dcol[x];
                if (nrow < 0 || nrow >= m || ncol < 0 || ncol >= n) continue;
                int nst = steps;
                if (dir != 4 && dir != x) nst++;
                if(nst > k) continue;
                if(dist +grid[nrow][ncol] < dis[nrow][ncol][nst][x] ) {
                    dis[nrow][ncol][nst][x] = dist +grid[nrow][ncol];
                    pq.push({dist +grid[nrow][ncol],nrow,ncol,nst,x});
                }
            }
        }
        return -1;
    }
};