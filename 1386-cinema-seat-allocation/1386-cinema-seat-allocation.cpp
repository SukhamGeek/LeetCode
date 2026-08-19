class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<bool>> check;
        for(auto it: reservedSeats){
            if(check.find(it[0])==check.end()){
                check[it[0]]= vector<bool>(3,true);
            }
            if(it[1]==1 || it[1]==10) continue;
            else if(it[1]<4 && check[it[0]][0]==true) check[it[0]][0]= false;
            else if((it[1]==4 || it[1]==5) &&(check[it[0]][0]==true || check[it[0]][1]==true)){
                check[it[0]][0]= false;
                check[it[0]][1]= false;
            }
           
            else if((it[1]==6 || it[1]==7) && (check[it[0]][1]==true || check[it[0]][2]==true)){
                check[it[0]][1]= false;
                check[it[0]][2]= false;
            }
            else if(it[1]>7 && check[it[0]][2]==true) check[it[0]][2]= false;
        }
        int ans= 2*(n-check.size());
        for(auto it: check){
            vector<bool> k= it.second;
            if(k[0]== true && k[2]==true) ans+=2;
            else if(k[0]== false && k[1]==false && k[2]==false) continue;
            else ans++;
        }
        return ans;
    }
};