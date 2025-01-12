#include <bits/stdc++.h>
using namespace std;

// 207. 课程表
class Solution {
  public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        int visitednum = 0;
        for (int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0], b = prerequisites[i][1];
            graph[b].push_back(a);
            indegree[a]++;
        }
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            visitednum++;
            for (int i = 0; i < graph[front].size(); i++) {
                indegree[graph[front][i]]--;
                if (indegree[graph[front][i]] == 0)
                    q.push(graph[front][i]);
            }
        }
        return visitednum == numCourses;
    }
};