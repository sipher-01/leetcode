class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double>prev;
        prev.push_back(poured*1.0);
        int i = 1;
        bool flag = false;
        while(prev.size()!=query_row+1){
            
            vector<double>cur;
            flag = false;
            if(prev[0]>1){
                flag = true;
                cur.push_back((prev[0]-1)/2);
            }
            else{
                cur.push_back(0);
            }
            for(int j=0; j<prev.size()-1; j++){
                double val = 0; 
                if(prev[j+1]>1){
                    val += (prev[j+1]-1)/2;
                    flag = true;
                }

                if(prev[j]>1){
                    val += (prev[j]-1)/2;
                    flag = true;
                }

                cur.push_back(val);
            }

            if(prev.back()>1){
                flag = true;
                cur.push_back((prev.back()-1)/2);
            }
            else{
                cur.push_back(0);
            }
        prev = cur;
        i++;
        if(!flag){
            break;
        }
        }
        if(query_glass>=prev.size()){
            return 0;
        }
        return min(1.0,prev[query_glass]);
    }
};