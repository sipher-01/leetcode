class Solution {
public:
    int gcd(int a, int b){
        if(b>a)return gcd(b,a);

        if(b==0)return a;

        return gcd(b,a%b);
    }
    int gcdOfOddEvenSums(int n) {
        int oddSum = (n * (2 + (n-1) * 2))/2;
        int evenSum = (n * (4 + (n-1) * 2))/2;
        return gcd(evenSum,oddSum);
    }
};