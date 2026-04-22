class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;
        for(int i=0; i<queries.size(); i++){
            for(int j=0; j<dictionary.size(); j++){
                int count=0;
                bool b= true;
                for(int k=0; k<queries[0].size(); k++){
                    if(queries[i][k]!=dictionary[j][k]) count++;
                    if(count>2){
                        b=false;
                        break;
                    }
                }
                if(b==true){
                    res.push_back(queries[i]);
                    break;
                }
            }
        }
        return res;
    }
};