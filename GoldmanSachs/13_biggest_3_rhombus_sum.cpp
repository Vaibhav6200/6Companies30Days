#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isValid(int row, int col, int rowSize, int colSize){
        return (row>=0 && row<rowSize && col>=0 && col<colSize);
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        set<int> sums;
        // Iterate through all cells in the grid
        for(int i=0; i<grid.size(); i++)
            for(int j=0; j<grid[0].size(); j++)
                sums.insert(grid[i][j]);

        for(int squareSize=1; squareSize <= 50; squareSize++){
            for(int row=0; row<m; row++){
                for(int col=0; col<n; col++){
                    if(isValid(row-squareSize, col, m, n) && isValid(row, col-squareSize, grid.size(), grid[0].size()) && isValid(row+squareSize, col, grid.size(), grid[0].size()) && isValid(row, col+squareSize, grid.size(), grid[0].size())) {
                        int sum = grid[row-squareSize][col] + grid[row+squareSize][col]  + grid[row][col-squareSize] + grid[row][col+squareSize];
                        for(int diag = 1; diag < squareSize; diag++)
                            sum += grid[row-diag][col+squareSize-diag];

                        for(int diag = 1; diag < squareSize; diag++)
                            sum += grid[row-diag][col-squareSize+diag];

                        for(int diag = 1; diag < squareSize; diag++)
                            sum += grid[row+diag][col+squareSize-diag];

                        for(int diag = 1; diag < squareSize; diag++)
                            sum += grid[row+diag][col-squareSize+diag];

                        sums.insert(sum);
                    }
                }
            }
        }

        vector<int> sumsList;
        for(auto sum : sums)
            sumsList.push_back(sum);

        reverse(sumsList.begin(), sumsList.end());

        vector<int> topThree;
        if(sumsList.size() < 3)
            return sumsList;

        for(int i = 0; i < 3; i++)
            topThree.push_back(sumsList[i]);

        return topThree;
    }
};



// class Solution {
// public:
//     int calcSum(int left, int right, int up, int down, vector<vector<int>> &grid){
//         int c1 = (left + right)/2;
//         int c2 = c1;
//         bool expand = true;
//         int sum=0;
//         for(int row=up; row<=down; row++){
//             if(c1 == c2)
//                 sum += grid[row][c1];
//             else
//                 sum += grid[row][c1] + grid[row][c2];

//             if(c1 == left)
//                 expand = false;

//             if(expand){
//                 c1--;
//                 c2++;
//             }
//             else{
//                 c1++;
//                 c2--;
//             }
//         }

//         return sum;
//     }

//     vector<int> getBiggestThree(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         priority_queue<int> pq;
//         set<int> mySet;     // used to store distinct values only in priority queue

//         for(int i=0; i<m; i++){
//             for(int j=0; j<n; j++){
//                 int l=j, r=j;
//                 int d=i;
//                 while(l>=0 && r<n && d<m){
//                     int sum = calcSum(l, r, i, d, grid);      // left, right, top, bottom
//                     l -= 1;
//                     r += 1;
//                     d += 2;
//                     pq.push(sum);
//                 }
//             }
//         }

//         // taking out top 3 sums from priority queue
//         vector<int> result;
//         for(int i=0; i<3; i++){
//             int temp = pq.top();
//             pq.pop();
//             result.push_back(temp);
//         }

//         return result;
//     }
// };



int main()
{

    return 0;
}