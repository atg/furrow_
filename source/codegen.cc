#import "codegen.hh"

static std::string mangle(std::string ident) {
    
    // TODO: We want to replace occurances of verb chars with compliant names
    // For instance, /$foo%@ becomes "slash_dollar_foo_percent_at"
    
    return ident;
}
static void codegen_call(std::string name, std::vector<expr_t*> args, const codegen_ctx& ctx) {
    ctx.output << mangle(name) << "(";
    codegen_items<expr_t*>(args, ", ", ctx);
    ctx.output << "(";
}


// START HERE!
void codegen(ast_t* ast, const codegen_ctx& ctx) {
    codegen_items<decl_t*>(ast->decls, "\n\n", ctx);
}
void codegen(decl_t* decl, const codegen_ctx& ctx) {
    switch (decl->declarationtype) {
        case decl_t::type_function:
            codegen(static_cast<function_decl_t*>(decl), ctx);
        break;
    }
}
void codegen(function_decl_t* decl, const codegen_ctx& ctx) {
    
    codegen(decl->return_type, ctx);
    ctx.output << " " << decl->name << "(";
    codegen_items<lvalue_t*>(decl->args, ", ", ctx);
    ctx.output << ") {\n\treturn ";
    codegen(decl->body);
    ctx.output << ";\n}\n";
}

void codegen(type_t* ty, const codegen_ctx& ctx) {
    switch (type_t>typetype) {
        case type_t::type_basic:
            ctx.output << mangle(static_cast<basic_type_t*>(ty)->name);
        break;
        case type_t::list_type_t:
            ctx.output << "std::vector< ";
            codegen(static_cast<list_type_t*>(ty)->of, ctx);
            ctx.output << " >";
        break;
        case type_t::tuple_type_t:
            ctx.output << "std::tuple< ";
            codegen_list<type_t*>(static_cast<tuple_type_t*>(ty)->components, ctx);
            ctx.output << " >";
        break;
        case type_t::set_type_t:
            ctx.output << "std::set< ";
            codegen(static_cast<set_type_t*>(ty)->of, ctx);
            ctx.output << " >";
        break;
        case type_t::hash_type_t:
            // TODO!
        break;
        case type_t::map_type_t:
            // TODO!
        break;
        case type_t::optional_type_t:
            ctx.output << "boost::optional< ";
            codegen(static_cast<optional_type_t*>(ty)->of, ctx);
            ctx.output << " >";
        break;
        case type_t::function_type_t:
            // TODO!
        break;
    }
}
void codegen(expr_t* expr, const codegen_ctx& ctx) {
    switch (expr->exprtype) {
        case expr_t::type_call:
            
        break;
        case expr_t::type_sentence:
            
        break;
    }
}
void codegen(verbphrase_t* vp, const codegen_ctx& ctx) {
    
    std::vector<expr_t*> args;
    if (noun)
        args.push_back(vp->noun);
        
    codegen_call(vp->verb->name, args, ctx);
}
void codegen(lvalue_t* lv, const codegen_ctx& ctx) {
    switch (lv->lvaluetype) {
        case lvalue_t::type_ident:
            ctx.output << mangle(static_cast<ident_value_t*>(lv)->ident);
        break;
    }
}


template<typename T>
void codegen_items<T>(std::vector<T> items, std::string separator, const codegen_ctx& ctx) {
    
    bool isFirst = true;
    for (typename T::iterator it = items.begin(), et = items.end(); it != et; ++it, isFirst = false) {
        if (!isFirst)
            output << separator;
        ctx.output << codegen(*it, ctx);
    }
}

