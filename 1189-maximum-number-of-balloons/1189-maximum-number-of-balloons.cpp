class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> v(26,0);
        int count = 0;
        for(auto i: text){
            v[i-'a']++;
            if(v['b'-'a']>=1 && v['a'-'a'] >= 1 && v['l'-'a'] >= 2 && v['o'-'a'] >= 2 && v['n'-'a'] >= 1){
                count++;
                v['b'-'a'] -= 1;
                v[0] -= 1;
                v['l'-'a'] -= 2;
                v['o'-'a'] -= 2;
                v['n'-'a'] -= 1;
            }
        }
        return count;
    }
};