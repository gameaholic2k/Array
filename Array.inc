#include  "Array.h"


//
// Array construtor
//
template<class  T>
Array<T>::Array(int length, int start_index) :
m_length(length),
m_start_index(start_index)

{
	m_array = new  T[length];
}


//
// Array copy construtor
// Performs a deep copy for the array
//
template<class  T>
Array<T>::Array(const Array  &copy) :
m_length(copy.m_length),
m_start_index(copy.m_start_index),
m_array(new T[copy.m_length])
{
	for (int idx = 0; idx < copy.m_length; idx++)
		m_array[idx] = copy.m_array[idx];
}


//
// Destructor
//
template<class T>
Array<T>::~Array()
{
	delete[] m_array;
}


//
// Assignment operator
//
template<class T>
const Array<T>&Array<T>::operator=(const Array  &rhs)
{
	if (this != &rhs)
	{
		delete[] m_array;
		m_array = new T[rhs.m_length];
		m_length = rhs.m_length;
		m_start_index = rhs.m_start_index;

		for (int idx = 0; idx < m_length; idx++)
			m_array[idx] = rhs.m_array[idx];
	}
	return *this;
}
template<class T>
void Array<T>::setStartIndex(int start_index)
{
	m_start_index = start_index;
}

template<class T>
void Array<T>::setLength(int length)
{
	T* tempArray = new T[length];
	m_length = length;
	for (int idx = 0; idx < length; idx++)
		tempArray[idx] = m_array[idx];
	delete[] m_array;
	m_array = tempArray;

}