class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int total = 0;
        priority_queue<int> pq;
        for(auto i : stones) pq.push(i);
        while(pq.size() >= 2) {
            int first_stone = pq.top(); //y
            pq.pop();
            int second_stone = pq.top(); //x
            pq.pop();
            int c = first_stone - second_stone; //y - x
            pq.push(c);
        }
        int ans = pq.top();
        return ans;
    }
};