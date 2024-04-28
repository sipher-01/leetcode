class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>task(26,0);
        for(int i=0; i<tasks.size(); i++){
            task[tasks[i]-'A']++;
        }
        priority_queue<int>pq;
        for(int i: task){
            if(i>0){
                pq.push(i);
            }
        }
        int time = 0;
        while(!pq.empty()){
            int a = n+1;
            vector<int>temp;
            while(a>0 && !pq.empty())
            {   int x = pq.top()-1;
                pq.pop();
                temp.push_back(x);
                a--;
            }
            for(int &it: temp){
                if(it>0){
                    pq.push(it);
                }
            }
            if(pq.empty()){
                time +=  temp.size();
            }
            else{
                time += n+1;
            }

        }
        return time;

    }
};