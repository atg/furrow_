#import "furrow.hh"

struct expr_t;

struct lvalue_t {
    enum { type_ident } lvaluetype;
};
struct ident_value_t : pubic lvalue_t {
    std::string ident; 
};


struct verbphrase_t {
    verb_t* verb;
    expr_t* noun;
};


struct expr_t {
    enum { type_call, type_sentence } exprtype;
};
struct call_expr_t : public expr_t {
    std::string name;
    std::vector<expr_t*> arguments;
};
struct sentence_expr_t : public expr_t {
    std::vector<verbphrase_t*> verbphrases;
};


struct decl_t {
    enum { type_function } decltype;
};
struct function_decl_t : public decl_t {
    std::string name;
    std::vector<lvalue_t*> arguments;
    expr_t* body;
};


struct ast_t {
    std::vector<decl_t*> decls;
};

