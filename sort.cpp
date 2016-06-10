/*
* add main function for test all the sort algorithm
*/
#include<vector>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

void printArray(vector<int> data) {
	for(int i = 0; i < data.size(); i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
}

int main(){
	vector<int> testData(10);
	srand((unsigned int)time(NULL));
	for(int i = 0; i < 10; i++) {
		testData[i] = rand()%100;
	}
	printArray(testData);//print the initialized array
	//sort the arrat
	printArray(testData);//print the result of sorted array
	return 0;
}

/*
* implement quick sort
*/

int partition(vector<int> &A, int p, int r) {
	int x = A[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (A[j] < x) {
			swap(A[j], A[++i]);
		}
	}
	swap(A[i+1], A[r]);
	return i+1;	
}

void sort_quick(vector<int> &A, int p, int r) {
	if (p < r) {
		int pivot = partition(A, p, r);
		sort_quick(A, p, pivot - 1);
		sort_quick(A, pivot + 1, r);
	}
}


/*
* implement max heap sort
*/

void maxHeapify(vector<int> &A, int heapsize, int i) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int largest = i;
	if (left < heapsize && A[left] > A[largest]) {
		largest = left;
	}
	if (right < heapsize && A[right] > A[largest]) {
		largest = right;
	}
	if (largest != i) {
		swap(A[i], A[largest]);
		maxHeapify(A, heapsize, largest);
	}
}

void buildMaxHeap(vector<int> &A, int heapsize) {
	int i = (heapsize - 1) / 2;
	while(i >= 0) {
		maxHeapify(A, heapsize, i);
		i--;
	}
}

void sort_heap(vector<int> &A, int heapsize) {
	buildHeap(A, heapsize);
	for(int i = heapsize - 1; i > 0; i--) {
		swap(A[0], A[i]);
		maxHeapify(A, i, 0);
	}
}

/*
* implement merge sort
*/
void msort(vector<int> &A, int p, int r) {
	if (p < r) {
		int q = p + (r - p)/2;
		msort(A, p, q);
		msort(A, q + 1, r);
		merge(A, p, q, r);
	}
}
void merge(vector<int> &A, int p, int q, int r) {
	int len1 = q - p + 1;
	int len2 = r - q;
	vector<int> left(len1 + 1);
	vector<int> right(len2 + 1);
	left[len1] = right[len2] = INT_MAX;// set the sentinel
	for(int i = 0; i < len1; i++) {
		left[i] = A[p + i];
	}
	for(int j = 0; j < len2; j++) {
		right[j] = A[q + 1 + j];	
	}	
	int i = j = 0;
	for(int k = p; k < q+1; k++) {
		if (left[i] < right[j]) {
			A[k] = left[i++];
		} else {
			A[k] = right[j++];
		}
	}
}
/*
* implement shell sort
*/
