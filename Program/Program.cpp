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
	};

	Node* head;
	int size;
public:
	List()
	{
		head = nullptr;
		size = 0;
	}

	void push_back(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;

		if (head == nullptr)
		{
			head = newNode;

			newNode->next = head;
		}
		else
		{
			newNode->next = head->next;

			head->next = newNode;

			head = newNode;
		}
	
		size++;
	}

	void pop_back()
	{
		Node* deleteNode = head;
		Node* currentNode = head;
		if (head == nullptr)
		{
			cout << "Linked list is empty" << endl;
		}

		while (currentNode->next != head)
		{
			currentNode = currentNode->next;
			size++;
		}

		currentNode->next = head->next;
		head = currentNode;
		deleteNode = head;

	}
};



int main()
{
	List<int>list;

	list.push_back(10);
	list.push_back(20);
	list.push_back(30);

	return 0;
}
