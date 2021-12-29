#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//bruit force approch
struct max_min
{
    int max;
    int min;
};
// mxminfn function to provide maximum strength
max_min mxminfn(max_min k, vector<int> ve)
{
    //brute force technique
    // time complexity  O(n)
    // number of comparision 2(n-1)
    k.max = ve[0];
    k.min = ve[0];
    for (int i = 0; i < ve.size(); i++)
    {

        if (k.max < ve[i])
        {
            k.max = ve[i];
        }
        if (k.min > ve[i])
        {
            k.min = ve[i];
        }
    }
    return k;
}
// more efficient approch with less complexity
max_min get_min_max(max_min k, int a, vector<int> vec, int b)
{
    int low = a;
    int high = b;
    int mid = (low + high) / 2;
    max_min kr;
    max_min kl;
    if (low == high)
    {
        k.max = k.min = vec[low];
    }
    else if (high == low + 1)
    {
        k.max = (vec[high] > vec[low]) ? vec[high] : vec[low];
        k.min = (vec[high] < vec[low]) ? vec[high] : vec[low];
    }
    else 
     { kl=  get_min_max(k, a, vec, mid);
      kr=  get_min_max(k, mid + 1, vec, b);
     
      k.max=(kl.max>kr.max)?kl.max:kr.max;
      k.min=(kl.min>kr.min)?kr.min:kl.min;
     
     }

    return k;
}

int main(int argc, char const *argv[])
{
    vector<int> vec;
    int k, n;
    cout << "enter the size :" << endl;
    cin >> n;
    cout << "Enter the elements u want to insert :\n";
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin >> k;
        vec.push_back(k);
    }
    cout << "\n";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
        /* code */
    }
    max_min mn;
    cout<<"\n----------------brute force approch------------\n";
    mn = mxminfn(mn, vec);
    cout << "\n max_value: " << mn.max << endl;
    cout << "\n min_value: " << mn.min << endl;

    cout<<"\n----------------optimised approch------------\n";
    mn = get_min_max(mn, 0, vec, n - 1);
    cout << "\n max_value: " << mn.max << endl;
    cout << "\n min_value: " << mn.min << endl;

    return 0;
}
