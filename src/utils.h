#pragma once

#include <boost/archive/iterators/unescape.hpp>
#include <string>

namespace neodymium {
class utils {
   public:
    static int stringToInt(const std::string& str) {
        int value = 0;
        for (const char c : str) {
            if (!std::isdigit(c)) {
                return value;
            }
            value += (c - '0');
            value *= 10;
        }
        return value / 10;
    }
    static std::string unescape(const std::string& str) {
        std::string returnValue = str;
        return returnValue;
    }
};
}  // namespace neodymium