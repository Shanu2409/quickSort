#include<iostream>
using namespace std;

int part(int *arr, int s, int e){
    int target = arr[s];
    int cnt = 0;

    //starting loop from s+1 cause s is target
    for(int i = s+1; i <= e; i++){
        if (arr[i]<=target){
            cnt++;
        }
    }

    int partI = s + cnt;

    swap(arr[s], arr[partI]);

    int i = s, j = e;

    while(i < partI && j > partI){
        while (arr[i]<target) i++;

        while (arr[j]>target) j--;

        if (i < partI && j > partI) swap(arr[i++], arr[j--]);
    }

    return partI;

}

void quickSort(int arr[], int s, int e){
    //base case
    if (s >= e)
     return ;

    int p = part(arr, s, e);

    //recursive call to solve left and right part of array
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}

int main()
{
    // cout<<"hello";
    int arr[] = {10,9,8,7,6,5,4,3,2,2};
    int n = 10;

    quickSort(arr, 0, n-1);

    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;


    return 0;
}
