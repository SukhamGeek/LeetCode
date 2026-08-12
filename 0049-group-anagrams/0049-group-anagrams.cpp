class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if(strs.size()==1){
            res.push_back({strs[0]});
            return res;
        }
        unordered_map<string,vector<int>> mpp;
        for(int i=0; i<strs.size(); i++){
            string temp= strs[i];
            sort(temp.begin(), temp.end());
            mpp[temp].push_back(i);
        }
        for(auto it: mpp){
            vector<string> temp;
            for(int i=0; i< it.second.size(); i++){
                temp.push_back(strs[it.second[i]]);
            }
            res.push_back(temp);
        }
        return res;
    }
};