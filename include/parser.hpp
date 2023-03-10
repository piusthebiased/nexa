#ifndef PARSER_HPP
#define PARSER_HPP

#include <map>

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/SourceMgr.h>

/*
#include "AST/binaryExprAST.hpp"
#include "AST/callExprAST.hpp"
#include "AST/exprAST.hpp"
#include "AST/functionAST.hpp"
#include "AST/ifExprAST.hpp"
#include "AST/numericExprAST.hpp"
#include "AST/prototypeAST.hpp"
#include "AST/stringExprAST.hpp"
#include "AST/variableExprAST.hpp"
*/

#include "lexer.hpp"
#include "token.hpp"

namespace nl {

class Parser {
private:
    const static std::map<std::string, int> binary_operator_precedence;

    std::vector<std::string> m_errors;

    std::fstream m_fileHandler;
    Lexer m_lexer;
    // std::map<std::string, llvm::Value *> m_values;

public:
    Parser(const std::string &filename);
    ~Parser();
    bool generate_IR();
};

}

#endif
