//
// Created by vilia on 2023/05/26.
//

#ifndef QUARKONCOMPILER_PARSER_H
#define QUARKONCOMPILER_PARSER_H
#include "ASTNode.h"
#include "Tokenization.h"
#include <string>
#include <memory>
namespace QuarkonCompiler {
    class Parser {
        std::shared_ptr<Lexer> _lexer;
        Token _lookahead;
        Token _consume(TokenType type) {
            auto consumed = _lookahead;
            if(consumed.type != type) {
                throw std::invalid_argument("Please handle this error...");
            }
            _lookahead = _lexer->getNextToken();
            return consumed;
        }
        NumberLiteralNode NumberLiteral() {
            return NumberLiteralNode(std::stoi(_consume(TokenType::INTEGER).repr));
        }
        LiteralExpressionNode LiteralExpression() {
            return LiteralExpressionNode(NumberLiteral());
        }
        ExpressionNode Expression() {
            return ExpressionNode(LiteralExpression());
        }
        ExpressionStatementNode ExpressionStatement() {
            auto exp = Expression();
            _consume(TokenType::COLON);
            return ExpressionStatementNode(exp);
        }
    public:
        explicit Parser(const std::shared_ptr<Lexer> &lexer)  {
            _lexer = lexer;
            _lookahead = _lexer->getNextToken();
        }
        ProgramNode Parse() {
            std::vector<ExpressionStatementNode> expList;
            while(_lookahead.type != TokenType::ERROR) {
                expList.emplace_back(ExpressionStatement());
            }
            return ProgramNode(expList);
        }
    };
}
#endif //QUARKONCOMPILER_PARSER_H
