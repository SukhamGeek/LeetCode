class Solution {
public:
    struct hash_pair {
        size_t operator()(const pair<int,int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0;
        int y = 0;
        int p = 3;   // 0 east, 1 south, 2 west, 3 north
        int ans = 0;

        unordered_set<pair<int,int>, hash_pair> st;

        for (int i = 0; i < obstacles.size(); i++) {
            st.insert({obstacles[i][0], obstacles[i][1]});
        }

        for (int i = 0; i < commands.size(); i++) {

            if (commands[i] == -2) {
                p = (p + 3) % 4;
            }
            else if (commands[i] == -1) {
                p = (p + 1) % 4;
            }
            else {

                if (p == 0) {
                    for (int j = 0; j < commands[i]; j++) {
                        x++;
                        if (st.find({x, y}) != st.end()) {
                            x--;
                            break;
                        }
                    }
                }

                if (p == 1) {
                    for (int j = 0; j < commands[i]; j++) {
                        y--;
                        if (st.find({x, y}) != st.end()) {
                            y++;
                            break;
                        }
                    }
                }

                if (p == 2) {
                    for (int j = 0; j < commands[i]; j++) {
                        x--;
                        if (st.find({x, y}) != st.end()) {
                            x++;
                            break;
                        }
                    }
                }

                if (p == 3) {
                    for (int j = 0; j < commands[i]; j++) {
                        y++;
                        if (st.find({x, y}) != st.end()) {
                            y--;
                            break;
                        }
                    }
                }

                ans = max(ans, x * x + y * y);
            }
        }

        return ans;
    }
};