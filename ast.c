#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast.h"

ast_t *ast_new_integer (long val)
{
	ast_t *result = (ast_t *)malloc(sizeof(ast_t));
    result->type = AST_INTEGER;
    result->integer = val;
    return result;
}

ast_t *ast_new_variable (char *name, var_type type){
    ast_t *result = (ast_t *)malloc(sizeof(ast_t));
    result->type = AST_VARIABLE;
    result->var.type = type;
    return result;
}

ast_t *ast_new_binary (ast_binary_e op, ast_t *left, ast_t *right){
    ast_t *result = (ast_t *)malloc(sizeof(ast_t));
    result->type = AST_BINARY;
    result->binary.op = op;
    result->binary.right = right;
    result->binary.left = left;
    return result;
}

ast_t *ast_new_function (char *name, int return_type, ast_list_t *params, ast_list_t *stmts){
    ast_t *result = (ast_t *)malloc(sizeof(ast_t));
    result->type = AST_FUNCTION;
    result->function.name = name;
    result->function.return_type = return_type;
    result->function.params = params;
    result->function.stmts = stmts;
    return result;
}

ast_t *ast_new_fncall (char *name, ast_list_t *args){
    ast_t *result = (ast_t *)malloc(sizeof(ast_t));
    result->type = AST_FNCALL;
    result->call.name = name;
    result->call.args = args;
    return result;
}

ast_t *ast_new_comp_stmt (ast_list_t *stmts){
    ast_t *result = (ast_t *)malloc(sizeof(ast_t));
    result->type = AST_COMPOUND_STATEMENT;
    result->compound_stmt.stmts = stmts;
    return result;
}

ast_t *ast_new_assignment (ast_t *lvalue, ast_t *rvalue){
    ast_t *result = (ast_t *)malloc(sizeof(ast_t));
    result->type = AST_ASSIGNMENT;
    result->assignment.lvalue = lvalue;
    result->assignment.rvalue = rvalue;

    return result;
    
}
ast_t *ast_new_declaration (ast_t *lvalue, ast_t *rvalue){
    ast_t *result = (ast_t *)malloc(sizeof(ast_t));
    result->type = AST_DECLARATION;
    result->declaration.lvalue = lvalue;
    result->declaration.rvalue = rvalue;

    return result;
}
ast_t *ast_new_condition (ast_t *condition, ast_t *valid, ast_t *invalid){
    ast_t *result = (ast_t *)malloc(sizeof(ast_t));
    result->type = AST_CONDITION;
    result->branch.condition = condition;
    result->branch.valid = valid;
    result->branch.invalid = invalid;

    return result;
}

ast_t *ast_new_loop (ast_t *condition, ast_t *stmt){
    ast_t *result = (ast_t *)malloc(sizeof(ast_t));
    result->type = AST_LOOP;
    result->loop.condition = condition;
    result->loop.stmt = stmt;

    return result;
}
ast_t *ast_new_return (ast_t *expr){
    ast_t *result = (ast_t *)malloc(sizeof(ast_t));
    result->type = AST_RETURN;
    result->ret.expr = expr;

    return result;
}

ast_list_t *ast_list_new_node (ast_t *elem) {
    ast_list_t *new_node;

    new_node = (ast_list_t *)malloc(sizeof(ast_list_t));
    new_node->data = elem;
    new_node->next = NULL;

    return new_node;
}

ast_list_t *ast_list_add (ast_list_t **list, ast_t *elem){
    ast_list_t *tmp;

    tmp = *list;
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = ast_list_new_node(elem);
    
    return *list;
}
