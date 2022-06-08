// Vector v0.6
#include <iostream>

using namespace std;

// 현재 원소의 개수
int Size = 0;

// 최대 수용 개수
int Capacity = 0;

// 컨테이너
int* Vector = nullptr;

// 컨테이너의 마지막 위치에 값을 추가
void push_back(const int& _Value);

// 컨테이너의 마지막 위치의 값을 삭제
void pop_back();

// 가장 앞쪽에 있는 원소
int front();

// 가장 뒤쪽에 있는 원소
int back();

// _where 의 위치에 데이터 삭제
void erase(const int& _where);

// _where 의 위치에 데이터 추가
void insert(const int& _where, const int& _Value);

int main(void)
{
	// 값 추가
	for (int i = 0; i < 10; ++i)
		push_back(i * 1 + 1);

	//pop_back();

	//erase(4);

	insert(4, 666);

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
	// 만약 더 이상 수용할 수 있는 공간이 없다면
	if (Size >= Capacity)
	{
		// 현재 수용량이 4보다 작다면 1씩 증가하고, 
		// 현재 수용량이 4보다 크거나 같다면 현재 수용량의 1/2 만큼 추가함
		Capacity += (Capacity <= 3) ? 1 : Capacity >> 1;

		// 임시 저장소를 생성
		int* Temp = new int[Capacity];

		// 생성된 공간을 초기화 함
		for (int i = 0; i < Capacity; ++i)
			Temp[i] = NULL;

		// 기존에 있던 값을 복사
		for (int i = 0; i < Size; ++i)
			Temp[i] = Vector[i];

		// 기존의 값을 삭제
		if (Vector)
		{
			delete[] Vector;
			Vector = nullptr;
		}

		// 임시값에 새 값을 추가
		Temp[Size] = _Value;

		// 임시값을 기존 벡터에 추가
		Vector = Temp;
	}
	else
		// 마지막 위치에 값 추가
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
	// 특정 위치에 있는 원소를 삭제하고 정렬
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
