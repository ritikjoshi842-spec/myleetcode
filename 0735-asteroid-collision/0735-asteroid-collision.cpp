class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int i = 0; i < asteroids.size(); i++) {
            int curr = asteroids[i];
            bool alive = true;
            while ((!st.empty()) and (curr < 0) and (st.top() > 0)) {
                if (abs(curr) > abs(st.top())) {
                    st.pop();
                } else if (abs(curr) == abs(st.top())) {
                    st.pop();
                    alive = false;
                    break;
                } else {
                    alive = false;
                    break;
                }
            }
            if (alive) {
                st.push(curr);
            }
        }
        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};