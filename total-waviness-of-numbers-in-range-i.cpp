class Solution {
public:

    int solve(int i){
        vector<int>a;
        int p = 0, v = 0;
        while(i>0){
            a.push_back(i%10);
            i /= 10;
        }

        for(int i=0; i<a.size(); i++){
            if((i>0 && i<a.size()-1) && (a[i-1]<a[i] && a[i]>a[i+1])){
                p++;
            }
            if((i>0 && i<a.size()-1) && (a[i-1]>a[i] && a[i]<a[i+1])){
                v++;
            }
        }
        return p+v;
    }

    int totalWaviness(int num1, int num2) {
        int cnt = 0;

        for(int i=num1; i<=num2; i++){
            cnt += solve(i);
        }

        return cnt;
    }
};