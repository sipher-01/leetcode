class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)return false;
        priority_queue<int,vector<int>, greater<int>>pq;
        for(int it: hand){
            pq.push(it);
        }
        int x = groupSize;
        while(!pq.empty()){
            int prev = pq.top();
            pq.pop();
            int temp = 1;
            vector<int>a;
            while(temp<groupSize && !pq.empty()){
                if(prev+1 == pq.top()){
                    prev = pq.top();
                    pq.pop();
                    temp++;
                }
                else if(prev == pq.top()){
                    a.push_back(pq.top());
                    pq.pop();
                }
                else {
                    return false;
                }
            }
            if(temp!=groupSize)return false;
            for(int i: a){
                pq.push(i);
            }
        }
        return true;
    }
};