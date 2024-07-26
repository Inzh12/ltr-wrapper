#pragma once

#include <stdexcept>
#include <iostream>

namespace LtrWrapper {
    class LtrException : public std::runtime_error {
    public:
        LtrException(const std::string& what_arg);
        LtrException(const char * what_arg);
    };
}
