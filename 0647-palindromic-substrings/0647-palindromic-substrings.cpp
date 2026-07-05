class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i =0;i<n;i++){
            ans += getAllPalindromes(s,i,i);
            ans += getAllPalindromes(s,i,i+1);
        }
        return ans;
    }
    int getAllPalindromes(string s,int left,int right){
        int count = 0;
        while(left >=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
            count++;
        }
        return count;
    }
};