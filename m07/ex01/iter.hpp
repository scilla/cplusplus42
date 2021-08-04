#ifndef ITER_HPP
#define ITER_HPP

template<typename T>
void iter(T* arr, unsigned int size, void (*f)(const T&)) {
	for (unsigned int i = 0; i < size; i++) {
		f(arr[i]);
	}
}

#endif /* ITER_HPP */
