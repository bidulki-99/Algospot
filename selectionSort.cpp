void selectionSort(vector<int>& A) {
	for (int i = 0; i < A.size(); i++) {
		int minIndex = i;
		
		for (int j = i + 1; j < A.size(); j++)
			if (A[minIndex] > A[j])
				minIndex = j;

		swap(A[i], A[minIndex]);
	}
}
