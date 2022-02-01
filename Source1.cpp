#include <iostream>
using namespace std;

class Vector
{
	int size = 0; // количество действительно присутствующих элементов в контейнере
	int capacity = 10; // ёмкость (вместительность, запас памяти)
	int* data; // указатель на динамический массив данных

	void EnsureCapacity(int new_size)
	{
		if (capacity < new_size)
		{
			capacity = capacity / 2 + 1;
			int* copy = new int[capacity];
			for (int i = 0; i < size; i++)
			{
				copy[i] = data[i];
				delete[] data;
				data = copy;
			}
		}
	}

public:
	Vector() : Vector(10)
	{
		// cout << "C-TOR WITHOUT PARAMS!\n";
	}

	Vector(int capacity)
	{
		if (capacity < 10)
		{
			capacity = 10;
		}
		this->capacity = capacity;
		data = new int[capacity];
		// cout << "C-TOR WITH PARAMS!\n";
	}

	~Vector()
	{
		// cout << "DESTRUCTOR!\n";
		if (data != nullptr) delete[] data;
	}

	void SetCapacity(int capacity)
	{
		this->capacity = capacity;
	}

	int GetSize()
	{
		return size;
	}

	int GetCapacity()
	{
		return capacity;
	}

	void PushBack(int value)
	{
		// EnsureCapacity(size + 1); // проверка, хватит ли места для нового элемента - делайте сами ;)
		data[size++] = value;
	}

	void PushFront(int value)
	{
		// EnsureCapacity(size + 1);
		for (int i = size; i > 0; i--)
		{
			data[i] = data[i - 1];
		}
		data[0] = value;
		size++;
	}

	void Clear()
	{
		// обнуление значений элементов делать необзятельно
		// for (int i = 0; i < size; i++)
		// {
		//	 data[i] = 0;
		// }
		size = 0;
	}

	bool IsEmpty() const
	{
		return size == 0;
	}

	void Print() const
	{
		if (IsEmpty())
		{
			cout << "Vector is empty.\n";
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				cout << data[i] << " ";
			}
			cout << endl;
		}
	}

	// остальные методы обязательно появятся здесь ;)
};

int main()
{
	Vector ar;
	ar.PushBack(1);
	ar.PushBack(2);
	ar.PushBack(3);
	ar.Print();
	ar.PushFront(4);
	ar.Print();
	ar.Clear();
	ar.Print();
}