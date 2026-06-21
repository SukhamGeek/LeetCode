class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        int a= image.size();
        int b= image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int tar= image[sr][sc];
        image[sr][sc]=color;
        int count=0;
        while(!q.empty()){
            int s= q.size();
            for(int i=0; i<s; i++){
                auto[m,n]= q.front();
                q.pop();
                if((m+1)<a && image[m+1][n]==tar){
                    image[m+1][n]=color;
                    q.push({m+1,n});                    
                }
                if((n+1)<b && image[m][n+1]==tar){
                    image[m][n+1]=color;
                    q.push({m,n+1});                    
                }
                if((m-1)>=0 && image[m-1][n]==tar){
                    image[m-1][n]=color;
                    q.push({m-1,n});                    
                }
                if((n-1)>=0 && image[m][n-1]==tar){
                    image[m][n-1]=color;
                    q.push({m,n-1});
                }
            }
        }    
        return image;    
    }
};