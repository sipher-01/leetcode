class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        if(n==1)return 1;
        int prev = 1;
        for(int i=1; i<n; i++){
            prev += 1;
            arr[i] = min(arr[i],prev);
            prev = arr[i];
        }  
        return arr[n-1]; 
    }
};