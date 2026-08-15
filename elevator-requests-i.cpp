class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int time = requests[0];
        int l = requests.size();

        for(int i=1; i<l; i++){
            time += abs(requests[i] - requests[i-1]);
        }

        return time;
    }
};