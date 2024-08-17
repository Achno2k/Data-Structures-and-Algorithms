#include <iostream>
using namespace std;

int Hash(int key){
	return key%10;
}

int probe(int HT[], int key){
	int index = Hash(key);
	int i = 0;

	while(HT[(index+i)%10] != 0)
		i++;
	return (index+i)%10;
}

void Insert(int HT[], int key){
	int index = Hash(key);
	if(HT[index] != 0){
		index = probe(HT, key);
	}
	HT[index] = key;
}

int Search(int H[], int key){
    int index = Hash(key);
    int i = 0;
    while (H[(index+i) % 10] != key){
        i++;
        if (H[(index + i) % 10] == 0){
            return -1;
        }
    }
    return (index + i) % 10;
}


int main()
{
	int HT[10] = {0};
	Insert(HT, 32);
	Insert(HT, 21);
	Insert(HT, 12);
	Insert(HT, 45);

	cout << "Successfull Search: " << Search(HT, 12) << endl;
	cout << "Unsuccessfull Search: "<< Search(HT, 35) << endl;

	return  0;
}