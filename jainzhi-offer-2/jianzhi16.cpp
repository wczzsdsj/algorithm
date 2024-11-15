#include<iostream>
using namespace std;

//快速幂
class Solution {
public:
    double qpow(double x, long long n){
        double ans=1.0;
        while(n>0){
            if(n%2) ans=ans*x;
            x=x*x;
            n=n/2;
        }
        return ans;
    }
    double myPow(double x, int n) {
        if(n<0) {
            long long n_=n;  // 防止n=-2147483648 时，-n int会越界
            return 1.0/qpow(x,-n_);
        }
        return qpow(x,n);
    }
};