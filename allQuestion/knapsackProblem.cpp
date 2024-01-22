#include <iostream>
#include <vector>

using namespace std;
int solveusingTabulation(int *profit,int *wt,int &capacity,int length){
    vector<vector<int>> dp(capacity+1,vector<int> (length+1,-1));
    //according to base case in recursion and memization use only;
    for (int row = 0; row <= capacity; row++)
    {
        dp[row][length]=0;
    }
    for (int i = 0; i <= capacity; i++)
    {
        //i do wrong thing in looping condition 
        for (int j = length-1; j >= 0; j--)
        {
            int include = 0;
            if (i>=wt[j])
            {
                // and here forget subtract capacity of corresponding weight in row;
                include = profit[j] + dp[i-wt[j]][j+1];
            }
            int exlude = 0+ dp[i][j+1];
            dp[i][j] = max(include,exlude);
            
            
        }
        
    }
    return dp[capacity][0];
    
}


int solveUSingSpaceOptimization(int *profit,int *wt,int capacity,int length){
    vector<int> next(capacity+1,-1);
    vector<int> curr(capacity+1,-1);
    for (int row = 0; row <= capacity+1; row++)
    {
        next[row]  = 0;
    }
    for (int j = length-1; j >= 0; j--)
    {
        for(int i  = 0;i<=capacity;i++)        
        {
            int include = 0;
            if(i>=wt[j]){
                include = profit[j] + next[i-wt[j]];


            }
            int exlude = 0 + next[i];
            curr[i] = max(include,exlude);
        }
        next = curr;
        
    }
    return curr[capacity];
    
    
}


// int solve(int *profit, int *wt, int index, int length, int &capacity,vector<vector<int>> &dp)
// {
//     // if (index == length - 1)
//     // {
//     //     if (wt[index] <= capacity)
//     //     {
//     //         return profit[index];
//     //         /* code */
//     //     }
//     //     else
//     //     {
//     //         return 0;
//     //     }
//     // }

//     if(index>=length){
//         return 0;
//     }
     
//     if(dp[capacity][index]!=-1){
//         return dp[capacity][index];
//     }
//      int include = 0;
//      if (wt[index]<=capacity)
//      {
//         int remainingCapacity = capacity - wt[index]; 
//         include = profit[index] + solve(profit,wt,index+1,length,remainingCapacity,dp);

       
//      }   
    
//     int exclude = 0+ solve(profit,wt,index+1,length,capacity,dp);
//     dp[capacity][index] = max(include,exclude);
//     return dp[capacity][index]; 
// }



int solve(int *profit,int *wt,int index,int length,int &capacity,vector<vector<int>> &dp){
    if (index>=length) 
    {
        return 0;
    }
    if(dp[capacity][index]!=-1){
        return  dp[capacity][index];
    }
    int include = 0;
    if (wt[index]<=capacity)    
    {
        int remainingCapacity = capacity - wt[index];
        include =profit[index] +  solve(profit,wt,index+1,length,remainingCapacity,dp);
    }
    int exclude = 0+ solve(profit,wt,index+1,length,capacity,dp);
    dp[capacity][index] = max(include,exclude);
    return dp[capacity][index];

    
}
int solveUsingRecurssion(int *profit,int *wt,int index,int length,int &capacity){
    //i am stuck here why this is not base case; may be if capacity is not zero but index out of bound means increase by length 

    // if(capacity<=0){
    //     return 0;
    // }

    if(index>=length){
        return 0;
    }
    int include = 0;
    if (wt[index]<=capacity)
    {
        int remainingCapacity = capacity - wt[index];
        include = profit[index] + solveUsingRecurssion(profit,wt,index+1,length,remainingCapacity);
    }
    int exlude = 0 + solveUsingRecurssion(profit,wt,index+1,length,capacity);
    int ans  = max(include,exlude);
    return ans;
    
}
int main()
{
    int profit[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int index = 0;
    int length = 3;
    int capacity = 50;
    vector<vector<int>> dp(capacity+1,vector<int>(length+1,-1)); 
    // int ans = solve(profit, wt, index, length, capacity,dp);
    // int ans  = solveUsingRecurssion(profit,wt,index,length,capacity);
    // int ans = solveusingTabulation(profit,wt,capacity,length);
    int ans = solveUSingSpaceOptimization(profit,wt,capacity,length);
    cout<<ans<<" ";

    return 0;
}