class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        string s1 = "",s2 = "";
        for(auto i: s){
            if(i != '#'){
                st.push(i);
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            auto ch = st.top();
            s1.push_back(ch);
            st.pop();
        }
        for(auto i: t){
            if(i != '#'){
                st.push(i);
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            auto ch = st.top();
            s2.push_back(ch);
            st.pop();
        }
        return s1==s2;
    }
};