class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st;
        unordered_set<string> end;
        for(auto it: deadends){
            end.insert(it);
        }
        int steps=0;
        queue<string> q;
        q.push("0000");
        while(!q.empty()){
            int s= q.size();
            for(int i=0; i<s; i++){
                string a= q.front();
                q.pop();
                if(a==target) return steps;
                if(end.count(a)) continue;
                for(int i=0; i<4; i++){
                    string temp= a;
                    int k= temp[i]-'0';
                    k= (k+1)%10;
                    temp[i]= '0'+k;
                    if(!st.count(temp)){
                        q.push(temp);
                        st.insert(temp);
                    }
                    k= (k+8)%10;
                    temp[i]= '0'+ k;
                    if(!st.count(temp)){
                        q.push(temp);
                        st.insert(temp);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};