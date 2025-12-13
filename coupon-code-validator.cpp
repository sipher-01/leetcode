class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string>res;
        unordered_map<string,int>priority;
        vector<pair<string,string>>temp;
        priority["electronics"] = 3;
        priority["grocery"] = 2;
        priority["pharmacy"] = 1;
        priority["restaurant"] = 0;

        for(int i=0; i<code.size(); i++){
            bool flag = true;
            for(auto it: code[i]){
                if(isalnum(it) || it=='_'){
                    continue;
                }
                else{
                    flag = false;
                    break;
                }
            }
            if(flag && isActive[i] && priority.find(businessLine[i])!=priority.end() && code[i]!=""){
                temp.push_back({businessLine[i],code[i]});
            }
        }
        auto lamda = [&priority](auto const &a, auto const &b){
            if(priority[a.first]==priority[b.first]){
                return a.second<b.second;
            }
            return priority[a.first]>priority[b.first];
        };
        sort(temp.begin(),temp.end(),lamda);
        for(auto it: temp){
            res.push_back(it.second);
        }
        return res;
    }
};