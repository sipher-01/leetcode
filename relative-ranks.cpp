class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>p;
        int count=1;
        for(int i=0; i<score.size(); i++){
            p.push({score[i],i});
        }
        vector<string>ans(score.size());
        while(!p.empty()){
            int top = p.top().second;
            p.pop();
            if(count==1){
                ans[top]="Gold Medal";
            }
            else if(count==2){
                ans[top]="Silver Medal";
            }
            else if(count==3){
                ans[top]="Bronze Medal";
            }
            else{
                ans[top]=to_string(count);
            }

            count++;
        }
        return ans;
    }
};