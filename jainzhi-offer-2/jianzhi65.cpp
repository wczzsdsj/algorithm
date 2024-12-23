#include<bits/stdc++.h>
using namespace std;

// 不用加减乘除做加法
class Solution {
  public:
    int encryptionCalculate(int dataA, int dataB) {
        int sum, carry;
        while(dataB!=0){
            sum = dataA ^ dataB;
            carry = (dataA & dataB) << 1;
            dataA = sum;
            dataB = carry;
        }
        return dataA;
    }
};