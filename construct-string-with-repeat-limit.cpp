class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<char>pq;
        vector<int>count(26,0);

        for(char &c: s){
            count[c-'a']+=1;
        }
        for(int i=25; i>=0; i--){
            if(count[i]>0)pq.push('a'+i);
        }
        string res = "";
        while(!pq.empty()){
            char c = pq.top();
            pq.pop();
            int freq = min(count[c-'a'],repeatLimit);
            res += string(freq,c);
            count[c-'a'] -= freq; 
            if(count[c-'a']>0){
                if(pq.empty())break;
                char c2 = pq.top();
                pq.pop();
                res += c2;
                count[c2-'a']--;
                if(count[c2-'a']>0){
                    pq.push(c2);
                }
                pq.push(c);
            }
        }
        return res;
    }
};