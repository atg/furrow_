#import <iostream>
#import <fstream>
#import "ast.hh"

void codegen(ast_t* ast, std::ostream& output);
void codegen(expr_t* expr, std::ostream& output);