class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        if(points.size()<4) return 0;
        int mini= INT_MAX;
        unordered_set<string> st;
        for (auto &p : points) {
            string key = to_string(p[0]) + "," + to_string(p[1]);
            st.insert(key);
        }
        unordered_map<int, vector<int>> xco;
        unordered_map<int, vector<int>> yco;
        for(int i=0; i< points.size(); i++){
            int x= points[i][0];
            int y= points[i][1];
            if(xco.find(x)==xco.end() || yco.find(y)==yco.end()){
                xco[x].push_back(y);
                yco[y].push_back(x); 
                continue;
            }
            else{
                for(auto a: xco[x]){
                    for(auto b: yco[y]){
                        string temp= to_string(b)+ "," + to_string(a);
                        if(st.count(temp)){
                            int area= abs(x-b)* abs(y-a);
                            mini= min(mini, area);
                        }
                    }
                }
                xco[x].push_back(y);
                yco[y].push_back(x); 
            }
        }
        if(mini== INT_MAX) return 0;
        return mini;
    }
};