/***********************************************************
* Author:					David Nguyen
* Date Created:				10/3/2015
* Last Modification Date:	10/3/2015
* Lab Number:				CST 211
* Filename:					Array.inc
*
* Overview:
*	Definitions for the dynamic Array class template
************************************************************/

#include  "Array.h"


//
// Array construtor
// 
template<class  T>
Array<T>::Array(int length, int start_index) :
m_length(length),
m_start_index(start_index)

{


	//
	// Throws an exception of the length is less than 0
	//
	if (length < 0)
		throw(ERR_NEGATIVE_ARRAY_SIZE);
	m_array = new  T[length];

	//
	// Throws an exception if the memory allocation fails.
	//
	if (!m_array)
		throw(ERR_MEM_ALLOC);
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
// Performs a deep copy for the array
//
template<class T>
const Array<T>&Array<T>::operator=(const Array  &rhs)
{
	//
	// Self-assignment check
	//
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

//
// Sets the length of the Array
// Throws an exception of the length is less than 0.
//
template<class T>
void Array<T>::setLength(int length)
{
	if (length < 0)
		throw(ERR_NEGATIVE_ARRAY_SIZE);
	T* tempArray = new T[length];
	
	//
	// Determines the buffer length by comparing which of the two
	// is less than the other
	//
	int buff_length;
	if (m_length < length)
		buff_length = m_length;
	else
		buff_length = length;

	for (int idx = 0; idx < buff_length; idx++)
		tempArray[idx] = m_array[idx];
	delete[] m_array;
	m_length = length;
	m_array = tempArray;

}

//
// Array operator[]
// Validates if the index is within bounds of the array
//
template<class T>
T &Array<T>::operator[](int index)
{
	if (index < m_start_index || index > LAST_INDEX)
		throw(ERR_OUT_OF_BOUNDS);
	return m_array[index - m_start_index];
}


//
// Array operator[] const
// Validates if the index is within bounds of the array
//
template<class T>
const T &Array<T>::operator[](int index) const
{
	if (index < m_start_index || index > LAST_INDEX)
		throw(ERR_OUT_OF_BOUNDS);
	return m_array[index - m_start_index];
}