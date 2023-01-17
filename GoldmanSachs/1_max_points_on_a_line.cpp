#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
//     Approach2: Time - O(n^2)
    double slope(vector<int> &a, vector<int> &b){
        return ((b[1] - a[1]) / (float)(b[0] - a[0]));
    }

    int maxPoints(vector<vector<int>>& pt) {
        int max_points=1;
        int n = pt.size();

        // Calculating slope of every point with selected point
        for(int i=0; i<n-1; i++){
            map<double, int> map;
            for(int j=i+1; j<n; j++){
                // Calculating slope
                double m = slope(pt[i], pt[j]);
                if(pt[j][1] - pt[i][1] < 0 && pt[j][0] - pt[i][0] == 0)
                    map[abs(m)]++;

                else
                    map[m]++;
            }

            int temp = 0;
            for(auto i: map)
                temp = max(temp, i.second + 1); // +1 for the current point(point 'i' itself)
            max_points = max(max_points, temp);
        }

        return max_points;
    }
};


// class Solution {
// public:
// /*
//     Approach1: Time - O(n^3)
//     Take any 2 possible points then check how many oints lies on that line
//     if a point c lies on line ab
//     then slope(ac) = slope(bc)
// */
//     double slope(vector<int> &a, vector<int> &b){
//         return ((b[1] - a[1]) / (float)(b[0] - a[0]));
//     }

//     int maxPoints(vector<vector<int>>& pt) {
//         int max_points=INT_MIN;
//         int n = pt.size();
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 int total=2;
//                 for(int k=0; k<n; k++){
//                     if(k!=i && k!=j){
//                         double slope2 = slope(pt[j], pt[k]);
//                         double slope1 = slope(pt[i], pt[k]);
//                         if(slope1 == slope2)
//                             total++;
//                     }
//                 }
//                 max_points = max(max_points, total);
//             }
//         }
//         if(max_points != INT_MIN)
//             return max_points;
//         return 1;
//     }
// };




int main()
{

    return 0;
}