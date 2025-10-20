template<typename T>
T& swap (T& a, T& b){
	T& temp;
	a = temp;
	a = b;
	b = temp;
}

template<typename T>
T& max (T& a, T& b){
	a > b ? a : b;
}

template<typename T>
T& min (T& a, T& b){
	a < b ? a : b;
}




