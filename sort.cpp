int partition(int A[], int p, int r) {
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

void sort_quick(int A[], int p, int r) {
	if (p < r) {
		int pivot = partition(A, p, r);
		sort_quick(A, p, pivot - 1);
		sort_quick(A, pivot + 1, r);
	}
}

void maxHeapify(int A[], int heapsize, int i) {
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

void buildMaxHeap(int A[], int heapsize) {
	int i = (heapsize - 1) / 2;
	while(i >= 0) {
		maxHeapify(A, heapsize, i);
		i--;
	}
}

void sort_heap(int A[], int heapsize) {
	buildHeap(A, heapsize);
	for(int i = heapsize - 1; i > 0; i--) {
		swap(A[0], A[i]);
		maxHeapify(A, i, 0);
	}
}
