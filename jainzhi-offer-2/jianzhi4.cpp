#include<vector>
using namespace std;
// class Solution
// {
// public:
//     bool findTargetIn2DPlants(vector<vector<int>> &plants, int target)
//     {
//         if (plants.empty())
//             return false;
//         int m = plants.size();
//         int n = plants[0].size();
//         int row = 0, col = n - 1;
//         while (row < m && col >= 0)
//         {
//             if (plants[row][col] == target)
//                 return true;
//             else if (plants[row][col] > target)
//                 col--;
//             else
//                 row++;
//         }
//         return false;
//     }
// };

//在二维数据中搜索target
class Solution{
public:
    bool findtargetintwoarray(vector<vector<int>>& plants,int target){
        if(plants.empty())
            return false;
        int m = plants.size();
        int n = plants[0].size();
        int row = 0, col = n - 1;
        while(row<m&&col>=0){
            if(plants[row][col]==target){
                return true;
            }
            else if(plants[row][col]<target)
                row++;
            else
                col--;
        }
        return false;
    }
};