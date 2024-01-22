#include<iostream>
using namespace std;
#include<vector>



class Solution {
public:
    int solveUsingSpaceOptimization(string text1,string text2){
        int length1 = text1.length();
        int length2 = text2.length();
        vector<int> next(length1+1,0);
        vector<int> curr(length1+1,0);
        for(int j = length2-1;j>=0;j--){
            for(int i = length1-1;i>=0;i--){            
                if(text1[i]==text2[j]){
                    curr[j] = 1+ next[j+1];
                }

        //why add else statement in this case this thing i am not understand 
                else{
                    int notMatch1 = next[j];
                    int notMatch2 = curr[j+1];
                    curr[j] = max(notMatch1,notMatch2);
                }

            }
            next = curr;
        }
        return curr[0]; 

    }
    int solveusingTabulation(string text1,string text2){
        int length1 = text1.length();
        int length2 = text2.length();
        vector<vector<int>> dp(length1+1,vector<int>(length2+1,-1));
        for(int i = 0;i<=length2;i++){
            dp[length1][i] = 0;
        }
        for(int i = 0;i<=length1;i++){
            dp[i][length2] = 0;
        }
        for(int i = length1-1;i>=0;i--){
            for(int j = length2-1;j>=0;j--){
                if(text1[i]==text2[j]){
                    dp[i][j] = 1+ dp[i+1][j+1];
                }

        //why add else statement in this case this thing i am not understand 
                else{
                    int notMatch1 = dp[i][j+1];
                    int notMatch2 = dp[i+1][j];
                    dp[i][j] = max(notMatch1,notMatch2);
                }

            }
        }
        return dp[0][0]; 

    }

    int solveUSingRecursion(string text1,string text2,int i ,int j){
        if(i>=text1.length() || j>= text2.length()){
            return 0;
        }
        int ans = 0;
        if(text1[i]==text2[j]){
            ans = 1+ solveUSingRecursion(text1,text2,i+1,j+1);
        }

        //why add else statement in this case this thing i am not understand 
        else{
        int notMatch1 = solveUSingRecursion(text1,text2,i,j+1);
        int notMatch2 = solveUSingRecursion(text1,text2,i+1,j);
        ans = max(notMatch1,notMatch2);
        }
        return ans; 
    }

    int solveusingMEM(string text1,string text2,int i,int j,vector<vector<int>> &dp){
        if(i>=text1.length() || j>= text2.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(text1[i]==text2[j]){
            dp[i][j] = 1 + solveusingMEM(text1,text2,i+1,j+1,dp);
        }
        else{
            int exlude1 = 0 + solveusingMEM(text1,text2,i,j+1,dp);
            int exlude2 = 0 + solveusingMEM(text1,text2,i+1,j,dp);
            dp[i][j] = max(exlude1,exlude2);
        }
        return dp[i][j];
        
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        int length1 = text1.length();
        int length2 = text2.length();
        int ans = solveusingTabulation(text1,text2);
        return ans ;
        
    }
};

