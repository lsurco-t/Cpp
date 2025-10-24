#pragma once
#include <stdexcept>
#include <algorithm>

template<typename T>
typename T::const_iterator easyfind(const T& container, int value){
	auto it = std::find(container.begin(), container.end(), value);
	if (it != container.end())
		return it;
	else
		throw std::runtime_error("Element not found");
}
