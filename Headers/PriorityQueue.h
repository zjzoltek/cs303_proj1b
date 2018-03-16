#ifndef PriorityQueue_H
#define PriorityQueue_H

#include <vector>
#include <algorithm>
#include <functional>
template<class _T, class _Comp = std::less<typename _T>>

class PriorityQueue
{
private:
	std::vector<_T> _container;
	_Comp _comparator;

	void _sort_internal_heap();

public:
	PriorityQueue();
	PriorityQueue(std::function <bool(_T, _T)> comparator);
	PriorityQueue(std::vector<_T>& container, std::function <bool(_T, _T)> comparator);
	PriorityQueue(std::vector<_T>&& container, std::function <bool(_T, _T)> comparator);
	PriorityQueue(std::vector<_T>&& container);
	PriorityQueue(std::vector<_T>& container);

	void push(_T value);

	void pop();

	size_t size();

	bool is_empty();

	_T front();
};

#endif



