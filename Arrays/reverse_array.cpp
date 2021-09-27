//Program to reverse an array
//Time Complexity -> O(n)
#include<iostream>
using namespace std;
void reverseArray(int arr[],int start,int end)
{

             int temp;
            while(start < end)
           {
                 temp = arr[start];
                 arr[start] = arr[end];
                 arr[end] = temp;
                 start++;
                 end--;
           }

}
int main()
{

int n = 6-1;
int arr[n] = {1,2,3,4,5};
reverseArray(arr,0,n);
for(int i=0;i<=n;i++)
    cout<<arr[i]<<" ";

}
