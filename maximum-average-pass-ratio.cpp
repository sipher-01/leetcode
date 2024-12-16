class Solution {
public:
#define p pair<double,int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<p>pq;

        int n = classes.size();

        for(int i=0; i<n; i++){
            double cur = (double)classes[i][0]/classes[i][1]; 
            double pr = (double)(classes[i][0]+1)/(classes[i][1]+1);
            double delta = pr - cur ;
            pq.push({delta,i});
        }

        while(extraStudents--){
            auto curr = pq.top();
            pq.pop();
            double delta = curr.first;
            int i = curr.second;
            classes[i][0]++;
            classes[i][1]++;
            double cur = (double)classes[i][0]/classes[i][1]; 
            double pr = (double)(classes[i][0]+1)/(classes[i][1]+1);
            delta = pr - cur ;
            pq.push({delta,i});
        }

        double result = 0.0;

        for(int i=0; i<n; i++){
            result += (double)classes[i][0]/classes[i][1];
        }
        return result/n;

    }
};