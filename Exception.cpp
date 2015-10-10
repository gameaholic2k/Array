/***********************************************************
* Author:					David Nguyen
* Date Created:				10/3/2015
* Last Modification Date:	10/3/2015
* Lab Number:				CST 211
* Filename:					Execption.h
*
* Overview:
*	Definitions for the Execption class.
************************************************************/
#include "Exception.h"

Exception::Exception(char *msg) :
m_msg(msg)
{
}

Exception::Exception(const Exception &copy) :
m_msg(copy.m_msg)
{
}

Exception::~Exception()
{
}

Exception &Exception::operator=(const Exception & rhs)
{
	if (this != &rhs)
		setMessage(rhs.m_msg);
	return *this;
}


void Exception::setMessage(char * msg)
{
	m_msg = msg;
}


//
// Stream insertion
//
std::ostream  &operator<<(std::ostream  &os, const Exception  &rhs)
{
	return os << rhs.getMessage();
}