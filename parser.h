#ifndef PARSER_H
#include "lexer.h"

typedef struct symbol
{
    char* name;
    struct symbol *next;
} symbol;

typedef struct symbols
{
    symbol *datas;
} symbols;

void parser(buffer_t * buffer, symbols *symboles);
void analyse_fonction(buffer_t * buffer, symbols *symboles);
void analyse_parametre(buffer_t * buffer, symbols *symboles);
void analyse_type_de_retour(buffer_t * buffer);
void analyse_corps_de_fonction(buffer_t *buffer);

symbol *creerSymbol(char* name);
void empiler(symbols *pile, char *name);
int is_symbol_present(symbols *symboles, char *name);

#define PARSER_H
#endif /* PARSER_H */