class Solution {
public:
    int countCollisions(string directions) {
        int r= 0;
        int s=0;
        int ans = 0;
        for(auto it: directions){
            if(it == 'L'){
                if(r>0){
                    ans += (1+r);
                    r = 0; 
                    s = 1; 
                }
                else if(s>0){
                    ans += 1;
                    s = 1;
                }
            }
            else if(it == 'R'){
                r += 1;
                s = 0;
            }
            else{
                if(r>0){
                    ans += r;
                    r = 0;
                }
                s = 1;
            }
        }
        return ans;
    }
};