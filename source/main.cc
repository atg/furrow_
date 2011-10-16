#import <iostream>

#import "furrow.hh"
#import "lexer.hh"
#import "parser.hh"
#import "codegen.hh"

int main(int argc, char** argv) {
    
    // Read from argv[1], write to stdout
    std::ifstream in_f = std::ifstream(argv[1]);
    std::string in_str = std::string( istreambuf_iterator(in_f), istreambuf_iterator() );
    std::ostream out_f = std::cout;
    
    std::vector<token_t> tokens = lex(in_str);
    ast_t ast = parse(tokens);
    codegen(ast, out_f);
    
    return 0;
}
