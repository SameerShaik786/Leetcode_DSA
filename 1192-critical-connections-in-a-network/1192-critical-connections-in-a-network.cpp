class Solution {
public:
    int timer = 1;
    void dfs(int i,int parent,vector<vector<int>> &adjList,vector<int> &low,vector<int> &time,vector<vector<int>> &res,vector<int> &visited){
            visited[i] = 1;
            time[i] = low[i] = timer;
            timer++;
            for(auto x: adjList[i]){
                if(x != parent){
                    if(visited[x]){
                        low[i] = min(low[i],low[x]);
                    }
                    else{
                        dfs(x,i,adjList,low,time,res,visited);
                        low[i] = min(low[i],low[x]);
                        if(low[x] > time[i]){
                            res.push_back({i,x});
                        }
                    }
                }
            }
            return;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> res;
        vector<int> visited(n,0);
        vector<vector<int>> adjList(n);
        for(auto i: connections){
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }
        vector<int> low(n);
        vector<int> time(n);
        dfs(0,-1,adjList,low,time,res,visited);
        return res;
    }
};