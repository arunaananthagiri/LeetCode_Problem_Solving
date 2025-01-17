class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int index = 0;
        for(auto i : s) {
            if(i == '(') {
                st.push(index);
                index = 0;
            }
            else {
                index = st.top() + max(index * 2, 1);
                st.pop();
            }
        }
        return index;
    }
};