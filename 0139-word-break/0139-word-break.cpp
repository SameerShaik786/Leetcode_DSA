class Solution {
public:
    int f(int i,string s,vector<string> &wordDict,vector<int> &dp){
        if(i == s.size()) return true;
        if(dp[i] != -1){
            return dp[i];
        }
        for(string p: wordDict){
            int len = p.size();
            if(s.substr(i,len) == p){
                    if(f(i+len,s,wordDict,dp)){
                        return dp[i] = true;
                    }
                }
            }
        return dp[i] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        return f(0,s,wordDict,dp);
    }
};