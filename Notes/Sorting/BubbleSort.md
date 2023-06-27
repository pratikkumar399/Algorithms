# Bubble Sort
It is a sorting algorithm which works by repeatedly swapping the adjacent elements if they are in wrong order or not in the required order.
``` 
> It gets its name from the way the smaller element bubbles or moves to the top or the first position.

> The element keeps getting swapped with the adjacent element until they are in the correct order.

> It works for certain rounds everytime from the first position to get the fully sorted array at the end.
```

## Example to understand the complete process👇🏻

Suppose we have an array of numbers:

>>[4,2,8,1,7]

Now for the array given above these will be the involved rounds of bubble sorting :

#### <ins>Round-1</ins>
  - Firstly it will compare 4 and 2 and swapping will be there as 4 is greater than 2.
  
  [**4**,**2**,8,1,7] -> [**2**,**4**,8,1,7]
  
  - Now the second and third element i.e. 4 and 8 will be compared and no swapping will be there as 4 is smaller than 8.
  
  [2,**4**,**8**,1,7] -> [2,**4**,**8**,1,7]

  - Now the next two elements i.e. 8 and 1 will be compared and both the elements will be swapped as 8 is greater than 1.
  
  [2,4,**8**,**1**,7] -> [2,4,**1**,**8**,7]

  - Now the last two elements will be compared i.e. 8 and 7 and it is clear that they will be swapped as 8 is greater than 7.

[2,4,1,**8**,**7**] -> [2,4,1,**7**,**8**]

Here the first round is complete and the array which we get after it is:
>> [2,4,1,7,8]

As we can see the array is not yet sorted so we will not stop here and go for another round.

#### <u>Round-2 </u>
 Now similar to  the first round we will again go with the complete swapping process starting from the first two elements.
 
 This round goes as:

 [**2**,**4**,1,7,8] -> [**2**,**4**,1,7,8] (No swapping required)

 [2,**4**,**1**,7,8] -> [2,**1**,**4**,7,8] 

 [2,1,**4**,**7**,8] -> [2,1,**4**,**7**,8] (No swapping required)

 [2,1,4,**7**,**8**] -> [2,1,4,**7**,**8**] (No swapping required)

 Here the second round is also complete and the array we get after the second round is:
 >> [2,1,4,7,8]

 As we can see the array is still not sorted so we will go for yet another round.

 #### <u>Round-3</u>

 We will go with the same swapping process again starting with the first two elements for this round as well.

 The third round goes as:

 [**2**,**1**,4,7,8] -> [**1**,**2**,4,7,8]

 [1,**2**,**4**,7,8] -> [1,**2**,**4**,7,8] (No swapping required)

 [1,2,**4**,**7**,8] -> [1,2,**4**,**7**,8] (No swapping required)

 [1,2,4,**7**,**8**] -> [1,2,4,**7**,**8**] (No swapping required)

 Here the third round is complete and the array we are getting after this round is:
 >> [1,2,4,7,8]

 It is clear that the array is completely sorted now 👍🏻 so this was our final round and there is no need of further rounds.

 ```
 👆🏻This way we got the sorted array using Bubble Sort Algorithm.
 ```
 ## C++ Code for Bubble Sort demonstration 

 ```cpp
 //unoptimised code
 #include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {6, 2, 9, 1, 7, 4};
    int n = arr.size();
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
               swap(arr[j],arr[j+1]);
            }
        }
    }
    cout << "Sorted array: ";
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

//optimised code, in best case scenario it will have a TC O(n)
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector <int> arr = {6, 2, 9, 1, 7, 4};
    int n = arr.size();
    int i, j;
    bool swapped;
    for (i = 0; i < n-1; i++) {
        swapped = false;
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swapped = true;
               swap(arr[j],arr[j+1]);
            }
        }
        if (swapped == false) {
            break;
        }
    }
    cout << "Sorted array: ";
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}


```
```
### Number of rounds/Passes required-
 As we saw that we require certain no. of rounds for the complete sorting using bubble sort which means we have to pass through the whole array for a certain no. of times.
 So here is the code to know how we can know the no. of passes required for bubble sort:
 ```
 ```cpp
 #include <bits/stdc++.h>
using namespace std;

int main() {
    vector <int> arr = {4,2,8,1,7};
    int n = arr.size();
    int i, j;
    int passes=0;
    bool swapped;
    for (i = 0; i < n-1; i++) {
        passes++;
        swapped = false;
        for (j = 0; j < n-i-1; j++) {
          // passes++; //we can do this with the above passes++ to get the total number of swaps.
            if (arr[j] > arr[j+1]) {
                swapped = true;
               swap(arr[j],arr[j+1]);
            }
        }
        if (swapped == false) {
            break;
        }
    }
    cout << "Sorted array: ";
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout<<passes<<endl;
    return 0;
}

```







