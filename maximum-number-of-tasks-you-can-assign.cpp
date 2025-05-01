class Solution {
public:
    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid){
        multiset<int>st(workers.begin(),workers.begin()+mid);
        int pills_used = 0;
        for(int i=mid-1; i>=0; i--){
            auto it = prev(st.end());
            if(*it>=tasks[i]){
                st.erase(it);
            }
            else if(pills_used>=pills){
                return false;
            }
            else{
                auto weak_worker = st.lower_bound(tasks[i] - strength);
                if(weak_worker==st.end()){
                    return false;
                }
                st.erase(weak_worker);
                pills_used++;
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int m = tasks.size();
        int n = workers.size();

        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end(),greater<>());

        int l=0, r=min(m,n);
        int ans = 0;
        while(l<=r){
            int mid = l + (r-l)/2;

            if(check(tasks,workers,pills,strength,mid)){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return ans;
    }
};