#pragma once
template<class T>
class queue
{
public:
	queue();
	void push_back(T&);
	T& pop_front();
	void resize();
	queue& operator=(const queue& other);
private:
	int capacity;
	int size;
	T* value;
};

template<class T>
inline queue<T>::queue()
{
	size = 0;
	capacity = 20;
	value = new T[capacity];
}

template<class T>
inline void queue<T>::push_back(T& val)
{
	if (size == capacity)
	{
		capacity *= 2;
		T* newValue = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			newValue[i] = value[i];
		}
		newValue[size] = val;
		value = newValue;
	}
	else {
		value[size] = val;
	}
	size++;
}

template<class T>
inline T& queue<T>::pop_front()
{
	T front = value[0];
	for (int i = 1; i < size; i++)
	{
		value[i - 1] = value[i];
	}
	size--;
	return front;
}

template<class T>
inline void queue<T>::resize() {
	capacity *= 2;
	T* newValue = new T[capacity];
	for (int i = 0; i < size; ++i) {
		newValue[i] = value[i];
	}
	delete[] value; 
	value = newValue;
}
template<class T>
inline queue<T>& queue<T>::operator=(const queue& other) {
	
		size = other.size;
		capacity = other.capacity;
		value = new T[capacity];
		for (int i = 0; i < size; ++i) {
			value[i] = other.value[i];
		}
	
	return *this;
}
