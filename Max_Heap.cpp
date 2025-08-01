#include<iostream>
using namespace std;

class MaxHeap {
    int *arr;
    int size; // total elements present in heap
    int capacity;
public:
    MaxHeap(int n) {
        capacity = n;
        arr = new int[n]; //dynamic memory allocation 
        size = 0;
    }
    
    void insert(int val) {
        //heap overflow check
        if (size == capacity) {
            cout << "Heap Overflow" << endl;
            return;
        }
        
        // memory space available 
        int index = size;
        arr[size++] = val;
        
        
        //step up to set element in correct position 
        
        while (index > 0 && arr[(index-1)/2] < arr[index]) {
            swap(arr[(index-1)/2], arr[index]);
            index = (index - 1) / 2;
        }
        }
        
       void print() {
            cout << "Heap Elements are: ";
            for (int i = 0; i < size; i++) {
                cout<<arr[i]<<" ";
            }
            cout  << endl;
        }
        ~MaxHeap() {
            delete[] arr;
        }
};

int main() {
    MaxHeap H1(5);
    for (int i = 0; i < 5; i++) {
        H1.insert(i+1);
    }
    H1.print();
    H1.insert(5);
    return 0;
}