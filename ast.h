#ifndef AST_H

typedef enum {
    AST_VOID,
    AST_INTEGER,
    AST_BINARY,
    AST_UNARY,
    AST_FUNCTION,
    AST_FNCALL,
    AST_VARIABLE,
    AST_CONDITION,
    AST_LOOP,
    AST_DECLARATION,
    AST_ASSIGNMENT,
    AST_COMPOUND_STATEMENT,
    AST_RETURN
} ast_node_type_e;

typedef enum {
    ENTIER,
    CHAR
} var_type;



//<=, ==, ET, OU, +, -, *
typedef enum {
    ADD,
    SUBSTRACT,
    MULTIPLY,
    DIVIDE,
    EQUAL,
    INF_EQUAL,
    SUP_EQUAL,
    SUP,
    INF,
    DIFF,
    AND, 
    OR
} ast_binary_e;

typedef struct ast_t {
    ast_node_type_e type;
    union {
        long integer;
        struct {
            char *name;
            var_type type;
        } var;
        struct {
            ast_binary_e op;
            struct ast_t *left;
            struct ast_t *right;
        } binary;
            struct {
            char op;
            struct ast_t *operand;
        } unary;
            struct {
            char *name;
            struct ast_list_t *args;
        } call;
        struct {
            char *name;
            int return_type;
            struct ast_list_t *params;
            struct ast_list_t *stmts;
        } function;
        struct {
            struct ast_list_t *stmts;
        } compound_stmt;
        struct {
            struct ast_t *lvalue;
            struct ast_t *rvalue;
        } assignment;
        struct {
            struct ast_t *lvalue;
            struct ast_t *rvalue;
        } declaration;
        struct {
            struct ast_t *condition;
            struct ast_t *valid;
            struct ast_t *invalid;
        } branch;
        struct {
            struct ast_t *condition;
            struct ast_t *stmt;
        } loop;
        struct {
            struct ast_t *expr;
        } ret;
    };
} ast_t;

typedef struct ast_list_t {
    ast_t *data;
    struct ast_list_t *next;
} ast_list_t;


ast_t *ast_new_integer (long val);
ast_t *ast_new_variable (char *name, var_type type);
ast_t *ast_new_binary (ast_binary_e op, ast_t *left, ast_t *right);
ast_t *ast_new_function (char *name, int return_type, ast_list_t *params, ast_list_t *stmts);
ast_t *ast_new_fncall (char *name, ast_list_t *args);
ast_t *ast_new_comp_stmt (ast_list_t *stmts);


ast_t *ast_new_assignment (ast_t *lvalue, ast_t *rvalue);
ast_t *ast_new_declaration (ast_t *lvalue, ast_t *rvalue);
ast_t *ast_new_condition (ast_t *condition, ast_t *valid, ast_t *invalid);
ast_t *ast_new_loop (ast_t *condition, ast_t *stmt);
ast_t *ast_new_return (ast_t *expr);
ast_list_t *ast_list_new_node (ast_t *elem);
ast_list_t *ast_list_add (ast_list_t **list, ast_t *elem);

#define AST_H
#endif /* AST_H */