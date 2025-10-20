template<typename T>
T& swap (T& a, T& b){
	T& temp;
	a = temp;
	a = b;
	b = temp;
}


