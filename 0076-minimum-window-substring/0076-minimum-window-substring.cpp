class Solution {
public:
    bool compare(unordered_map<char,int> &m1,unordered_map<char,int> &m2){
        for(auto &i: m2){
            if(m1[i.first] < m2[i.first]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int count = t.size();
        int m = s.size(), n = t.size();
        int i =0, j =0;
        unordered_map<char,int> m1;
        int minLength = INT_MAX,start = -1;
        unordered_map<char,int> m2;
        for(auto i: t){
            m2[i]++;
        }
        while( j < m){
            m1[s[j]]++;
            if(m2.find(s[j]) != m2.end() && m1[s[j]] <= m2[s[j]]){
               count--;
            }
            while(i<m && count == 0){
                if(compare(m1,m2)){
                    if(j-i+1 < minLength){
                        minLength = j-i+1;
                        start = i;
                    }
                }
                m1[s[i]]--;
                if(m2.find(s[i]) != m2.end() && m1[s[i]] < m2[s[i]]){
                    count++;
                }
                i++;
            }
            j++;
        }
        return minLength == INT_MAX ? "" : s.substr(start,minLength);
    }
};