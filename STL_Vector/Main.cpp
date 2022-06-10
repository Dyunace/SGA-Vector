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

	// ���� �տ� �ִ� ���Ҹ� ��ȯ
	vecNumbers.front();

	// ���� �ڿ� �ִ� ���Ҹ� ��ȯ
	vecNumbers.back();

	// ���� �������� ����Ű�� �ݺ���
	vecNumbers.begin();

	// ���� �������� ����Ű�� �ݺ���
	vecNumbers.end();

	/*
	for (int i = 0; i < 10; ++i)
		//cout << *(iterator + i) << endl;	// �Ʒ��� ����
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