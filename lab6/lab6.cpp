#include <iterator>

template <class iterator, class type>
bool all_of(const iterator& begin, const iterator& end, bool(&func)(type)) {
	for (auto i = begin; i != end; i = std::next(i))
		if (!func(*i))
			return false;
	return true;
}

template <class iterator, class type>
bool one_of(const iterator& begin, const iterator& end, bool(&func)(type)) {
	bool answer = false;
	for (auto i = begin; i != end; i = std::next(i))
		if (func(*i)) {
			if (answer)
				return false;
			answer = true;
		}
	return true;
}

template <class rev_iterator, class type>
rev_iterator find_backward(const rev_iterator& rbegin, const rev_iterator& rend, type x) {
	rev_iterator index = rbegin;
	for (auto i = rbegin; i != rend; i = std::next(i))
		if (*i == x) {
			index = i;
			break;
		}
	return index;
}