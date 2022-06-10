//STL_Vector v0.2
#include <iostream>
#include <vector>

using namespace std;


int main(void)
{
	int MAX = 50;

	vector<int> vecNumbers;

	for (int i = 0; i < 10; ++i)
	{
		vecNumbers.push_back(10 * i);
		
		//cout << "capacity : " << vecNumbers.capacity() << endl;
		//cout << "size : " << vecNumbers.size() << endl << endl;
	}

	// 가장 앞에 있는 원소를 반환
	vecNumbers.front();

	// 가장 뒤에 있는 원소를 반환
	vecNumbers.back();

	// 가장 시작점을 가르키는 반복자
	vecNumbers.begin();

	// 가장 시작점을 가르키는 반복자
	vecNumbers.end();

	/*
	for (int i = 0; i < 10; ++i)
		//cout << *(iterator + i) << endl;	// 아래와 같음
		cout << *(iterator++) << endl;
	*/

	/*
	for (vector<int>::iterator iter = vecNumbers.begin();
		iter != vecNumbers.end(); ++iter)
		cout << (*iter) << endl;

	for (auto iter = vecNumbers.begin();
		iter != vecNumbers.end(); ++iter)
		cout << (*iter) << endl;
	*/

	/*
	for (auto iter = vecNumbers.begin(); iter != vecNumbers.end();)
	{
		if ((*iter) > MAX)
			iter = vecNumbers.erase(iter);
		else
			++iter;
	}

	for (auto iter = vecNumbers.begin(); iter != vecNumbers.end(); ++iter)
	{
		cout << (*iter) << endl;
	}
	*/

	return 0;
}