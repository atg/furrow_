#import "../source/lexer.hh"

#define emit(kind) emit_token(kind, ts, te, tokens);

static inline void emit_token(int kind, char* ts, char* te, std::vector<token_t>& tokens) {
    token_t tok;
    tok.tokentype = kind;
    tok.contents = new std::string(ts, te, te - ts);
    tokens.push_back(tok);
}

%%{

machine lexer;
write data;

verbchar = [/.];
identchar = ([a-zA-Z0-9_] | '-');

main := |*
    
    # Operators
    [+] { emit(PLUS) };
    '-' { emit(MINUS) };
    [*] { emit(STAR) };
    [/] { emit(SLASH) };
    # "mod" { emit(MOD) };
    
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
    
    char* data = input.c_str();
    std::vector<token_t> tokens;
    
    char* p = data;
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
