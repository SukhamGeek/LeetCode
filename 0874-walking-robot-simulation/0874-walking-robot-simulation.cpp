class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x=0;
        int y=0;
        int p=3;
        int ans= INT_MIN;
        struct hash_pair {
            size_t operator()(const pair<int,int>& p) const {
                return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
            }
        };
        unordered_map<pair<int,int>, int, hash_pair> mpp;
        for(int i=0; i<obstacles.size(); i++){
            mpp[{obstacles[i][0],obstacles[i][1]}]++;
        }
        for(int i=0; i<commands.size(); i++){
            if(commands[i]==-2){
                p= (p+3)%4;
                continue;
            }
            else if(commands[i]==-1){
                p= (p+1)%4;
                continue;
            }
            else{
                if(p==0){
                    for(int j=0; j<commands[i]; j++){
                        x++;
                        if(mpp[{x,y}]>0){
                            x--;
                            break;
                        }
                    }
                }
                if(p==1){
                    for(int j=0; j<commands[i]; j++){
                        y--;
                        if(mpp[{x,y}]>0){
                            y++;
                            break;
                        }
                    }
                }
                if(p==2){
                    for(int j=0; j<commands[i]; j++){
                        x--;
                        if(mpp[{x,y}]>0){
                            x++;
                            break;
                        }
                    }
                }
                if(p==3){
                    for(int j=0; j<commands[i]; j++){
                        y++;
                        if(mpp[{x,y}]>0){
                            y--;
                            break;
                        }
                    }
                }
                
                int temp= (x*x)+(y*y);
                if(temp>ans) ans=temp;
            }
        }
        return ans;
    }
};