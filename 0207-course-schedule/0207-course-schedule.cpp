class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto &i: prerequisites){
            adjList[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i] == 0) q.push(i); 
        }
        vector<int> ans;
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            ans.push_back(x);
            for(auto j: adjList[x]){
                indegree[j]--;
                if(indegree[j] == 0) q.push(j);
            }
        }
        return ans.size() == numCourses;
    }
};