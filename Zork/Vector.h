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
			capacity += 8;
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
	bool pop_back(TYPE& value)
	{
		if (value.num_elements > 0){
			value.num_elements--;
			return true;
		}
		return false;
	}

	TYPE Pop_Back()
	{
		if (num_elements > 0)
		{

			num_elements--;

			return buffer[num_elements];
		}

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
			for (unsigned int i = num_elements - 1; i >= 0; i--)
			{


				temp[i] = buffer[i - 1];


			}

			buffer[0] = element;
			num_elements++;

		}

		bool empty() const
		{
			return buffer[0] == '\0';
		}



		void size()const
		{
			return num_elements;
		}

		const TYPE& operator[](const unsigned int &index)const
		{
			assert(indez >= 0 && index < num_elements)
				return buffer[index];


		}
		const TYPE operator[](const unsigned int &index)const
		{
			assert(indez >= 0 && index < num_elements)
				return buffer[index];
		}

		void PrintVector()const
		{
			for (unsigned int i = 1; i < num_elements; i++)
			{
				printf("%i", buffer[i]);
			}
		}

		void clear()
		{
			num_elements = 0;
		}
		~Vector()
		{
			printf("Destruction");
			delete[] buffer;
		}

	};