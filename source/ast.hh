#import <string>
#import <vector>

struct expr_t, decl_t, type_t, expr_t, verbphrase_t, verb_t, lvalue_t;

struct ast_t {
    std::vector<decl_t*> decls;
};


struct decl_t {
    enum { type_function } declarationtype;
};
struct function_decl_t : public decl_t {
    std::string name;
    std::vector<lvalue_t*> arguments;
    expr_t* body;
    type_t* return_type;
};


struct type_t {
    enum { type_basic, type_list, type_tuple, type_set, type_hash, type_map, type_optional, type_function } typetype;
};
struct type_basic : public type_t {
    std::string name;
};
struct list_type_t : public type_t {
    type_t* of;
};
struct tuple_type_t : public type_t {
    std::vector<type_t*> components;
};
struct set_type_t : public type_t {
    type_t* of;
};
struct hash_type_t : public type_t {
    type_t* from;
    type_t* to;
};
struct map_type_t : public type_t {
    type_t* from;
    type_t* to;
};
struct optional_type_t : public type_t {
    type_t* of;
};
struct function_type_t : public type_t {
    std::vector<type_t*> domain;
    std::vector<type_t*> codomain;
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


struct verbphrase_t {
    verb_t* verb;
    expr_t* noun;
};


struct verb_t {
    std::string name;
};


struct lvalue_t {
    enum { type_ident } lvaluetype;
};
struct ident_value_t : public lvalue_t {
    std::string ident; 
};

