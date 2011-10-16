#import <vector>

#import "lexer.hh"
#import "ast.hh"

ast_t* parse(std::vector<token_t> tokens);
