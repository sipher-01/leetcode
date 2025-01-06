class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int>ans(n);
        vector<int>one;
        for(int i=0; i<n; i++){
            if(boxes[i] == '1'){
                one.push_back(i);
            }
        }
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int &it: one){
                sum += abs(i-it);
            }
            ans[i] = sum;
        }
        return ans;

    }
};