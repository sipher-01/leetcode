class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int total_students = chalk.size();
        long long total_sum = accumulate(chalk.begin(), chalk.end(), 0LL);
        k %= total_sum;
        for(int i=0; i<total_students; i++){
            if(k<chalk[i]){
                return i;
            }
            k -= chalk[i];
        }
        return -1;
    }
};