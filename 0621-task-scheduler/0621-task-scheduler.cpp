class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;
        for (auto& i : tasks) {
            m[i]++;
        }
        priority_queue<int> pq;
        for (auto& i : m) {
            pq.push(i.second);
        }
        int time = 0;
        while (!pq.empty()) {
            vector<int> temp;
            int cycle = n + 1;
            while (cycle > 0 && !pq.empty()) {
                auto x = pq.top();
                pq.pop();

                x--;
                if (x > 0) {
                    temp.push_back(x);
                }
                time++;
                cycle--;
            }
            for (auto i : temp)
                pq.push(i);
            if (!pq.empty())
                time += cycle;
        }
        return time;
    }
};