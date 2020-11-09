#include "Heap.h"
#include <iostream>
using namespace std;

int Heap::getSize() const
{
	return keys.size();
}

int Heap::getValue(int index) const
{
	return keys[index];
}

int Heap::parentIndex(int currIndex)
{	
	return (currIndex / 2);	
}

int Heap::leftChild(int currIndex) 
{
	return (2 * currIndex) + 1;
}

int Heap::rightChild(int currIndex)
{
	return (2 * currIndex) + 2;
}

void Heap::add(const int &key)
{
	bool inOrder = false;

	int currIndex = keys.size();
	keys.push_back(key);

	if (currIndex != 0)
	{
		while (!inOrder)
		{
			if (key > keys[parentIndex(currIndex)])
			{
				shiftUp(currIndex);
				currIndex = parentIndex(currIndex);
			}
			else
				inOrder = true;
		}
	}

}

void Heap::removeMax()
{
	int rootKey = keys[0];
	int hole = 0;
	bool removed = false;

	while (!removed)
	{
		if (hole == getSize() - 1)
		{
			keys[getSize() - 1] = rootKey;
			cout << "\nRemove Item: " << keys[getSize() - 1];
			keys.pop_back();
			removed = true;
		}
		else if (rightChild(hole) >= getSize())
		{
			if (leftChild(hole) < getSize())
			{
				keys[hole] = keys[leftChild(hole)];
				hole = leftChild(hole);
				keys[hole] = rootKey;
			}
			else
			{
				keys[hole] = keys[getSize() - 1];
				keys[getSize() - 1] = rootKey;
				hole = getSize() - 1;
			}
		}
		else if (leftChild(hole) >= getSize())
		{
			keys[hole] = keys[rightChild(hole)];
			hole = rightChild(hole);
			keys[hole] = rootKey;
		}
		else if (keys[leftChild(hole)] >= keys[rightChild(hole)])
		{
			keys[hole] = keys[leftChild(hole)];
			hole = leftChild(hole);
			keys[hole] = rootKey;
		}
		else
		{
			keys[hole] = keys[rightChild(hole)];
			hole = rightChild(hole);
			keys[hole] = rootKey;
		}
	}

}

void Heap::shiftUp(int currIndex)
{
	int temp = keys[parentIndex(currIndex)];
	keys[parentIndex(currIndex)] = keys[currIndex];
	keys[currIndex] = temp;
}

void Heap::display()
{
	for (int i = 0; i < getSize(); i++)
		cout << keys[i] << ' ';
}