class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int i=0,j=0,n = s.size();
        unordered_map<char,int> m;
        while(j<n){
            m[s[j]]++;
            while((j-i+1) > m.size()){
                m[s[i]]--;
                if(m[s[i]]==0){
                    m.erase(s[i]);
                }
                i++;
            }
            if((j-i+1)==m.size()){
                ans = max(ans,j-i+1);
            }
            j++;
        }
        return ans;
    }
};