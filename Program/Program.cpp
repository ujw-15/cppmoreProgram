#include <iostream>

using namespace std;

template<typename T>
class List
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node* previous;
	};

	Node* head;
	Node* tail;
	int size;
public:
	List()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	
	void push_front(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		newNode->next = nullptr;
		newNode->previous = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->previous = newNode;
		
			newNode->next = head;

			head = newNode;
		}
		
		size++;
	}

	void pop_front()
	{
		if (head == nullptr)
		{
			cout << "linked list is empty" << endl;
		}
		else
		{
			Node* deleteNode = head;

			if (head == tail)
			{
				head = nullptr;
				tail = nullptr;
			}
			else
			{
				deleteNode->next->previous = nullptr;

				head = head->next;
			}

			delete deleteNode;

			size--;
		}
		
	}


	void push_back(T data)
	{
		Node* newNode = new Node;
		
		newNode->data = data;
		newNode->next = nullptr;
		newNode->previous = nullptr;

		if (tail == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;

			newNode->previous = tail;

			tail = newNode;
		}

		size++;
	}

	const bool& empty()
	{
		return	head == nullptr;
	}

	~List()
	{
		while (head != nullptr)
		{
			pop_front();
		}
	}
};

int main()
{
	List<int>list;

	list.push_front(10);
	list.push_front(5);
	
	list.push_back(20);
	list.push_back(30);

	list.pop_front();
	list.pop_front();
	list.pop_front();


	return 0;
}


