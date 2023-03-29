Binary Search is a searching algorithm . 
Search time is O(log n) where n is the number of elements in the binary search . :)

Code for binary Search : 
```cpp

    // given an array and we have to find a target element
    int start = 0;
    int end = arr.size() -1; 

    while (start < end){
        int mid = start + (start - end)/2 ;
        if(mid == target){
            answer = arr[mid];
        }
        else if(mid > target){
            start = mid + 1 
        }
        else{
            end = mid - 1 ;
        }
    }
    

```