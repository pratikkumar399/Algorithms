#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {4, 2, 8, 1, 7};
    int n = arr.size();
    int i, j;
    int passes = 0;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        passes++;
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            // passes++; //we can do this with the above passes++ to get the total number of swaps.
            if (arr[j] > arr[j + 1])
            {
                swapped = true;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
    cout << "Sorted array: ";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << passes << endl;
    return 0;
}