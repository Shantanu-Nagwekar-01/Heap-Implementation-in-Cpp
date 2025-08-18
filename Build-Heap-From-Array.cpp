#include <iostream>
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

int main()
{
    int arr[] = {10, 3, 8, 9, 5, 13, 18, 14, 11, 70};
    BuildMaxHeap(arr, 10);
    print(arr, 10);
    return 0;
}

//time complexity: O(n) for building max heap
//space complexity: O(1) no extra space
//for min heap just change signs in heapify if conditions for left and right node checks
//Output: The array elements are: 70 14 18 11 5 13 8 9 10 3 
