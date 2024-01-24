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



int main(){
    int arr[] = {2,5,6,4,3,5};
    int i = 0;
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> ans1(n+1,-1);
    int ans = solve(arr,i,n,ans1);
    cout<<ans<<endl;
    return 0;
}