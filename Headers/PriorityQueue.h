#pragma once

template<class _T>
class PriorityQueue;

#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

template<class _T>
class PriorityQueue
{
private:
	std::vector<_T> _container;
	std::function <bool(_T, _T)> _comparator;
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

	_T& front();

	void sort_internal_heap();

	typename std::vector<_T>::iterator begin();
	typename std::vector<_T>::iterator end();
};

#include "../Headers/PriorityQueue.h"

template<class _T>
void PriorityQueue<_T>::sort_internal_heap()
{
	std::sort_heap(_container.begin(), _container.end(), _comparator);
}

template<class _T>
PriorityQueue<_T>::PriorityQueue() : _comparator(), _container()
{}

template<class _T>
PriorityQueue<_T>::PriorityQueue(std::function <bool(_T, _T)> comparator) : _comparator(comparator)
{
	std::make_heap(_container.begin(), _container.end(), _comparator);
}

template<class _T>
PriorityQueue<_T>::PriorityQueue(std::vector<_T>& container) : _container(container), _comparator()
{
	std::make_heap(_container.begin(), _container.end(), _comparator);
}

template<class _T>
PriorityQueue<_T>::PriorityQueue(std::vector<_T>&& container) : _container(container), _comparator()
{
	std::make_heap(_container.begin(), _container.end(), _comparator);
}

template<class _T>
PriorityQueue<_T>::PriorityQueue(std::vector<_T>& container, std::function<bool(_T, _T)> comparator) : _container(container), _comparator(_comparator)
{
	std::make_heap(_container.begin(), _container.end(), _comparator);
}

template<class _T>
PriorityQueue<_T>::PriorityQueue(std::vector<_T>&& container, std::function<bool(_T, _T)> comparator) : _container(std::move(container)), _comparator(comparator)
{
	std::make_heap(_container.begin(), _container.end(), _comparator);
}

template<class _T>
void PriorityQueue<_T>::push(_T value)
{
	_container.push_back(std::move(value));
	std::push_heap(_container.begin(), _container.end(), _comparator);
}

template<class _T>
void PriorityQueue<_T>::pop()
{
	std::pop_heap(_container.begin(), _container.end(), _comparator);
	_container.pop_back();
}

template<class _T>
size_t PriorityQueue<_T>::size()
{
	return _container.size();
}

template<class _T>
bool PriorityQueue<_T>::is_empty()
{
	return _container.empty();
}

template<class _T>
_T& PriorityQueue<_T>::front()
{
	return _container.front();
}

template<class _T>
typename std::vector<_T>::iterator PriorityQueue<_T>::begin()
{
	return _container.begin();
}

template<class _T>
typename std::vector<_T>::iterator PriorityQueue<_T>::end()
{
	return _container.end();
}