class Solution {
public:
    int maximumSwap(int num) {
        string s = "";
        while(num>0){
            int a = num%10;
            s+=to_string(a);
            num /= 10;
        }
        reverse(s.begin(),s.end());
        pair<int,int> maxi;
        maxi = {-1,-1};
        for(int i=0; i<s.size(); i++){
            if((s[i]-'0')>=maxi.first){
                maxi.first = (s[i]-'0');
                maxi.second = i;
            }
        }
        int n= s.size();
        vector<int> maxRight(n);
        int maxIdx = n - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] > s[maxIdx]) {
                maxIdx = i;
            }
            maxRight[i] = maxIdx;
        }
        for(int i=0; i<s.size(); i++){
            if(s[i] < s[maxRight[i]]) {
                swap(s[i],s[maxRight[i]]);
                break;
            }
        }
        // int ans = 0;
        // for(int i=0; i<s.size(); i++){
        //     ans = ans*10 + (s[i]-'0');
        // }
        return stoi(s);
    }
};