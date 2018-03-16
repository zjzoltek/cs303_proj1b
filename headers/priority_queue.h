#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <algorithm>
#include <functional>
template<class _T, class _Comp = std::less<typename _T>>

class priority_queue
{
private:
	std::vector<_T> _container;
	_Comp _comparator;

	void _sort_internal_heap();

public:
	priority_queue();
	priority_queue(std::function <bool(_T, _T)> comparator);
	priority_queue(std::vector<_T>& container, std::function <bool(_T, _T)> comparator);
	priority_queue(std::vector<_T>&& container, std::function <bool(_T, _T)> comparator);
	priority_queue(std::vector<_T>&& container);
	priority_queue(std::vector<_T>& container) : _container(container), _comparator()

	void push(_T value);

	void pop();

	size_t size();

	bool is_empty();

	_T front();
};

#endif



