#include <iostream>
using namespace std;

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

void Insert(Node** bins, int index){
	Node* temp = new Node;
	temp->data = index;
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
	int x = p->data;
	bins[index] = p->next;
	delete p;
	return x;
}

void binSort(int A[], int n){
	int m = findMax(A, n);
	Node** bins = new Node*[m+1]{nullptr};

	for(int i=0; i<n; i++)
		Insert(bins, A[i]);

	int j=0;
	for(int i=0; i<m+1; i++){
		while(bins[i] != nullptr){
			A[j++] = Delete(bins, i);
		}
	}
}
void print(int A[], int n){
	for(int i=0; i<n; i++)
		cout << A[i] << " ";
}

int main()
{
	int A[] = {8, 5, 7, 3, 2};
	binSort(A, sizeof(A)/sizeof(A[0]));
	cout << "Sorted array: ";
	print(A, sizeof(A)/sizeof(A[0])); 

	return 0;
}