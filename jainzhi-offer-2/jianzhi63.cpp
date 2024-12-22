#include<bits/stdc++.h>
using namespace std;
// 买卖股票的最佳时机(一次交易)
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int mi=INT_MAX;
        int maxvalue=0;
        for (int i = 0; i < prices.size();i++) {
            mi = min(prices[i],mi);
            if(i!=0)
                maxvalue = max(maxvalue,prices[i]-mi);
        }
        return maxvalue;
    }
};