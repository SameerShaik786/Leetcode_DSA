class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> distances(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    distances[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            int i = x.first, j = x.second;
            if(i-1>=0 && distances[i-1][j] == -1 && mat[i-1][j] == 1){
                q.push({i-1,j});
                distances[i-1][j] = distances[i][j]+1;
            }
            if(i+1<m && distances[i+1][j] == -1 && mat[i+1][j] == 1){
                q.push({i+1,j});
                distances[i+1][j] = distances[i][j]+1;
            }
            if(j-1>=0 && distances[i][j-1] == -1 && mat[i][j-1] == 1){
                q.push({i,j-1});
                distances[i][j-1] = distances[i][j]+1;
            }
            if(j+1<n && distances[i][j+1] == -1 && mat[i][j+1] == 1){
                q.push({i,j+1});
                distances[i][j+1] = distances[i][j]+1;
            }
        }
        return distances;
    }
};