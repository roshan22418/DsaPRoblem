#include<iostream>
using namespace std;



void QuickSort(int *arr,int start,int end){
    if(start>=end){
        return;
    }
    int pivot = end;
    int i = start-1;
    int j = start;
    while (j<pivot)
    {
    
        if(arr[pivot]>arr[j]){
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    i++;
    swap(arr[i],arr[pivot]);
    QuickSort(arr,start,i-1);
    QuickSort(arr,i+1,end);    

}

int main(){
    int arr[] = {56,34,23,7};
    int length = sizeof(arr)/sizeof(int);
    // int g = length/5;
    int start = 0;
    QuickSort(arr,0,length-1);
    for (int i = 0; i < length; i++)
    {
        cout<<arr[i]<<endl;
    }
    
    
}