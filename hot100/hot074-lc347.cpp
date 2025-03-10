#include <bits/stdc++.h>
using namespace std;

// 347. 前 K 个高频元素
class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        vector<int> ret;
        unordered_map<int, int> mp;
        for (auto &val : nums) {
            mp[val]++;
        }
        auto cmp = [&](int a, int b) -> bool { return mp[a] > mp[b]; };
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        // map的遍历
        // for (auto it = mp.begin(); it != mp.end(); it++) {
        //     q.push(it->first);
        //     if (q.size() > k) {
        //         q.pop();
        //     }
        // }
        // for(auto&[key,val]:mp){
        //     q.push(key);
        //     if(q.size()>k)
        //         q.pop();
        // }
        for(auto& pair:mp){
            q.push(pair.first);
            if (q.size() > k)
                q.pop();
        }
        while (!q.empty()) {
            ret.push_back(q.top());
            q.pop();
        }
        return ret;
    }
};

// pair能直接比较大小
class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> cnt;
        using pii = pair<int, int>;
        for (int x : nums) {
            ++cnt[x];
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for (auto &[x, c] : cnt) {
            pq.push({c, x});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};