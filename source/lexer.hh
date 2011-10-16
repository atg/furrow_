#import "tokens.hh"

struct token_t {
    int tokentype;
    std::string* contents;
};

std::vector<token_t> lex(std::string input);
