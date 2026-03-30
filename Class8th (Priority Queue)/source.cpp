#include <iostream>

using namespace std;
template<typename T>
class PriorrtyQueue
{
private:
	int index;
	int capacity;

	T* container;
public:
	PriorrtyQueue()
	{
		index = 0;
		capacity = 0;
		container = nullptr;
	}

	void resize(int newSize)
	{

		capacity = newSize;

		T* temporary = new T[capacity];

		for (int i = 0; i < capacity; i++)
		{
			temporary[i] = NULL;
		}

		for (int i = 0; i < index; i++)
		{
			temporary[i] = container[i];
		}
		delete[] container;

		container = temporary;

	}

	void push(T data)
	{
		if (capacity <= 0)
		{
			resize(1);
		}
		else if (index >= capacity)
		{
			resize(capacity * 2);
		}

		container[index++] = data;

		int child = index - 1;
		int parent = (child - 1) / 2;

		while (child > 0)
		{
			if (container[parent] < container[child])
			{
				std::swap(container[parent], container[child]);
			}

			child = parent;

			parent = (child - 1) / 2;
		}
	}

	void pop()
	{
		if (index <= 0)

		{
			cout << "priority queue is empty" << endl;
		}
		else
		{
			container[0] = container[--index];

			container[index] = NULL;

			int parent = 0;
			int child = parent * 2 + 1;

			while (child < index)
			{
				child = parent * 2 + 1;

				if (container[child] < container[child + 1])
				{
					child++;
				}

				if (container[child] < container[parent])
				{
					break;
				}
				else
				{
					std::swap(container[child], container[parent]);

					parent = child;
				}
			}
		}
	}

	~PriorrtyQueue()
	{
		if (container != nullptr)
		{
			delete[] container;
		}
	}

	const T& top()
	{
		return container[0];
	}

	const int& size()
	{
		return size;
	}

	const bool& empty()
	{
		return index <= 0;
	}
};

int main()
{
	PriorrtyQueue<int>priorrtyQueue;

	priorrtyQueue.push(10);
	priorrtyQueue.push(50);
	priorrtyQueue.push(70);
	priorrtyQueue.push(5);
	priorrtyQueue.push(30);

	while (priorrtyQueue.empty() == false)
	{
		cout << priorrtyQueue.top() << endl;

		priorrtyQueue.pop();
	}

	cout << "Priority Queue is Size : " << priorrtyQueue.size() << endl;

	return 0;
}

