#include <iostream>
#include <vector>
using namespace std;
// Function to perform heap sort
void heapify(vector<int>& arr, int n, int parent) {
    int smallest = parent;
    int leftChild = 2 * parent + 1;
    int rightChild = 2 * parent + 2;
    if (leftChild < n && arr[leftChild] < arr[smallest]) 
        smallest = leftChild;
    if (rightChild < n && arr[rightChild] < arr[smallest]) 
        smallest = rightChild;
    if (smallest != parent) {
        swap(arr[parent], arr[smallest]);
        heapify(arr, n, smallest);
    }
}
void buildHeap(vector<int>& arr, int n) {
    for(int i=(n/2)-1;i>=0;i--)
    	heapify(arr, n, i);
}
void heapSort(vector<int>& arr) {
    int n = arr.size();
    buildHeap(arr, n);
    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
int main() {
    int i,n,x;
    cout<<"Heap sort\n";
    cout<<"Enter number of elements:";
    cin>>n;
	vector<int> arr,brr;
    for(i=0;i<n;i++)
    {
    	cin>>x;
    	arr.push_back(x);   	
	}
    heapSort(arr);
	cout<<"Sorted array:\n";
    for (int num : arr) 
        cout << num << " ";
    return 0;
}
