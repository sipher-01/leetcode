class Solution {
public:

    struct DSU{
        // vector<int>p,r;
        unordered_map<int,int>p,r;
        // DSU(int n):p(n),r(n,0){
        //     for(int i=0; i<n; i++){
        //         p[i] = i;
        //     }
        // }
        int find(int x){
            if(p.find(x) == p.end()) p[x] = x;
            if(p[x]==x){
                return x;
            }
            return p[x] = find(p[x]);
        }

        void union_by_rank(int a, int b){
            a = find(a), b = find(b);
            if(a == b) return;
            if(r[a]>r[b]){
                p[b] = a;
                if(r[a] == r[b]) r[a]++;
            } 
            else{
                p[a] = b;
            }
        }
    };

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

        auto lamda = [](auto const& a, auto const& b){
            return a[2]<b[2];
        };
        sort(meetings.begin(),meetings.end(),lamda);
        // unordered_set<int>knowSecret;
        // knowSecret.insert(0);
        // knowSecret.insert(firstPerson);
        vector<bool>know(n,false);
        know[0] = true;
        know[firstPerson] = true;

        int i=0;
        while(i<meetings.size()){
            int time = meetings[i][2];
            int j = i;
            DSU dsu;
            set<int>person;
            // vector<int>person;

            while(j<meetings.size() && time == meetings[j][2]){
                int a = meetings[j][0], b = meetings[j][1];
                dsu.union_by_rank(a,b);
                person.insert(a);
                person.insert(b);
                // person.push_back(a);
                // person.push_back(b);
                j++;
            }
            // sort(person.begin(),person.end());
            // person.erase(unique(person.begin(), person.end()), person.end());
            unordered_set<int>good;
            for(int p: person){
                if(know[p]){
                    good.insert(dsu.find(p));
                }
            }
            for(int p: person){
                int parent = dsu.find(p);
                if(good.count(parent)){
                    know[p] = true;
                }
            }
            i = j;
        }

        vector<int>ans;
        for(int i=0; i<n; i++){
            if(know[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

