#include<bits/stdc++.h>
using namespace std;
// 扑克牌中的顺子
class Solution {
  public:
    bool checkDynasty(vector<int> &places) {
        sort(places.begin(),places.end());
        int num_zero = 0;
        int num_blank = 0;
        for (int i = 0; i < places.size();i++) {
            if(places[i]==0){
                num_zero++;
            }
        }
        for (int i = num_zero; i < places.size(); i++) {
            if (i - 1 >= num_zero && places[i - 1] == places[i])
                return false;
            if (i - 1 >= num_zero && places[i - 1] + 1 < places[i]) {
                num_blank += places[i] - places[i - 1] - 1;
            }
        }
        return num_zero < num_blank ? false : true;
    }
};