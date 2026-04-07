class Robot {
public:
    int d=0; //current dir east d=1  is north d=2 west d=3 south
    int x=0;
    int y=0;
    int w;
    int h;
    int per;
    Robot(int width, int height) {
         w= width-1;
         h= height-1;
         per= 2*(w+h);
    }
    void step(int num) {
        if(num>per){
            num= num%per;
            if (num == 0) {
                num = per;
            }
        }
        if(d==0){
           if((w-x)<num){
              int temp= num-(w-x);
              x=w;
              d=(d+1)%4;
              step(temp);
              return;
           } 
           else x+=num;
        }
        else if(d==1){
           if((h-y)<num){
              int temp= num-(h-y);
              y=h;
              d=(d+1)%4;
              step(temp);
              return;
           }
           else y+=num;
        }
        else if(d==2){
           if(x<num){
              int temp= num-x;
              x=0;
              d=(d+1)%4;
              step(temp);
              return;
           }
           else x-=num;
        }
        else if(d==3){
           if(y<num){
              int temp= num-y;
              y=0;
              d=(d+1)%4;
              step(temp);
              return;
           }
           else y-=num;
        }
    }
    
    vector<int> getPos() {
        vector<int>ans={x,y};
        return ans;
    }
    
    string getDir() {
        if(d==0) return "East";
        else if(d==1) return "North";
        else if(d==2) return "West";
        else return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */