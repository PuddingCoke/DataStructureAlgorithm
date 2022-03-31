#pragma once

struct Point
{
	Point(const int& x, const int& y) :
		x(x), y(y) {}
	int x;
	int y;
	Point* next = nullptr;
	Point* prev = nullptr;
};

template<typename Node>
struct List
{
	List() :length(0), head(nullptr), cur(nullptr) {}

	void addPoint(Node* const node)
	{
		if (length)
		{
			cur->next = node;
			cur->next->prev = cur;
			cur = cur->next;
			cur->next = nullptr;
		}
		else
		{
			head = node;
			cur = head;
			head->prev = nullptr;
			head->next = nullptr;
		}
		length++;
	}

	~List()
	{
		Node* temp = head;
		while (head)
		{
			temp = temp->next;
			delete head;
			head = temp;
		}
	}

	int length;
	Node* head;
	Node* cur;
};

template<typename Node>
void foreach(List<Node>* const list, void (*func)(Point* const))
{
	for (Point* point = list->head; point != nullptr; point = point->next)
	{
		func(point);
	}
}