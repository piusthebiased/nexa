//
// Created by piuslee on 2/18/23.
//

#ifndef PARSER_HPP
#define PARSER_HPP

#include <map>

#include "AST/binaryExprAST.hpp"
#include "AST/callExprAST.hpp"
#include "AST/exprAST.hpp"
#include "AST/functionAST.hpp"
#include "AST/numberExprAST.hpp"
#include "AST/prototypeAST.hpp"
#include "AST/variableExprAST.hpp"

#include "lexer.hpp"

extern std::map<char, int> BinopPrecedence;
std::unique_ptr<ExprAST> ParseNumberExpr();
std::unique_ptr<ExprAST> ParseParenExpr();
std::unique_ptr<ExprAST> ParseIdentifierExpr();
std::unique_ptr<ExprAST> ParsePrimary();
std::unique_ptr<ExprAST> ParseBinaryOperationRHS(int ExprPrec, std::unique_ptr<ExprAST> LHS);
std::unique_ptr<ExprAST> ParseExpression();
std::unique_ptr<PrototypeAST> ParsePrototype();
std::unique_ptr<FunctionAST> ParseDefinition();
std::unique_ptr<FunctionAST> ParseTopLevelExpr();
std::unique_ptr<PrototypeAST> ParseExtern();

#endif