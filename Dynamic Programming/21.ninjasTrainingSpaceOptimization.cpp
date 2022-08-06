/*
Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?
You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.
*/
#include <bits/stdc++.h>
using namespace std;




int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<int>prev(4, 0);
    prev[0]=max(points[0][1], points[0][2]);
    prev[1]=max(points[0][0], points[0][2]);
    prev[2]=max(points[0][0], points[0][1]);
    prev[3]=max(max(points[0][0], points[0][1]), points[0][3]);
    
    for(int day = 1; day <n; day++){
        vector<int>temp(4, 0);
        for(int last = 0; last <4; last++){
               temp[last]=0;
            for(int task = 0; task<3; task++){
                if(task!=last){
                   temp[last]=max(temp[last],  points[day][task]+prev[task]);
                }
            }
        }
        prev =temp;
    }
    return prev[3];
}

int main()
{

    return 0;
}
