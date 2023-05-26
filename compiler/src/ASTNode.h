//
// Created by vilia on 2023/05/26.
//

#ifndef QUARKONCOMPILER_ASTNODE_H
#define QUARKONCOMPILER_ASTNODE_H
#include <vector>
#include <variant>
namespace QuarkonCompiler {
    class NumberLiteralNode {
        std::size_t integer;
    public:
        explicit NumberLiteralNode(unsigned long long int integer) : integer(integer) {}
    };
    class LiteralExpressionNode {
        using LiteralExpressionContainer = NumberLiteralNode;
        LiteralExpressionContainer literal;
    public:
        explicit LiteralExpressionNode(const LiteralExpressionContainer &literal) : literal(literal) {}
    };
    class ExpressionNode {
        using ExpressionContainer = LiteralExpressionNode;
        ExpressionContainer expression;
    public:
        explicit ExpressionNode(const ExpressionContainer &expression) : expression(expression) {}
    };
    class ExpressionStatementNode {
        ExpressionNode _exp;
    public:
        explicit ExpressionStatementNode(const ExpressionNode &exp) : _exp(exp) {}
    };
    class ProgramNode {
        std::vector<ExpressionStatementNode> statementList;
    public:
        explicit ProgramNode(const std::vector<ExpressionStatementNode> &statementList) : statementList(statementList) {}
    };
}
#endif //QUARKONCOMPILER_ASTNODE_H
