#pragma once

#include <exception>
#include <string>

class mem_exception : public std::exception
{
	std::string msg;
public:
    mem_exception(const std::string & str) : msg(str) {}
    const char * what() const noexcept {
		return msg.c_str();
	}
};
