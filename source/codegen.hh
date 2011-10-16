#import <iostream>
#import <fstream>
#import "ast.hh"

struct codegen_ctx {
	std::ostream& output;
};

void codegen(ast_t* ast, const codegen_ctx& ctx);
void codegen(expr_t* expr, const codegen_ctx& ctx);

template<typename T>
void codegen_items<T>(std::vector<T> items, std::string separator, const codegen_ctx& ctx);
