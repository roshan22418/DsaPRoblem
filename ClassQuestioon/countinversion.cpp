#include<iostream>
#include<vector>
using namespace std;

void mergeTwo(int *array,vector<int> &temp,int start,int end,int &count){
    int mid = (start+end)/2;
    int k = start;
    int index_i = start;
    int index_j = mid+1;
    int count1 = count;
    while (mid>=index_i && end>=index_j)
    {
        if(array[index_i]>array[index_j]){
            temp[k] = array[index_j];
            count1 += (mid - index_i + 1);   // mid - index_i +1 is all number means after index_i all inversion with 
            // index_j so all remaining element of mid - index_i +1 greater than array[index_j]
            index_j++;
            k++;
        }
        else
        {
            temp[k] = array[index_i];
            index_i++;
            k++;
        }
        
    }
    count = count1;
    while (mid>=index_i)
    {
        temp[k] = array[index_i];
        k++;index_i++;
    }
    while (end>=index_j)
    {
        temp[k] = array[index_j];
        k++;
        index_j++;
    }

    while (start<=end)
    {
        array[start] = temp[start];
        start++;
    }
    
    
    
    



}

void mergeSort(int *array,vector<int> &temp,int start,int end,int &count){
    int mid = (start + end)/2;
    if(start==end){
        return;
    }
    mergeSort(array,temp,start,mid,count);
    mergeSort(array,temp,mid+1,end,count);
    mergeTwo(array,temp,start,end,count);
}

int main(){
    int array[] = {3,7,1,9,4,5};
    int length = sizeof(array)/sizeof(array[0]);
    vector<int> copyArr(length,0);
    int start = 0;
    int count = 0;
    mergeSort(array,copyArr,0,length-1,count);
    cout<<count<<endl;
    return 0;
}