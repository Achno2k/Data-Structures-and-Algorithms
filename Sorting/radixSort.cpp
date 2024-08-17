#include <iostream>
#include <cmath>
using namespace std;

//Time complexity --> O(n)
//Space complexity --> O(n)

class Node{
public:
	int data;
	Node* next;
};

int findMax(int A[], int n){
	int max = A[0];
	for(int i=0; i<n; i++){
		if(max < A[i])
			max = A[i];
	}
	return max;
}

void Insert(Node** bins, int index, int val){
	Node* temp = new Node;
	temp->data = val;
	temp->next = nullptr;

	if(bins[index] == nullptr)
		bins[index] = temp;
	else{
		Node* p = bins[index];
		while(p->next != nullptr)
			p = p->next;

		p->next = temp;
	}
}

int Delete(Node** bins, int index){
	Node* p = bins[index];
	bins[index] = bins[index]->next;
	int x = p->data;
	delete p;
	return x;
}
 
int iteration(int max){
	int count{0};
	while(max != 0){
		max /= 10;
		count++;
	}
	return count;
}

int binIndex(int val, int pass){
	return (int)(val / pow(10, pass)) % 10;
}

void radixSort(int A[], int n){
	Node** bins = new Node*[10]{nullptr};
	int max = findMax(A, n);
	int limit = iteration(max);

	for(int i=0; i<limit; i++){
		for(int j=0; j<n; j++){
			int index = binIndex(A[j], i);
			Insert(bins, index, A[j]);
		}

		int k{0};
		for(int j=0; j<10; j++){
			while(bins[j] != nullptr){
				A[k++] = Delete(bins, j);
			}
		}

		for(int i=0; i<10; i++)
			bins[i] = nullptr;
	}

	delete[] bins;
}

void print(int A[], int n){
	for(int i=0; i<n; i++)
		cout << A[i] << " ";
}

int main()
{
	int A[] = {237, 146, 259, 348, 152, 163, 235, 48, 36, 62};
	radixSort(A, sizeof(A)/sizeof(A[0]));
	cout << "Sorted array: ";
	print(A, sizeof(A)/sizeof(A[0])); 

	return 0;
}



