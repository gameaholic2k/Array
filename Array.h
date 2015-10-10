/***********************************************************
* Author:					David Nguyen
* Date Created:				10/3/2015
* Last Modification Date:	10/3/2015
* Lab Number:				CST 211
* Filename:					Array.h
*
* Overview:
*	Declarations for the Array class.
************************************************************/


#include "Exception.h"

#define LAST_INDEX m_start_index + m_length -1
#define PUBLIC_LAST_INDEX data.getLength() + data.getStartIndex() - 1

#ifndef  array_H
#define  array_H



//
// Array class declaration
//
//	Constraints for ELEMENT_TYPE:
//	- assignable
//	- copyable
//	- must have a default constructor
//
template<class T>
class Array
{
public:
	Array(int length, int start_index = 0);
	Array(const Array &copy);
	~Array();

	const Array &operator=(const Array &rhs);
	T &operator[](int index);
	const T &operator[](int index) const;
	//T &operator[](int index)				{ return m_array[index - m_start_index]; }
	//const T &operator[](int index) const	{ return m_array[index - m_start_index]; }


	int getStartIndex()								{ return m_start_index; }
	int getLength()									{ return m_length; }
	void setStartIndex(int start_index);
	void setLength(int length);

	

private:
	T *m_array;
	int m_length;
	int m_start_index;

};

#include  "Array.inc"


#endif