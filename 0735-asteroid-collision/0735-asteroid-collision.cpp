class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        if(asteroids[0]>0) st.push(asteroids[0]);
        if(asteroids[0]<0) ans.push_back(asteroids[0]);
        for(int i=1; i<asteroids.size(); i++){
            if(asteroids[i]>0) st.push(asteroids[i]);
            else{
                bool flag= false;
                while(!st.empty()&& abs(asteroids[i])>=st.top()){
                    if(abs(asteroids[i])==st.top()){
                        st.pop();
                        flag= true;
                        break;
                    }
                    st.pop();
                }
                if(st.empty() && flag) continue;
                if(st.empty()){
                    ans.push_back(asteroids[i]);
                }
            }
        }
        stack<int>st2;
        if(!st.empty()){
            while(!st.empty()){
                st2.push(st.top());
                st.pop();
            }
            while(!st2.empty()){
                ans.push_back(st2.top());
                st2.pop();
            }
        }
        return ans;
    }
};