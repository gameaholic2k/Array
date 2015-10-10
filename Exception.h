/***********************************************************
* Author:					David Nguyen
* Date Created:				10/3/2015
* Last Modification Date:	10/3/2015
* Lab Number:				CST 211
* Filename:					Execption.h
*
* Overview:
*	Declarations for the Execption class.
************************************************************/


#ifndef  exception_H
#define  exception_H

#include <iostream>

#define  ERR_OUT_OF_BOUNDS			1   // Thrown when an array bound is exceeded.
#define  ERR_MEM_ALLOC				2	// Thrown when fails to allocate dynamic memory
#define  ERR_NEGATIVE_ARRAY_SIZE    3   // Thrown if length is less than 0.
class Exception
{
public:
	Exception(char *msg);
	Exception(const Exception &copy);
	~Exception();

	Exception &operator=(const Exception &rhs);
	const char *getMessage() const									{ return m_msg; }
	void setMessage(char* msg);

private:
	char *m_msg;
};

//
// Non-member Functions
//
std::ostream &operator<<(std::ostream &os, const Exception &rhs);

#endif