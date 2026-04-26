class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int f=1; 
        int l= INT_MIN;
        for(int i=0; i<piles.size(); i++){
            l= max(l,piles[i]);
        }
        int mid= f+(l-f)/2;
        while(f<=l){
            int sum=0;
            int flag=1;
            for(int i=0; i<piles.size(); i++){
                sum+= (piles[i]+(mid-1))/mid;
                if(sum>h){
                    flag=-1;
                    break;
                }
            }
            if(flag==-1) f=mid+1;
            else l=mid-1;
            mid= f+(l-f)/2;
        }
        return mid;
    }
};