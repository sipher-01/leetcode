class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int>res;
        set<int>st;
        for (int x: arr){
            set<int>temp;
            temp.insert(x);
            for (int y: st){
                temp.insert(x|y);
            }
            res.insert(temp.begin(),temp.end());
            st = temp;
        }
        return res.size();
    }
};