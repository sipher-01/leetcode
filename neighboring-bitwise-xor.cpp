class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xorr = 0;
        int n = derived.size();
        for(int i=0; i<n; i++){
            xorr ^=derived[i];
        }
        if(xorr == 0)return true;
        return false;
    }
};