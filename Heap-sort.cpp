#include<iostream>
using namespace std;


void print(int arr[], int n)
{
    cout << "The array elements are: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Heapify(int arr[], int i, int n)
{
    while (true)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
        {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            i = largest;
        }
        else
        {
            break;
        }
    }
}

void BuildMaxHeap(int arr[], int n)
{
    // step down approach
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Heapify(arr, i, n);
    }
}

void HeapSort(int arr[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[i],arr[0]);
        Heapify(arr, 0, i);
    }
}
int main() {
    int arr[] = {23, 34, 64, 7, 37, 43, 97};
    int n = sizeof(arr) / sizeof(int);
    BuildMaxHeap(arr, n);
    print(arr, n);
    cout<<"Sorted Array after appying Heap Sort:\n";
    HeapSort(arr, n);
    print(arr, n);
    return 0;
}

/*
Time Complexity: O(nlogn) n times logn of heapify
Space Complexity:auxilliary space complexity ->  O(1) in-place sorting; total space complexity is O(n)
Output:
The array elements are: 97 37 64 7 34 43 23 
Sorted Array after appying Heap Sort:
The array elements are: 7 23 34 37 43 64 97 
*/