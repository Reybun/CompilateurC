#ifndef PARSER_H
#include "lexer.h"
#include "ast.h"

 typedef enum {
     SYM_FUNCTION,
     SYM_VAR,
     SYM_PARAM
} sym_type_t;

typedef struct symbol_t {
    char *name;
    sym_type_t type; // symbol type
    ast_t *attributes;
    struct symbol_t *function_table;
    struct symbol_t *next;
} symbol_t;

void parser(buffer_t * buffer, symbol_t *symboles);
void analyse_fonction(buffer_t * buffer, symbol_t *symboles);
void analyse_parametre(buffer_t * buffer, symbol_t *symboles);
void analyse_type_de_retour(buffer_t * buffer);
void analyse_corps_de_fonction(buffer_t *buffer);

symbol_t *creerSymbol(char* name);
void empiler(symbol_t *pile, char *name);
int is_symbol_present(symbol_t *symboles, char *name);

#define PARSER_H
#endif /* PARSER_H */