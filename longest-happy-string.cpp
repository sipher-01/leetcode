class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a>0) pq.push({a,'a'});
        if(b>0)pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});
        string ans = "";
        char prev ;
        while(!pq.empty()){
            auto node = pq.top();
            int freq = node.first;
            char letter = node.second;
            int cnt =0;
            if(prev == letter)cnt=1;
            while(freq>0 && cnt<2 ){
                ans += letter;
                // prev = letter;
                freq--;
                cnt++;
            }
            pq.pop();
           if(!pq.empty()){ 
                auto node2 = pq.top();
                int freq2 = node2.first;
                char letter2 = node2.second;
                ans += letter2;
                prev = letter2;
                freq2--;
                pq.pop();
                if(freq2>0)pq.push({freq2,letter2});
            }
            else break;
            if(freq>0)pq.push({freq,letter});
        }
         return ans;
    }
};