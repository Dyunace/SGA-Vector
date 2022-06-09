#include <iostream>
#include <vector>

using namespace std;


int main(void)
{

	vector<int> vecNumbers;

	for (int i = 0; i < 10; ++i)
		vecNumbers.push_back(10 * i);

	for (vector<int>::iterator iter = vecNumbers.begin();
		iter != vecNumbers.end(); ++iter)
		cout << (*iter) << endl;
		

	/*
	int Array[16];
	for (int i = 0; i < 16; ++i)
		Array[i] = i + 1;

	int* iterator = Array;

	for (int i = 0; i < 16; ++i)
		cout << Array[i] << endl;

	for (int i = 0; i < 16; ++i)
		cout << *(iterator + i) << endl;
	*/

	return 0;
}