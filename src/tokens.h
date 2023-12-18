#pragma once

#include <boost/algorithm/string.hpp>
#include <format>
#include <map>
#include <optional>
#include <string>
#include <vector>

namespace neodymium {
class token {
   public:
    enum token_type : int {
        literal_int,
        literal_double,
        literal_float,
        literal_string
    };
    token(const token_type type, const auto value) : type(type), value(value) {}

   private:
    token_type type;
    std::optional<std::string> value;

   public:
    void setType(const token_type type) { this->type = type; }
    void setValue(const std::optional<std::string>& value) {
        this->value = value;
    }
    [[nodiscard]] token_type getType() const { return type; }
    [[nodiscard]] auto getValue() const { return value; }
    [[nodiscard]] std::string getTypeName() const {
        switch (type) {
            case literal_int:
                return "Int";
            case literal_double:
                return "Double";
            case literal_float:
                return "Float";
            case literal_string:
                return "String";
            default:
                std::cerr << "you messed up with the token types you dumbass";
                exit(EXIT_FAILURE);
        }
    }
};
class tokenizer {
   public:
    static std::vector<token> tokenize(const std::string& source) {
        std::vector<token> tokens;
        for (int i = 0; i < source.length(); i++) {
            if (std::isdigit(source.at(i)) || source.at(i) == '.') {
                std::string number;
                while (std::isdigit(source.at(i)) || source.at(i) == '.' ||
                       source.at(i) == 'f') {
                    number.append(std::string(1, source.at(i)));
                    i++;
                    if (i >= source.length() || source.at(i - 1) == 'f') {
                        break;
                    }
                }
                if (number.contains('f')) {
                    tokens.emplace_back(token::literal_float,
                                        std::optional(number));
                } else if (number.contains('.')) {
                    tokens.emplace_back(token::literal_double,
                                        std::optional(number));
                } else {
                    tokens.emplace_back(token::literal_int,
                                        std::optional(number));
                }
            } else if (source.at(i) == '\'' || source.at(i) == '\"') {
                const bool double_quotes = source.at(i) == '\"';
                i++;
                std::string str;
                while (i < source.length()) {
                    if (source.at(i) == '\"' && double_quotes ||
                        source.at(i) == '\'' && !double_quotes) {
                        break;
                    }
                    str.append(std::string(1, source.at(i)));
                    i++;
                }
                tokens.emplace_back(token::literal_string, std::optional(str));
            }
        }
        return tokens;
    }
};
}  // namespace neodymium
