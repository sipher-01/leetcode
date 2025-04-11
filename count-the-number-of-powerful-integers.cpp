class Solution {
public:
    long long solve(string str, string s, int limit){
        if(str.length()<s.length())return 0;

        int remL = str.length() - s.length();
        string trailing = str.substr(remL);
        long long count = 0;
        for(int i=0; i<remL; i++){
            int digit = str[i] - '0';
            if(digit <= limit){
                count+=digit*pow(limit+1,remL-i-1);
            }
            else{
                count += pow(limit+1,remL-i);
                return count;
            }
        }
        if(trailing>=s){
            count+=1;
        }
        return count;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string startStr = to_string(start-1);
        string endStr = to_string(finish);

        return solve(endStr,s,limit) - solve(startStr,s,limit);
    }
};