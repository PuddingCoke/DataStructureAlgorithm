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

struct List
{
	List() :length(0), head(nullptr), cur(nullptr) {}

	void addNode(const int& x,const int& y)
	{
		if (length)
		{
			cur->next = new Point(x, y);
			cur->next->prev = cur;
			cur = cur->next;
			cur->next = nullptr;
		}
		else
		{
			head = new Point(x, y);
			cur = head;
			head->prev = nullptr;
			head->next = nullptr;
		}
		length++;
	}

	~List()
	{
		Point* temp = head;
		while (head)
		{
			temp = temp->next;
			delete head;
			head = temp;
		}
	}

	int length;
	Point* head;
	Point* cur;
};

void foreach(List* const list, void (*func)(Point* const))
{
	for (Point* point = list->head; point != nullptr; point = point->next)
	{
		func(point);
	}
}