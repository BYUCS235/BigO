# BigO
Once you have eliminated syntax errors and logic errors that cause your code to return the wrong values, you then need to find performance bugs or problems that make your code take longer to run than it needs to.  The order notation provides a way to talk about the efficiency of your code.

We can say that a program or block of code takes O(n) if the time to run is some constant times the size of the problem.  For example, the following loop is O(n) since it will go through the loop n times.
```c++
    int value = 43;
    int found = 0;
    for(int i = 0; i < n; i++) {
        if(value == bigarray[i]) {
            found++;
        }
    }
```
Almost any algorithm will take at least O(n) because it will need to look at each data element at least once.  The major exception is looking for a value in an index which takes O(logn)

The next class of algorithms take O(nlogn) and include sorting.  These are not much worse than O(n).
```c++
    double mylog = log2(n);
    for(int l=0; l<mylog; l++) {
      for(int i = 0; i < n; i++) {
        if(value == bigarray[i]) {
            found++;
        }
      }
    }
```
Although this will take longer, the difference is not as significant as O(n^2).
```c++
    int notUnique = 0;
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < n; i++) {
            if(bigarray[i] == bigarray[j]) {
                notUnique++;
            }
        }
    }
```
This code will look through every pair twice, so you might think it would be good to create an algorithm that only goes through the inner loop for half of the array.  Although this is approximately n^2-n, it really doesnt make as much difference as the difference between O(nlogn) and O(n^2).
```c++
    for(int j = 0; j < n; j++) {
        for(int i = j; i < n; i++) {
            if(bigarray[i] == bigarray[j]) {
                notUnique++;
            }
        }
    }
```
Finally, you can see and O(n^3) algorithm is much worse than the O(n^2)
```c++
    for(int k = 0; k < n; k++) {
      for(int j = 0; j < n; j++) {
        for(int i = j; i < n; i++) {
            if(bigarray[i] == bigarray[j]) {
                notUnique++;
            }
        }
      }
    }
```
