class Solution {
public:
    string intToRoman(int num) {
    vector<int>n;
    int j = 1;
    while(num>0){
        int i = num%10;
        n.push_back(i*j);
        j *= 10;
        num /= 10;
    }
    reverse(n.begin(),n.end());
    string ans="";
    for(auto it: n){
        if(it>=1000){
            int times = it/1000;
            while(times--){
                ans += 'M';
            }
        }
        else if(it>=500){
            if(it==900)ans+="CM";
            else{int times = (it-500)/100;
            ans += 'D';
            while(times--){
                ans+='C';
            }}
        }
        else if(it>=100){
            if(it==400)ans+="CD";
            else{
            int times = (it)/100;
            while(times--){
                ans+='C';
            }}
        }
        else if(it>=50){
            if(it==90)ans+="XC";
            else {int times = (it-50)/10;
            ans +='L';
            while(times--){
                ans+='X';
            }}
        }
        else if(it>=10){
            if(it==40)ans+="XL";
            else {
            int times = (it)/10;
            while(times--){
                ans+='X';
            }}
        }
        else if(it>=5){
            if(it==9)ans+="IX";
            else {
            int times = (it-5);
            ans+='V';
            while(times--){
                ans+='I';
            }}
        }
        else{
            if(it==0)continue;
            if(it==4)ans+="IV";
            else{
                while(it--){
                    ans+='I';
                }
            }
        }
    }
        return ans;
    }
};