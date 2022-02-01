#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <ctime>
using namespace std;

class Vector
{
	int size = 0; // êîëè÷åñòâî äåéñòâèòåëüíî ïðèñóòñòâóþùèõ ýëåìåíòîâ â êîíòåéíåðå
	int capacity = 10; // ¸ìêîñòü (âìåñòèòåëüíîñòü, çàïàñ ïàìÿòè)
	int* data; // óêàçàòåëü íà äèíàìè÷åñêèé ìàññèâ äàííûõ

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


	void PushBack(int value)
	{
		// EnsureCapacity(size + 1); // ïðîâåðêà, õâàòèò ëè ìåñòà äëÿ íîâîãî ýëåìåíòà - äåëàéòå ñàìè ;)
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
		// îáíóëåíèå çíà÷åíèé ýëåìåíòîâ äåëàòü íåîáçÿòåëüíî
		// for (int i = 0; i < size; i++)
		// {
		//	 data[i] = 0;
		// }
		size = 0;
	}

	bool Equals(const Vector& another)const
	{
		if (size == another.size)
		{
			int result = 0;
			for (int i = 0; i < size; i++)
			{
				if (data[i] == another.data[i])
				{
					result++;
				}
			}
			return result == size;
		}

		return false;
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

	int IndexOf(int value)
	{
		for (int i = 0; i < size; i++)
		{
			if (this->data[i] == value)
			{
				return i;
			}
		}
		return -1;
	}

	int LastIndexOf(int value)
	{
		for (int i = size - 1; i >= 0; i--)
		{
			if (this->data[i] == value)
			{
				return i;
			}
		}
		return -1;
	}

	void Reverse()
	{
		reverse(data, data + size);
	}

	void SortAsc()
	{
		sort(data, data + size);
	}
	void SortDesc()
	{
		sort(data, data + size);
		Reverse();
	}

	void Shuffle()
	{
		random_shuffle(data, data + size);
	}

	void  RandomFill()
	{
		//generate(data, data + size, rand() % 10);	// íå ïîëó÷àåòñÿ (	
		for (int i = 0; i < size; i++)
		{
			data[i] = (rand() % 10);
		}
	}

	int GetElementAt(unsigned int index) const
	{
		if (index >= size) throw "Incorrect index!";
		return data[index];
	}

	Vector Clone(const Vector& clone) //ïåðåïîëíåíèå áóôåðà â data 
	{
		size = clone.size;
		capacity = clone.capacity;
		data = new int[clone.capacity];
		for (int i = 0; i < size; i++)
		{
			data[i] = clone.data[i];
		}
		return clone;
	}

	bool operator==(const Vector& another)
	{
		return Equals(another);
	}

	Vector operator=(const Vector& another)
	{
		return Clone(another);
	}

	const int& operator[](unsigned int index) const
	{
		if (index >= size) throw "Incorrect index!";
		return data[index];
	}
	friend istream& operator>>(istream& is, Vector& original)
	{
		/*size = original.size;
		data = new int[original.capacity];*/
		for (int i = 0; i <= original.size; i++)
		{
			is >> original.data[i];
		}
		return is;
	}
	// îñòàëüíûå ìåòîäû îáÿçàòåëüíî ïîÿâÿòñÿ çäåñü ;)
};

ostream& operator<<(ostream& os, Vector& original)
{
	original.Print();
	return os;
}



int main()
{
	srand(time(0));
	Vector ar;
	Vector ar1;
	cout << "Vector 1: \n";
	ar.PushBack(1);
	ar.PushBack(2);
	ar.PushBack(3);
	ar.Print();
	cout << "Index of 3: " << ar.IndexOf(3) << "\n";
	cout << "last index of 5: " << ar.LastIndexOf(5) << "\n";
	cout << "Element at index 2 is : " << ar.GetElementAt(2) << "\n";
	ar.PushFront(4);
	ar.Print();
	ar.Reverse();
	ar.Print();
	cout << "Ascending sort: \n";
	ar.SortAsc();
	ar.Print();
	cout << "Descending sort: \n";
	ar.SortDesc();
	ar.Print();
	cout << "Shuffle: \n";
	ar.Shuffle();
	ar.Print();
	cout << "Random fill: \n";
	ar.RandomFill();
	ar.Print();
	cout << "Vector 2: \n";
	ar1.PushBack(5);
	ar1.PushBack(6);
	ar1.PushBack(7);
	ar1.Print();
	cout << "Vector 1 = Vector 2? " << ar.operator==(ar1) << "\n";
	cout << "= Vector 2\n";
	ar.operator=(ar1);
	ar.Print();
	cout << "Clone 2: \n";
	ar.Clone(ar1);
	cout << ar;
	cout << "Clear all \n";
	ar.Clear();
	ar.Print();
}
