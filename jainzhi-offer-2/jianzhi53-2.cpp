#include <functional>
#include <iostream>
#include <vector>
using namespace std;
// 0 ～ n-1 中缺失的数字
class Solution {
  public:
    int binarysearch(vector<int> &records, int l, int r) {
        if (l > r)
            return l;
        int mid = (l + r) / 2;
        int res;
        if (records[mid] == mid) {
            res = binarysearch(records, mid + 1, r);
        } else if (mid == 0 || records[mid - 1] == mid - 1)
            res = mid;
        else {
            res = binarysearch(records, l, mid - 1);
        }
        return res;
    }

    int takeAttendance(vector<int> &records) {
        return binarysearch(records, 0, records.size() - 1);
    }
};
class Solution {
  public:
    int takeAttendance(vector<int> &records) {
        int i = 0, j = records.size() - 1;
        int res = 0;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (records[mid] == mid) {
                i = mid + 1;
            } else if (mid == 0 || records[mid - 1] == mid - 1) {
                res = mid;
                break;
            } else {
                j = mid - 1;
            }
        }
        if (i == records.size())
            res = records.size();
        return res;
    }
};

class Solution {
  public:
    int takeAttendance(vector<int> &records) {
        int l = 0, r = records.size() - 1;
        while(l<=r){
            int mid = l + (r - l) / 2;
            if(records[mid]==mid)
                l = mid + 1;
            else
                r = mid-1;
        }
        return l;
    }
};