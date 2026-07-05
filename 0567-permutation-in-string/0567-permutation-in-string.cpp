class Solution {
public:
    bool checkInclusion(string p, string s) {
        int m = s.size(), n = p.size();
        int i = 0,j =0;
        vector<int> alpha_p(26,0);
        vector<int> alpha_s(26,0);
        for(int i=0;i<n;i++){
            alpha_p[p[i]-'a']+=1;
        }
        string st;
        while( j<m){
            st.push_back(s[j]);
            alpha_s[s[j]-'a']+=1;
            if((j-i+1)==n){
                bool ok = true;
                for(int k=0;k<n;k++){
                    if(alpha_p[p[k]-'a']!=alpha_s[p[k]-'a']){
                        ok = false;
                        break;
                    }
                }
                if(ok == true){
                 return true;
                }
                alpha_s[s[i]-'a']--;
                i++;
            }
           j++;
        }
        return false;
    }
};