#pragma once

template<class _T, class _Comp = std::less<typename _T>>
class PriorityQueue;

#include <list>
#include <algorithm>
#include <functional>

template<class _T, class _Comp>
class PriorityQueue
{
private:
	std::list<_T> _container;
	_Comp _comparator;

	void _sort_internal_heap();
public:
	PriorityQueue();
	PriorityQueue(std::function <bool(_T, _T)> comparator);
	PriorityQueue(std::list<_T>& container, std::function <bool(_T, _T)> comparator);
	PriorityQueue(std::list<_T>&& container, std::function <bool(_T, _T)> comparator);
	PriorityQueue(std::list<_T>&& container);
	PriorityQueue(std::list<_T>& container);

	void push(_T value);

	void pop();

	size_t size();

	bool is_empty();

	_T front();
};
