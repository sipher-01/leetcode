class Solution {
public:
    int count(vector<int>& row){
        bool flag1 = true;
        bool flag2 = true;
        bool flag3 = true;
        for(int i=0; i<10; i++){
            // cout<<row[i]<<" ";
            int seat = i+1;
            if(seat>=2 && seat<=5 && row[i]==-1){
                flag1 = false;
            }
            if(seat>=4 && seat<=7 && row[i]==-1){
                flag2 = false;
            }
            if(seat>=6 && seat<=9 && row[i]==-1){
                flag3 = false;
            }
        }
        // cout<<"\n";
        if(flag1 || flag3)flag2 = false;
        // cout<<format("1: {}, 2: {}, 3: {}",flag1,flag2,flag3)<<"\n";
        return flag1 + flag2 + flag3;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(),reservedSeats.end(),[&](const auto& a, const auto&b){
            if(a[0]==b[0])return a[1]<b[1];
            return a[0]<b[0];
        });

        int ans = 0;
        vector<int>row(10,0);
        int r = reservedSeats[0][0];
        ans += (r-1)*2;
        for(auto it: reservedSeats){
            if(r!=it[0]){
                ans += count(row);
                // cout<<ans<<" ";
                ans += (it[0] - r - 1)*2;
                r = it[0];
                row.assign(10,0);
            }

            row[it[1]-1] = -1;
        }
        ans += count(row);
        ans += (n-r)*2;
        // cout<<ans<<"\n";
        return ans;
    }
};