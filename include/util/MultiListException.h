#ifndef MULTILISTEXCEPTION_H
#define	MULTILISTEXCEPTION_H

#include <exception>
#include <string>

class MultiListException : public std::exception
{
public:

	MultiListException(const char *msg) : m_msg(msg) { }

	virtual ~MultiListException() throw() { }

	virtual const char* what() const throw()
	{
		return m_msg.c_str();
	}

private:
	std::string m_msg;
};

#endif	/* MULTILISTEXCEPTION_H */

