class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n= s.size();
        vector<bool>vec(n+1,false);
        vec[0]=true;
        int maxi=INT_MIN;
        unordered_map<string,int>mpp;
        for(int i=0; i<wordDict.size(); i++){
            maxi= max(maxi,(int)wordDict[i].size());
            mpp[wordDict[i]]++;
        }
        for(int i=0; i<n; i++){
            int j=i;
            int temp=maxi;
            while(j>=0&&temp>0){
                if(mpp.find(s.substr(j,i-j+1))!=mpp.end()){
                    if(j==0){
                        cout<<i<<endl;
                        vec[i+1]=true;
                        break;
                    } 
                    else{
                        if(vec[j]==true){
                            cout<<i<<endl;
                            vec[i+1]=true;
                            break;
                        }
                    }
                }
                j--;
                temp--;
            }
        }
        return vec[n];
    }
};