class Solution {
public:
    string getHappyString(int n, int k) {
        string s="a";
        if(n==1&& k<4){
          s[0]+=k-1;
          return s;  
        }
        int a=0;
        string ans=helper(n, k, "a", 1, a);
        if(a==k) return ans;
        ans=helper(n, k, "b", 1, a);
        if(a==k) return ans;
        ans=helper(n, k, "c", 1, a);
        if(a==k) return ans;
        return "";
    }
    string helper(int n, int k, string s, int size, int& o){
        if(o>=k) return "";
        if(size==n){
            o++;
            return s;
        }
        if(s[size-1]=='a'){
            string s1= helper(n, k, s+'b', size+1, o);
            if(o==k) return s1;
            string s2= helper(n, k, s+'c', size+1, o);
            if(o==k) return s2;
        }
        else if(s[size-1]=='b'){
            string s1= helper(n, k, s+'a', size+1, o);
            if(o==k) return s1;
            string s2= helper(n, k, s+'c', size+1, o);
            if(o==k) return s2;
        }
        else{
            string s1= helper(n, k, s+'a', size+1, o);
            if(o==k) return s1;
            string s2= helper(n, k, s+'b', size+1, o);
            if(o==k) return s2;
        }
        return "";
    }
};