#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<fstream>

void MergeSort(vector<int> &array, int front, int end);
void Merge(std::vector<int> &Array, int front, int mid, int end);
int main(){
    vector<int> temp = {9,8,7,6,5,4,3,2,1,0};
    MergeSort(temp,0,9);
    for(int i =0;i<10;i++){
        cout << temp[i]<<" ";
    }
    cout << endl;
}


void MergeSort(vector<int> &array, int front, int end){
                                         // front與end為矩陣範圍
    if (front < end) {                   // 表示目前的矩陣範圍是有效的
        int mid = (front+end)/2;         // mid即是將矩陣對半分的index
        MergeSort(array, front, mid);    // 繼續divide矩陣的前半段subarray
        MergeSort(array, mid+1, end);    // 繼續divide矩陣的後半段subarray
        Merge(array, front, mid, end);   // 將兩個subarray做比較, 並合併出排序後的矩陣
    }
}

void Merge(std::vector<int> &Array, int front, int mid, int end){

    // 利用 std::vector 的constructor, 
    // 把array[front]~array[mid]放進 LeftSub[]
    // 把array[mid+1]~array[end]放進 RightSub[]
    vector<int> temp;
    int i  = front;
    int j = mid +1;
    int now =0;
    while(now<end-front+1){
        // for(int t =0;t< end-front+1;t++){
        //     cout << Array[front+t];
        // }
        // cout << endl;
        // cout << i<< j<<now<<mid<<end<<endl;
        // system("pause"); 
        if(i<=mid&&j<=end){
            if(Array[i]<=Array[j]){
                temp.push_back(Array[i]);
                i++,now++;
                continue;
            }else{
                temp.push_back(Array[j]);
                j++,now++;
                continue;
            }
        }
        if(i<=mid){
            temp.push_back(Array[i]);
            i++,now++;
            continue;
        }
        if(j<=end){
            temp.push_back(Array[j]);
            j++,now++;
            continue;
        }
    }
    for(int k =0;k<end-front+1;k++){
        Array[front+k]= temp[k];
    }
}