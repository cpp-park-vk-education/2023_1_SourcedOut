#include "MyCppAntlr.h"

#include <iostream>

MyCppAntlr::MyCppAntlr(std::istream& in) {
  input_ptr = std::make_unique<antlr4::ANTLRInputStream>(in);
  lexer_ptr = std::make_unique<antlrcpptest::CPP14Lexer>(&(*input_ptr));
  tokenStream_ptr = std::make_unique<antlr4::CommonTokenStream>(&(*lexer_ptr));
  parser_ptr = std::make_unique<antlrcpptest::CPP14Parser>(&(*tokenStream_ptr));
}

std::vector<std::string> MyCppAntlr::getTokensArray() {
  tokenStream_ptr->fill();
  std::vector<std::string> ans(tokenStream_ptr->size());

  int i = 0;
  for (antlr4::Token* token : tokenStream_ptr->getTokens()) {
    ans[i] = token->toString();
    i++;
  }

  return ans;
}

std::string MyCppAntlr::getTokensString() {
  tokenStream_ptr->fill();
  std::string res;

  for (antlr4::Token* token : tokenStream_ptr->getTokens()) {
    res += token->toString()+" ";
  }

  return res;
}

std::string MyCppAntlr::getTreeString() {
  auto tree = parser_ptr->translationUnit();
  return tree->toStringTree(&(*parser_ptr));
}

std::pair<std::string, std::string> MyCppAntlr::getTokensAndTree() {
  std::string tokens = getTokensString();
  std::string astTree = getTreeString();
  return std::make_pair(tokens, astTree);
}