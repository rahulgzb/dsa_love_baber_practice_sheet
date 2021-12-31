#include <bits/stdc++.h>
using namespace std;
//brute force teechnique 
//extra size put all the negative element in one array and other in extra array;
//put all the negative eliment in it;
/*------------two pointer technique--------*/

void swap(int* a,int*b)
{
    int temp =*a;
    *a=*b;
    *b=temp;
}
void myalgo(int arr[],int low ,int high )
{
    int p1=low;
    int p2=low+1;
    while (p2<=high)
    {
        if ((arr[p1]<0 && arr[p2]>=0) || (arr[p1]<0 && arr[p2]<0))
        {
            p1++;
            p2++;
        }
        else if (arr[p1]>=0 && arr[p2]>=0)
        {
             p1++;
             p2++;
             myalgo(arr,p1,high);
        }
        else if (arr[p1]>=0 && arr[p2]<0)
        {
            swap(&arr[p1],&arr[p2]);
            --p1;
            --p2;
        }
        
    }
    
}

int main(int argc, char const *argv[])
{
    int arr[] = {-3,-3,2,3,-9,-7,23};
    int n =sizeof(arr)/sizeof(arr[0]);
      myalgo (arr,0,n-1);
      for (int i = 0; i < n; i++)
      {
          cout<<"  "<<arr[i];
          /* code */
      }
      

    return 0;
}
