class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";

        for(int i=0;i<s.size();i++){
            int odd = expand(s,i,i);
            int even = expand(s,i,i+1);
            int length = max(odd,even);
            if(length >= ans.size()){
                int start = i-(length-1)/2;
                int end = i+length/2;
                ans = s.substr(start,length);
            }
        }
        return ans;
    }
    int expand(string s,int left,int right){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
};