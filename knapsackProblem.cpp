#include <iostream>
#include <vector>

using namespace std;

int solve(int *profit, int *wt, int index, int length, int &capacity,vector<vector<int>> &dp)
{
    // if (index == length - 1)
    // {
    //     if (wt[index] <= capacity)
    //     {
    //         return profit[index];
    //         /* code */
    //     }
    //     else
    //     {
    //         return 0;
    //     }
    // }

    if(index>=length){
        return 0;
    }
     
    if(dp[capacity][index]!=-1){
        return dp[capacity][index];
    }
     int include = 0;
     if (wt[index]<=capacity)
     {
        int remainingCapacity = capacity - wt[index]; 
        include = profit[index] + solve(profit,wt,index+1,length,remainingCapacity,dp);

       
     }   
    
    int exclude = 0+ solve(profit,wt,index+1,length,capacity,dp);
    dp[capacity][index] = max(include,exclude);
    return dp[capacity][index]; 
}

int main()
{
    int profit[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int index = 0;
    int length = 3;
    int capacity = 50;
    vector<vector<int>> dp(capacity+1,vector<int>(length+1,-1)); 
    int ans = solve(profit, wt, index, length, capacity,dp);
    cout<<ans<<" ";

    return 0;
}