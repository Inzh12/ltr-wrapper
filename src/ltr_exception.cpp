#include "ltr_exception.h"

namespace LtrWrapper {
    LtrException::LtrException(const std::string &what_arg) : std::runtime_error(what_arg) {}
    LtrException::LtrException(const char *what_arg) : std::runtime_error(what_arg) {}
}
