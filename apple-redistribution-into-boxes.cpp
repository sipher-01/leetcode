class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int nas = 0;
        int n = capacity.size();
        int total = accumulate(apple.begin(), apple.end(),0);

        sort(capacity.begin(),capacity.end());
        int sum = 0;
        for(int i= n-1; i>=0; i--){
            nas++;
            sum += capacity[i];
            if(total<=sum)break;
        }
        return nas;
    }
};