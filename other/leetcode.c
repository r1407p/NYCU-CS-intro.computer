#include<stdio.h>
#include<math.h>

int main(){
    int arr[6]={2,0,2,1,1,0};
    sortColors(arr,6);
    for(int i =0;i<6;i++)printf("%d ",arr[i]);
}
void sortColors(int* nums, int numsSize);
void swap(int *,int *);
void quicksort(int *,int ,int );
void sortColors(int* nums, int numsSize){
    quicksort(nums,0,numsSize-1);
}
void swap(int *a,int *b){
    *a ^=*b;
    *b ^=*a;
    *a ^=*b;
}
void quicksort(int *arr,int left,int right){
    int i =left;
    int j = right;
    int pivot =left;
    if(i>=j)return;
    while(i<j){
        while(arr[i]<=arr[pivot])i++;
        while(arr[pivot]<arr[j])j--;
        if(i<j)swap(arr+i,arr+j);
    }
    swap(arr+j,arr+pivot);
    quicksort(arr,left,j-1);
    quicksort(arr,j+1,right);
}
