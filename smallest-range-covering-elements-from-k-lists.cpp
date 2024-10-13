class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // to store min element, list index ,  index
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int max_element = INT_MIN;
        vector<int>small(2,0);
        small[1] = INT_MAX;
        int i=0;
        for(auto &it: nums){
            pq.push({it[0],i,0});
            i++;
            max_element = max(max_element,it[0]);
        }

        while(!pq.empty()){
            auto node = pq.top();
            int min_element = node[0];
            int list_ind = node[1];
            int ind = node[2];
            pq.pop();
            if((max_element - min_element < small[1] - small[0]) || 
            (max_element - min_element == small[1] - small[0] &&
            min_element<small[0])){
                small[0] = min_element;
                small[1] = max_element;
             }
            if(ind+1 < nums[list_ind].size()){
                int val = nums[list_ind][ind+1];
                pq.push({val,list_ind,ind+1});
                max_element = max(val,max_element);
            }
            else{
                break;
            }
        }
        return small;
    }
};