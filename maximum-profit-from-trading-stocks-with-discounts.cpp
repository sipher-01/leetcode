class Solution {
public:
    void dfs(int i, vector<int>& present, vector<int>& future, int budget, 
    unordered_map<int,vector<int>>&tree,vector<vector<vector<int>>>& statesProfit){
        vector<pair<vector<int>,vector<int>>>childStateProfit;
        for(int v: tree[i]){
            dfs(v,present,future,budget,tree,statesProfit);
            childStateProfit.push_back({statesProfit[v][0],statesProfit[v][1]});
        }
        for(int parentBuy = 0; parentBuy<=1; parentBuy++){
            int price = (parentBuy==1)?(present[i]/2): present[i];
            int profit = future[i] - price;
            vector<int>bestProfitAtU(budget+1,0);

            //case1: u didnt buy the stock
            vector<int>childIfUNotBought(budget+1,0);
            for(const auto& child: childStateProfit){
                vector<int>temp(budget+1,0);

                for(int used=0; used<=budget; used++){
                    for(int taken = 0; taken+used<=budget; taken++){
                        temp[taken+used] = max(temp[taken+used],childIfUNotBought[used]+
                        child.first[taken]);
                    }
                }
                childIfUNotBought=std::move(temp);
            }

            for(int b=0; b<=budget; b++){
                bestProfitAtU[b] = max(bestProfitAtU[b],childIfUNotBought[b]);
            }
            //case 2: u bought the stock
            if(price<=budget){
                vector<int>childIfUBought(budget+1,0);
                for(const auto& child: childStateProfit){
                    vector<int>temp(budget+1,0);

                    for(int used=0; used<=budget; used++){
                        for(int taken = 0; taken+used<=budget; taken++){
                            temp[taken+used] = max(temp[taken+used],childIfUBought[used]+
                            child.second[taken]);
                        }
                    }
                    childIfUBought=std::move(temp);
                }
                for(int b=price; b<=budget; b++){
                    bestProfitAtU[b] = max(bestProfitAtU[b],childIfUBought[b - price]+profit);
                }
            }

            statesProfit[i][parentBuy] = std::move(bestProfitAtU);
        }
    }
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        
        unordered_map<int,vector<int>>tree;
        for(auto it: hierarchy){
            tree[it[0]-1].push_back(it[1]-1);
        }
        //statesProfit[node][buy/notbuy][budget]
        vector<vector<vector<int>>>statesProfit(n,vector<vector<int>>(2,vector<int>(budget+1,0)));
        dfs(0,present,future,budget,tree,statesProfit);
        int ans = 0;
        for(int b=0; b<=budget; b++){
            ans = max(ans,statesProfit[0][0][b]);
        }
        return ans;
    }
};