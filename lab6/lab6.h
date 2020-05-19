#pragma once

// 1 - all_of
template <class iterator, class type>
bool all_of(const iterator&, const iterator&, bool(&func)(type));

// 4 - one_of
template <class iterator, class type>
bool one_of(const iterator&, const iterator&, bool(&func)(type));

// 7 - find_backward
template <class rev_iterator, class type>
rev_iterator find_backward(const rev_iterator&, const rev_iterator&, type);

#include "lab6.cpp"