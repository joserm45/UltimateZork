#include <stdio.h>

template <class TYPE>

class Vector
{
private:
	TYPE* buffer = nullptr;
	unsigned int capacity = 5;
	unsigned int num_elements = 0;

public:
	Vector()
	{


		buffer = new TYPE[capacity];

	}
	Vector(const Vector& other)
	{

		capacity = other.capacity;
		num_elements = other.num_elements;
		buffer = new TYPE[capacity];
		for (unsigned int i = 0; i < num_elements; i++)
		{
			buffer[i] = other.buffer[i];
		}

	}
	TYPE* operator [] (int)
	{

		return buffer[int];
	}
	void push_back(const TYPE& element)
	{
		TYPE* temp = nullptr;
		if (capacity == num_elements)
		{
			capacity *= 2;
			temp = new TYPE[capacity];

			for (unsigned int i = 0; i < num_elements; i++)
			{
				temp[i] = buffer[i];
			}

			delete[]buffer;
			buffer = temp;
		}

		buffer[num_elements++] = element;

	}

	void push_front(const TYPE& element)
	{
		TYPE* temp = nullptr;
		if (capacity == num_elements)
		{
			capacity *= 2;
			temp = new TYPE[capacity];

			for (unsigned int i = 0; i < num_elements; i++)
			{
				temp[i] = buffer[i];
			}

			delete[]buffer;
			buffer = temp;
			num_elements++;
		}
		temp = new TYPE[capacity];
		for (unsigned int i = num_elements; i >= 0; i - *-)
		{


			temp[i] = buffer[i - 1];


		}

		buffer[0] = element;
		num_elements++;

	}

	void PrintVector()const
	{
		for (unsigned int i = 1; i < num_elements; i++)
		{
			printf("%i", buffer[i]);
		}
	}
	~Vector()
	{
		printf("Destruction");
		delete[] buffer;
	}

};