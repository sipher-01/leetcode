class Solution {
public:
int solve(vector<int> &arr, int k){
	int n = arr.size();
	int l=0, r=0;
	int cnt=0;
	int ans=0;
	while(r<n){
		if(arr[r]%2!=0)cnt++;
		while(cnt>k){
                if (arr[l] % 2 != 0) {
                    cnt--;
                }
                l++;
		}
		ans += r-l+1;
		r++;
	}
	return ans;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);

    }
};