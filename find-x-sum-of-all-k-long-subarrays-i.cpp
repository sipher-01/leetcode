class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
                int n = nums.size();
        vector<int> ans;

        for (int i = 0; i <= n - k; i++) {
            vector<int> sub(nums.begin() + i, nums.begin() + i + k);
            unordered_map<int, int> freq;
            for (int num : sub) {
                freq[num]++;
            }
            vector<pair<int, int>> items(freq.begin(), freq.end());
            sort(items.begin(), items.end(), [](auto &a, auto &b) {
                if (a.second == b.second) return a.first > b.first;
                return a.second > b.second;
            });
            int x_sum = 0;
            // unordered_set<int> top_x;
            for (int j = 0; j < items.size() && j < x; j++) {
                x_sum += (items[j].first * items[j].second);
                // top_x.insert(items[j].first);
            }
            // for (int num : sub) {
            //     if (top_x.count(num)) x_sum += num;
            // }

            ans.push_back(x_sum);
        }

        return ans;
    }
};