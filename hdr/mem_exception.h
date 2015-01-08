#pragma once

#include <exception>
#include <string>

class mem_exception : public std::exception
{
	std::string msg;
public:
	explicit mem_exception(const std::string & str) : msg(str) {}
	const char * what() const throw() {
		return msg.c_str();
	}
};