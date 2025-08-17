#include<iostream>
using namespace std;

void BuildMaxHeap(int arr[], int n) {
    //step down approach
    for (int i = n/2 - 1; i >= 0; i--) {
        Heapify(arr, i, n);
    }
}

int main() {
    int arr [] = {10, 3, 8, 9, 5, 13, 18, 14, 11, 70};
    BuildMaxHeap(arr, 10);
}