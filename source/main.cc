#import <iostream>
#import <vector>
#import <fstream>
#import <iterator>

#import "lexer.hh"
#import "parser.hh"
#import "tokens.hh"
#import "codegen.hh"

int main(int argc, char** argv) {
    
    // Read from argv[1], write to stdout
    std::ifstream in_f(argv[1], std::ifstream::in);
    std::string in_str( (std::istreambuf_iterator<char>(in_f)), (std::istreambuf_iterator<char>()) );
    std::ostream& out_f = std::cout;
    
    std::vector<token_t> tokens = lex(in_str);
    ast_t* ast = parse(tokens);
    codegen(ast, out_f);
    
    return 0;
}
