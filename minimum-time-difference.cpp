class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>timeStamp;
        for(auto time: timePoints){
            int hour = stoi(time.substr(0,2));
            int min = stoi(time.substr(3,2));
            timeStamp.push_back(hour*60+min);
        }
        sort(timeStamp.begin(),timeStamp.end());
        int mini = INT_MAX;
        for(int i=0; i<timeStamp.size()-1; i++){
            mini = min(mini,timeStamp[i+1]-timeStamp[i]);
        }
        mini = min(mini,1440-timeStamp[timeStamp.size()-1]+timeStamp[0]);
        return mini;
    }
};