class Solution {
    int n;
public:
    bool solve(int l, int r, int cnt1, int cnt2, bool turn, vector<int>&nums){
        if(l>r){
            cout<<format("cnt1 : {} & cnt2 : {}",cnt1,cnt2)<<endl;
            if(cnt1>=cnt2)return true;
            return false;
        }
        bool res = false;
        cout<<format("l : {} r : {} turn : {}",l,r,turn)<<endl;
        if(turn){
            res |= solve(l+1,r,cnt1+nums[l],cnt2,!turn,nums) ||
             solve(l,r-1,cnt1+nums[r],cnt2,!turn,nums);
        }
        else{
            res |= solve(l+1,r,cnt1,cnt2+nums[l],!turn,nums) && 
             solve(l,r-1,cnt1,cnt2+nums[r],!turn,nums);
        }
        return res;
    }
    bool predictTheWinner(vector<int>& nums) {
        n = nums.size();
        if(n&1) return solve(0, n-1, 0, 0, true, nums);
        return true;
    }
};