#define p pair<int,int>

class Solution {
public:
    int to_int(string s){
        int num = 0;
        int n = s.length();
        for(int i=0; i<n; i++){
            num = num*10 + (s[i]-'0');
        }
        return num;
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int n = numberOfUsers;
        vector<int>mention(n);
        unordered_set<int>online;
        auto lamda = [this](auto const &a, auto const &b){
            int x = to_int(a[1]), y = to_int(b[1]);
            if(x==y){
                if(a[0] == "OFFLINE" && b[0] == "MESSAGE") return true;
                if(a[0] == "MESSAGE" && b[0] == "OFFLINE") return false;
            }
            return x<y;
        };
        sort(events.begin(),events.end(),lamda);
        for(auto i=0; i<n; i++){
            online.insert(i);
        }
        //pair of (time_to_online, id);
        priority_queue<p,vector<p>,greater<p>>offline;
        int cnt = 0;
        for(auto e: events){
            int timeStamp = to_int(e[1]);
            while(!offline.empty() && offline.top().first<=timeStamp){
                auto it = offline.top();
                offline.pop();
                online.insert(it.second);
            }
            if(e[0] == "MESSAGE"){
                string s = "";
                for(int i=0; i<=e[2].length(); i++){
                    if(i==e[2].length() || e[2][i]==' '){
                        if(s=="ALL"){
                            cnt++;
                        }
                        else if(s=="HERE"){
                            for(int st: online){
                                mention[st]++;
                            }
                        }
                        else{
                            int id = to_int(s.substr(2));
                            mention[id]++;
                        }
                        s = "";
                    }
                    else{
                        s += e[2][i];
                    }
                }

            }
            else{
                int id = to_int(e[2]);
                offline.push({timeStamp+60,id});
                online.erase(id);
            }
        }
        for(int i=0; i<n; i++){
            mention[i] += cnt;
        }

        return mention;
        
    }
};