// Vector v0.5
#include <iostream>

using namespace std;

// 원소의 개수
int Size = 0;

// 최대 수용 개수
int Capacity = 0;

// 컨테이너
int* Vector = nullptr;

// 컨테이너의 마지막 위치에 값을 추가
void push_back(const int& _Value);

// 컨테이너의 마지막 위치의 값을 삭제
void pop_back();

int front();
int back();

// 특정 위치 값을 삭제
void Delete(const int& _where);

// 숙제 : 특정 위치에 데이터를 삽입하는 함수 만들기
void Insert(const int& _where, const int& _Value);

int main(void)
{
	for (int i = 0; i < 10; ++i)
		push_back(i * 100 + 100);

	pop_back();

	Delete(4);

	Insert(4, 666);

	// 출력
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
	if (Size >= Capacity)
	{
		Capacity += (Capacity <= 3) ? 1 : Capacity >> 1;

		int* Temp = new int[Capacity];

		for (int i = 0; i < Size; ++i)
			Temp[i] = Vector[i];

		if (Vector)
		{
			delete[] Vector;
			Vector = nullptr;
		}

		Temp[Size] = _Value;
		Vector = Temp;
	}
	else
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

void Delete(const int& _where)
{
	// 특정 위치에 있는 원소를 삭제하고 정렬
	--Size;
	for (int i = _where + (-1); i < Size; ++i)
		Vector[i] = Vector[i + 1];
}

void Insert(const int& _where, const int& _Value)
{
	++Size;
	for (int i = Size; i > _where + (-1); --i)
		Vector[i] = Vector[i - 1];

	Vector[_where + (-1)] = _Value;
}