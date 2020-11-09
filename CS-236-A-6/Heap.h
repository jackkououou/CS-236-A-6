#pragma once
#include <vector>
using namespace std;

/*class Heap
{
private:
	Node * root;
	void insert(int key, Node * node);
	voi

};

class Node
{
private:
	int key;
	Node * left, * right;

	friend class Heap;

public:
	Node(int x)
	{
		key = x;
		left = nullptr;
		right = nullptr;
	}
};*/

class Heap
{
private:
	vector<int> keys;

public:
	Heap() {}
	~Heap() {}
	void add(const int &keys);
	void removeMax();
	int getSize() const;
	int getValue(int index) const;
	int parentIndex(int currIndex);				
	int leftChild(int currIndex);
	int rightChild(int currIndex);
	void shiftUp(int currIndex);
	void display();

};