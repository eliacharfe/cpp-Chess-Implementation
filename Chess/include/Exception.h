#pragma once
#include "Utilities.h"

class UnknownLocation : public std::exception
{
public:
    UnknownLocation(const char* str) : m_str(str) {}
    const char* what() const noexcept { return m_str; }

private:
    const char* m_str;
};