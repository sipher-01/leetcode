class Solution {
public:
    int countBits(int x){
        return __builtin_popcount(x);
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        for(int hr = 0; hr < 12; hr++){
            for(int mn = 0; mn < 60; mn++){

                if(countBits(hr) + countBits(mn) == turnedOn){

                    string time = to_string(hr) + ":";

                    if(mn < 10) time += "0";
                    time += to_string(mn);

                    ans.push_back(time);
                }
            }
        }
        return ans;
    }
};
