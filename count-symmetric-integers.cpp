class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;

        for(int i=low; i<=high; i++){
            string s = to_string(i);
            if(s.length()%2!=0)continue;
            else{
                int mid = s.length()/2;
                bool flag = true;
                int a =0,b=0;
                for(int j=0; j<s.length(); j++){
                    if(j==mid){
                        flag = false;
                    }
                    if(flag){
                        a+= (s[j]-'0');
                    }
                    else{
                        b+= (s[j]-'0');
                    }
                }
                if(a==b)ans++;
            }
        }
        return ans;
    }
};