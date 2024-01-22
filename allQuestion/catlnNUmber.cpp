#include<iostream>
using namespace std;
int CatlanNumber(int n){
    if(n<=1){
        return 1;
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res+= CatlanNumber(i)*CatlanNumber(n-i-1);
    }
    return res;
    
}

int main(){
    int n = 10;
    for (int i = 0; i < n ; i++)
    {
        cout<<CatlanNumber(i)<<" ";
    }
    return 0;
    
}