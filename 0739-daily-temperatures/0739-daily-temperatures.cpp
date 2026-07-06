class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums2) {
        stack<int> st;
        int n = nums2.size();
        vector<int> res(n);
        vector<int> nextGreater(n,-1);
        for(int i=n-1;i>=0;i--){
            int num = nums2[i];
            while(!st.empty() && nums2[st.top()] <= num){
                st.pop();
            }
            if(!st.empty()){
                nextGreater[i] = st.top()-i;
            }
            st.push(i);
        }
        for(int i=0;i<n;i++){
            if(nextGreater[i]==-1) nextGreater[i] = 0;
        }
        return nextGreater;
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        return nextGreaterElement(temperatures);
    }
};