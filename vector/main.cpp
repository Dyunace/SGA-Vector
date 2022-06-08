// Vector v0.6
#include <iostream>

using namespace std;

// ���� ������ ����
int Size = 0;

// �ִ� ���� ����
int Capacity = 0;

// �����̳�
int* Vector = nullptr;

// �����̳��� ������ ��ġ�� ���� �߰�
void push_back(const int& _Value);

// �����̳��� ������ ��ġ�� ���� ����
void pop_back();

// ���� ���ʿ� �ִ� ����
int front();

// ���� ���ʿ� �ִ� ����
int back();

// _where �� ��ġ�� ������ ����
void erase(const int& _where);

// _where �� ��ġ�� ������ �߰�
void insert(const int& _where, const int& _Value);

int main(void)
{
	// �� �߰�
	for (int i = 0; i < 10; ++i)
		push_back(i * 1 + 1);

	//pop_back();

	//erase(4);

	insert(4, 666);

	// ���
	for (int i = 0; i < Size; ++i)
		cout << "Vector[" << i << "] : " <<  Vector[i] << endl;
	cout << "Size : " << Size << endl;
	cout << "Capacity : " << Capacity << endl << endl;

	cout << front() << endl;
	cout << back() << endl;

	return 0;
}

void push_back(const int& _Value)
{
	// ���� �� �̻� ������ �� �ִ� ������ ���ٸ�
	if (Size >= Capacity)
	{
		// ���� ���뷮�� 4���� �۴ٸ� 1�� �����ϰ�, 
		// ���� ���뷮�� 4���� ũ�ų� ���ٸ� ���� ���뷮�� 1/2 ��ŭ �߰���
		Capacity += (Capacity <= 3) ? 1 : Capacity >> 1;

		// �ӽ� ����Ҹ� ����
		int* Temp = new int[Capacity];

		// ������ ������ �ʱ�ȭ ��
		for (int i = 0; i < Capacity; ++i)
			Temp[i] = NULL;

		// ������ �ִ� ���� ����
		for (int i = 0; i < Size; ++i)
			Temp[i] = Vector[i];

		// ������ ���� ����
		if (Vector)
		{
			delete[] Vector;
			Vector = nullptr;
		}

		// �ӽð��� �� ���� �߰�
		Temp[Size] = _Value;

		// �ӽð��� ���� ���Ϳ� �߰�
		Vector = Temp;
	}
	else
		// ������ ��ġ�� �� �߰�
		Vector[Size] = _Value;

	++Size;

	cout << "Value : " << _Value << endl;
	cout << "Size : " << Size << endl;
	cout << "Capacity : " << Capacity << endl << endl;
}

void pop_back()
{
	--Size;
}

int front()
{
	return Vector[0];
}

int back()
{
	return Vector[Size - 1];
}

void erase(const int& _where)
{
	// Ư�� ��ġ�� �ִ� ���Ҹ� �����ϰ� ����
	--Size;
	for (int i = _where + (-1); i < Size; ++i)
		Vector[i] = Vector[i + 1];
}

void insert(const int& _where, const int& _Value)
{
	if (Size >= Capacity)
		Capacity += (Capacity <= 3) ? 1 : Capacity >> 1;

	int* Temp = new int[Capacity];

	for (int i = 0; i < Capacity; ++i)
		Temp[i] = NULL;

	for (int i = 0; i < _where; ++i)
		Temp[i] = Vector[i];

	Temp[_where] = _Value;
	++Size;

	for (int i = _where + 1; i < Size; ++i)
		Temp[i] = Vector[i - 1];

	if (Vector)
	{
		delete[] Vector;
		Vector = nullptr;
	}

	Vector = Temp;
}
