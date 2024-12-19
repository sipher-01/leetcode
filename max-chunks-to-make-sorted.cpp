class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cum = 0;
        int ori = 0;
        int chunk = 0;
        for(int i=0; i<arr.size(); i++){
            cum += arr[i];
            ori += i;
            if(cum == ori)chunk++;
        }
        return chunk;
    }
};