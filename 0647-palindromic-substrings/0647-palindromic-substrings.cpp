class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        unordered_map<string,int> m;
        for(int i =0;i<n;i++){
            int odd = getAllPalindromes(s,i,i,m);
            int even = getAllPalindromes(s,i,i+1,m);
        }
        return m.size();
    }
    int getAllPalindromes(string s,int left,int right,unordered_map<string,int> &m){
        while(left >=0 && right<s.size() && s[left]==s[right]){
            string a = to_string(left)+"."+to_string(right);
            if(m.count(a)==0) m[a] =1;
            left--;
            right++;
        }
        return 0;
    }
};