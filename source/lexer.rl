#import "../source/lexer.hh"

#define emit(kind) emit_token(kind, ts, te, tokens);

static inline void emit_token(int kind, char* ts, char* te, std::vector<token_t>& tokens) {
    token_t tok;
    tok.tokentype = kind;
    tok.contents = new std::string(ts, te - ts);
    tokens.push_back(tok);
}

%%{

machine lexer;
write data;

verbchar = [/.];
identchar = ([a-zA-Z0-9_] | '-');

main := |*
    
    # Delimiters and Operators
    [(] { emit(LPAREN) };
    [)] { emit(RPAREN) };
    
    [=] { emit(EQ) };
    [,] { emit(COMMA) };
    
    [+] { emit(PLUS) };
    '-' { emit(MINUS) };
    [*] { emit(STAR) };
    [/] { emit(SLASH) };
            
    # Keywords
    # "foo" { emit(FOO) };
    
    # Literals
    digit+ ('.' digit+)? { emit(NUMERIC) };
    
    # Identifiers
    [a-zA-Z_] identchar* { emit(IDENT) };
    verbchar (([a-zA-Z_] | verbchar) (identchar | verbchar)*)? { emit(VERB) };
*|;

}%%

std::vector<token_t> lex(std::string input) {
    
    const char* data = input.c_str();
    std::vector<token_t> tokens;
    
    char* p = const_cast<char*>(data);
    char* pe = p + input.length();
    char* eof = pe;
    
    int cs = 0;
    int act = 0;
    int have = 0;
    int curline = 1;
    char* ts = 0;
    char* te = 0;
    int done = 0;
    int nesting = 0;
    
    %% write init;
    %% write exec;
    
    return tokens;
}
