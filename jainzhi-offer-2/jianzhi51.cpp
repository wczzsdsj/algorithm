#include<vector>
#include<iostream>
#include<functional>
using namespace std;
// 数组中的逆序对
class Solution {
  public:
    int reversePairs(vector<int> &record) {
        int n = record.size();
        vector<int> tmp(n, 0);
        function<int(int, int)> mergeSort = [&](int l, int r) -> int {
            if (l >= r)
                return 0;
            int mid = (l + r) / 2;
            int res = mergeSort(l, mid) + mergeSort(mid + 1, r);
            int i = l, j = mid + 1;
            int index = i;
            while (i <= mid && j <= r) {
                if (record[i] <= record[j]) { // 保证j前面的都是小于record[i]，能构成逆序对的
                    res += j - (mid + 1);
                    tmp[index++] = record[i];
                    i++;
                } else {
                    tmp[index++] = record[j];
                    j++;
                }
            }
            for (; i <= mid; i++, index++) {
                tmp[index] = record[i];
                res += j - (mid + 1);
            }
            for (; j <= r; j++, index++) {
                tmp[index] = record[j];
            }
            for (int k = l; k <= r; k++) {
                record[k] = tmp[k];
            }

            return res;
        };
        for (auto val : record) {
            cout << val << ' ';
        }
        return mergeSort(0, n - 1);
    }
};