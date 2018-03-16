#include "../Headers/PriorityQueue.h"

template<class _T, class _Comp = std::less<typename _T>>
inline void PriorityQueue<_T, _Comp>::_sort_internal_heap()
{
	std::sort_heap(_container.begin(), _container.end());
}

template<class _T, class _Comp = std::less<typename _T>>
PriorityQueue<_T, _Comp>::PriorityQueue() : _comparator(), _container()
{}

template<class _T, class _Comp = std::less<typename _T>>
PriorityQueue<_T, _Comp>::PriorityQueue(std::function <bool(_T, _T)> comparator) : _comparator(comparator)
{
	std::make_heap(_container.begin(), _container.end());
}

template<class _T, class _Comp = std::less<typename _T>>
PriorityQueue<_T, _Comp>::PriorityQueue(std::vector<_T>& container) : _container(container), _comparator()
{
	std::make_heap(_container.begin(), _container.end());
}

template<class _T, class _Comp = std::less<typename _T>>
PriorityQueue<_T, _Comp>::PriorityQueue(std::vector<_T>&& container) : _container(container), _comparator()
{
	std::make_heap(_container.begin(), _container.end());
}

template<class _T, class _Comp = std::less<typename _T>>
PriorityQueue<_T, _Comp>::PriorityQueue(std::vector<_T>& container, std::function<bool(_T, _T)> comparator) : _container(container), _comparator(_comparator)
{
	std::make_heap(_container.begin(), _container.end());
}

template<class _T, class _Comp = std::less<typename _T>>
PriorityQueue<_T, _Comp>::PriorityQueue(std::vector<_T>&& container, std::function<bool(_T, _T)> comparator) : _container(std::move(container)), _comparator(comparator)
{
	std::make_heap(_container.begin(), _container.end());
}

template<class _T, class _Comp = std::less<typename _T>>
inline void PriorityQueue<_T, _Comp>::push(_T value)
{
	_container.push_back(std::move(_T));
	std::push_heap(_container.begin(), _container.end());
}

template<class _T, class _Comp = std::less<typename _T>>
inline void PriorityQueue<_T, _Comp>::pop()
{
	std::pop_heap(_container.begin(), _container.end());
	_container.pop_back();
}

template<class _T, class _Comp = std::less<typename _T>>
inline size_t PriorityQueue<_T, _Comp>::size()
{
	return _container.size();
}

template<class _T, class _Comp = std::less<typename _T>>
inline bool PriorityQueue<_T, _Comp>::is_empty()
{
	return _container.empty();
}

template<class _T, class _Comp = std::less<typename _T>>
inline _T PriorityQueue<_T, _Comp>::front()
{
	return _container.front();
}
