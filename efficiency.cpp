#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <math.h>
using namespace std;
#define MAXSIZE 1000000
main()
{
    int n; // The size of the problem
    clock_t oldtime, newtime;
    double seconds;
    int bigarray[MAXSIZE];
    
    for(int i = 0; i < MAXSIZE; i++) // Initialize to random numbers
        bigarray[i] = rand();
    cout << "Enter an integer "<<endl;
    cin >> n;
    if((n < 0) || (n >= MAXSIZE)) { // If out of Range
        exit(0);
    }
    
    
    // First try an O(n) Algorithm to search for a value
    oldtime = clock(); 
    int value = 43;
    int found = 0;
    for(int i = 0; i < n; i++) {
        if(value == bigarray[i]) {
            found++;
        }
    }
    
    newtime = clock();
    
    seconds = (double)(newtime-oldtime)/CLOCKS_PER_SEC;
    cout << "O(n) search took "<<seconds<<endl;
    
    // Now do a nlogn algorithm
    oldtime = clock(); 
    
    double mylog = log2(n);
    for(int l=0; l<mylog; l++) {
      for(int i = 0; i < n; i++) {
        if(value == bigarray[i]) {
            found++;
        }
      }
    }
    
    newtime = clock();
    
    seconds = (double)(newtime-oldtime)/CLOCKS_PER_SEC;
    cout << "O(nlogn) search took "<<seconds<<endl;
    
    // Now try an O(n^2) Algorithm to determine if values are unique
    oldtime = clock();
    int notUnique = 0;
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < n; i++) {
            if(bigarray[i] == bigarray[j]) {
                notUnique++;
            }
        }
    }
    
    newtime = clock();
    
    seconds = (double)(newtime-oldtime)/CLOCKS_PER_SEC;
    cout << "n^2 took "<<seconds<<endl;
    // Now try an O(n^2-n) Algorithm to determine if values are unique
    notUnique = 0;
    oldtime = clock(); 
    for(int j = 0; j < n; j++) {
        for(int i = j; i < n; i++) {
            if(bigarray[i] == bigarray[j]) {
                notUnique++;
            }
        }
    }
    
    newtime = clock();
    seconds = (double)(newtime-oldtime)/CLOCKS_PER_SEC;
    cout << "n^2-n took "<<seconds<<endl;
    
    notUnique = 0;
    oldtime = clock(); 
    for(int k = 0; k < n; k++) {
      for(int j = 0; j < n; j++) {
        for(int i = j; i < n; i++) {
            if(bigarray[i] == bigarray[j]) {
                notUnique++;
            }
        }
      }
    }
    
    newtime = clock();
    seconds = (double)(newtime-oldtime)/CLOCKS_PER_SEC;
    cout << "n^3 took "<<seconds<<endl;
    
}
