class Solution {
public:

    int maximumLength(vector<int>& nums) {
        map<long long,int>mp;
        for(auto it: nums){
            mp[it]++;
        }

        int ans = 1;

        if (mp.count(1)) {
            int count = mp[1];
            // The length of the subset must be odd
            if (count % 2 == 0) {
                count -= 1; 
            }
            ans = max(ans, count);
            mp.erase(1); // Remove 1 so we don't process it in the main loop
        }

        for(auto it: mp){
            int len = 0;
            if(it.second == 1){
                len = 1;
            }
            else{
                long long next = 1LL * it.first*it.first;
                len += 2;
                while(mp.find(next) != mp.end()){
                    if(mp[next] == 1){
                        len += 1;
                        break;
                    }
                    else{
                        next = next * next;
                        len += 2;
                    }
                }
                if(len%2==0){
                    len -= 1;
                }
            }
            ans = max(ans,len);
        }

        return ans;
    }
};

// class Solution {
// public:
//     int maximumLength(vector<int>& nums) {
//         // Changed to long long to prevent downcasting during lookups
//         // Changed to unordered_map for O(1) lookups
//         unordered_map<long long, int> mp;
//         for(auto it: nums){
//             mp[it]++;
//         }

//         // Initialize to 1, because the minimum valid subset length for a non-empty array is 1
//         int ans = 1; 

//         if (mp.count(1)) {
//             int count = mp[1];
//             // The length of the subset must be odd
//             if (count % 2 == 0) {
//                 count -= 1; 
//             }
//             ans = max(ans, count);
//             mp.erase(1); // Remove 1 so we don't process it in the main loop
//         }

//         for(auto it: mp){
//             int len = 0;
//             if(it.second == 1){
//                 len = 1;
//             }
//             else{
//                 long long next = 1LL * it.first * it.first;
//                 len += 2;
                
//                 // mp.find(next) is now safely looking up a long long key
//                 while(mp.find(next) != mp.end()){
//                     if(mp[next] == 1){
//                         len += 1;
//                         break;
//                     }
//                     else{
//                         next = next * next;
//                         len += 2;
//                     }
//                 }
                
//                 if(len % 2 == 0){
//                     len -= 1;
//                 }
//             }
//             ans = max(ans, len);
//         }

//         return ans;
//     }
// };