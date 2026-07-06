class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        for(int i = 0;i<nums2.size();i++){
            m[nums2[i]] = i;
        }
        stack<int> st;
        int n = nums2.size();
        vector<int> res(nums1.size());
        vector<int> nextGreater(n,-1);
        st.push(nums2[n-1]);
        for(int i=n-2;i>=0;i--){
            int num = nums2[i];
            while(!st.empty() && st.top() <= num){
                st.pop();
            }
            if(!st.empty()){
                nextGreater[i] = st.top();
            }
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            res[i] = nextGreater[m[nums1[i]]];
        }
        return res;
    }
};