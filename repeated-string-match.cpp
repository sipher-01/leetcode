class Solution {
public:
    int rabinKarp(string t,string p){
        int n=t.size();
        int m=p.size();
        long long patHash  = 0;
        long long power = 1;
        int base = 26;
        int prime = 100000001;
        for(int i=0; i<m; i++){
            patHash = (patHash + (p[i]-'a'+1)*power)%prime;
            power = (power*base)%prime;
        }
        vector<long long>pha(n);//prefix hash array
        vector<long long>pa(n);//power array
        pha[0] = t[0]-'a'+1;
        pa[0] = 1;
        power = base;
        for(int i=1; i<n; i++){
            pha[i] = (pha[i-1] + (t[i]-'a'+1)*power)%prime;
            pa[i]=power;
            power = (power*base)%prime;
        }
        long long sp = 0, ep = m-1;
        while(ep<n){
            long long win  = pha[ep];
            if(sp>0){
                win = (win-pha[sp-1]+prime)%prime;
            }
            if(win==(patHash*pa[sp])%prime)return 1;
            sp++;ep++;
        }
        return 0;

    }
    int repeatedStringMatch(string a, string b) {
        if(a== b) return 1;
        int count = 1;
        string source = a;
        while(source.size() < b.size()){
            source+=a;
            count++;
        }
        if(source == b) 
            return count;
        if(rabinKarp(source,b) == 1) 
            return count;        
        if(rabinKarp(source+a,b) == 1) 
            return count+1;
        return -1;
    }
};