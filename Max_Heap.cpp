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

        void Heapify(int index) {
            //iterative approach
            while(true) {
                int largest = index;
                int left = 2 * index + 1;
                int right = 2 * index + 2;

                if (left < size && arr[left] > arr[largest]) {
                    largest = left;
                }

                if (right < size && arr[right] > arr[largest]) {
                    largest = right;
                }

                if (largest != index) {
                    swap(arr[largest], arr[index]);
                    index = largest;
                }
                else {
                    break;
                }
            }
        }

        void remove() {
            // heap underflow check
            if (size == 0) {
                cout<<"Heap Underflow"<<endl;
                return;
            }
            int top = arr[0];
            arr[0] = arr[size-1];
            size--;
            Heapify(0);
            cout<<top<<" is deleted\n";
            return;
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

        int top() {
            // heap underflow check
            if (size == 0) {
                cout<<"Heap is empty\n";
                return -1;
            }
            return arr[0];
        }
};

int main() {
    MaxHeap H1(5);
    for (int i = 0; i < 5; i++) {
        H1.insert(i+1);
    }
    H1.print();
    H1.insert(5);
    H1.remove();
    cout<<"The Max Element is: "<<H1.top()<<endl;
    H1.print();
    return 0;
}

/*
Max Heap Implementation

Time Complexity:
- insert(val): O(log n)   // because we may need to "bubble up" through heap levels
- remove(): O(log n)      // because we call Heapify, which may traverse log n levels
- Heapify(index): O(log n)
- top(): O(1)             // just returning the root
- print(): O(n)           // printing all elements

Space Complexity:
- O(n) for the dynamic array to store heap elements
*/


//Output:
/*
Heap Elements are: 5 4 2 1 3 
Heap Overflow
5 is deleted
The Max Element is: 4
Heap Elements are: 4 3 2 1 
*/