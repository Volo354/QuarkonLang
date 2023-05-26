//
// Created by vilia on 2023/05/26.
//

#ifndef QUARKONCOMPILER_TOKENIZATION_H
#define QUARKONCOMPILER_TOKENIZATION_H
#include <map>
#include <string>
#include <utility>
#include <regex>

namespace QuarkonCompiler {
    enum class TokenType {
        INTEGER,
        COLON,
        ERROR
    };
    struct Token {
        TokenType type;
        std::string repr;
    };
    class Lexer {
        std::string _source;
        size_t _cursor = 0;
        std::map<std::string, TokenType> _specification {
                {"^\\d+", TokenType::INTEGER},
                {"^;", TokenType::COLON}
        };
    public:
        Token getNextToken() {
            for(auto &pair: _specification) {
                auto matchedStr = _match(pair.first);
                if(matchedStr != "\0") {
                    return Token {.type = pair.second, .repr = matchedStr};
                }
            }
            return Token {.type = TokenType::ERROR};
        }
        explicit Lexer(std::string source) : _source(std::move(source)) {}
    private:
        std::string _match(const std::string &pattern) {
            std::regex constructedPattern(pattern);
            std::smatch matchInfo;
            std::string sourceString = _source.substr(_cursor, _source.length() - 1);
            if(std::regex_search(sourceString, matchInfo, constructedPattern)) {
                _cursor += matchInfo.length();
                return matchInfo.str();
            }
            return "\0";
        }
    };
}
#endif //QUARKONCOMPILER_TOKENIZATION_H
