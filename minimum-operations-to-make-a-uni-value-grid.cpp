class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>temp;
        for(auto it: grid){
            for(auto i: it){
                temp.push_back(i);
            }
        }
        sort(begin(temp),end(temp));
        int rem = temp[0] % x;
        for (int num : temp) {
            if (num % x != rem) return -1;
        }
        int mid = temp[temp.size()/2];
        int op = 0;
        for(auto num: temp){
            op += abs(num-mid)/x;
        }
        return op;
    }
};