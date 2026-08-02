class Solution {
    using ll = long long;
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        unordered_map<int,int>mp;
        ll sum = 0;
        int n = tasks.size();
        vector<ll>rem_task(n+1);

        rem_task[0]=0;
        for(int i=0; i<n; i++){
            sum += tasks[i];
            rem_task[i+1] = sum;
        }

        sum = 0;
        int m = shifts.size();
        vector<int>ans(m);
        ll mx = rem_task[n];
        for(int i=0; i<m; i++){
            sum += shifts[i];
            auto it = lower_bound(rem_task.begin(),rem_task.end(),sum);
            if(it==rem_task.end()){
                it = prev(it);
            }
            if(*it>sum) it = prev(it);
            int rem = n - (it-rem_task.begin());
            // cout<<format("rem : {} it : {} sum : {}",rem, it-rem_task.begin(), sum)<<endl;
            ans[i] = rem;
            if(sum>=mx){
                sum = 0;
            }
        }
        
        return ans;
    }
};