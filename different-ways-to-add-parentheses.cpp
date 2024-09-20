class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int>ans;
        for(int i = 0; i<expression.size(); i++){
            if(expression[i] =='+'||expression[i] == '-'||expression[i] == '*'){
                auto a = diffWaysToCompute(expression.substr(0,i));
                auto b = diffWaysToCompute(expression.substr(i+1));
                for(auto it: a){
                    for(auto itr: b){
                        if(expression[i]=='+') ans.push_back(it+itr);
                        else if(expression[i]=='-') ans.push_back(it-itr);
                        else if(expression[i]=='*') ans.push_back(it*itr);
                    }
                }
            }
        }
        if(ans.empty())ans.push_back(stoi(expression));
        return ans;
    }
};