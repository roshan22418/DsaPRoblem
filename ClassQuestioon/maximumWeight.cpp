#include<iostream>
#include<vector>
using namespace std;
int solve(int *arr,int i ,int n,vector<int> &ans1){
    if(i>=n){
        return 0;
    }
    if(ans1[i]!=-1){
        return ans1[i];
    }
    int ans = 0;
    int include = arr[i] + solve(arr,i+2,n,ans1);
    int exlude = 0 + solve(arr,i+1,n,ans1);
    ans = max(include,exlude);
    ans1[i] = ans;
    return ans ;

}

int solveusingtabulationTowDown(int *arr,int length){
    vector<int> ans(length+1,0);
    ans[length] = 0;
    ans[length-1] = arr[length-1];
    for (int i = length-2; i >=0; i--)
    {
        int include = arr[i] + ans[i+2];
        int exlude = 0 + ans[i+1];
        ans[i] = max(include,exlude);
    }
    return ans[0];
    
}



int solveusingSpaceOptimization(int *arr,int length){
    int prev = 0;
    int next = arr[length-1];
    int ans = 0;
    for (int i = length-2; i >=0; i--)
    {
        int include = arr[i] + prev;
        int exlude = 0 + next;
        ans = max(include,exlude);
        prev = next;
        next = ans;
    }

    return ans ;
    
}



int main(){
    int arr[] = {2,5,6,4,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    // int ans = solve(arr,i,n,ans1);
    int ans1 = solveusingSpaceOptimization(arr,n);
    // cout<<ans1<<endl;
    cout<<ans1;
    return 0;
}