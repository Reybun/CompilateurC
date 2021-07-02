#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lexer.h"
#include "parser.h"


void parser(buffer_t * buffer) {
    while (buf_eof(buffer) == false)
    {
        char *first = lexer_getalphanum(buffer);
        if(strcmp(first, "fonction") != 0) {
            printf("----------------- Expected function but was %s \n", first); 
            exit(EXIT_FAILURE);
        }
        else {
            analyse_fonction(buffer);
        }      
    }
}

void analyse_fonction(buffer_t * buffer) {
    /*
    Algorithme analyse_fonction():

    Début
    - analyse du lexème qui sera le nom de la fonction
    - appel de analyse_paramètres()
    - appel de analyse_type_de_retour()
    - appel de analyse_corps_de_fonction()
    - création de l’AST pour la fonction “main” avec les paramètres, type de retour et corps de fonction
    - ajout du symbole correspondant au nom de la fonction dans la table des symboles
    - retourner l’AST pour la fonction “main”
    Fin
    */

    char *name = lexer_getalphanum(buffer);
    analyse_parametre(buffer);
    analyse_type_de_retour(buffer);
    analyse_corps_de_fonction(buffer);
}

void analyse_parametre(buffer_t * buffer) {

    lexer_assert_openbrace(buffer, "Expected (");
    int should_continue = 1;
    while (should_continue == 1)
    {
        char *type = lexer_getalphanum(buffer);
        if(strcmp(type, "entier") != 0) {
            printf("Expected a type but was %s \n", type); 
            exit(EXIT_FAILURE);
        }
        
        char *name = lexer_getalphanum(buffer);
        /*
        vérification de l’inexistance du lexème dans la table des symboles
        si le symbole n’existe pas, l’ajouter dans la table des symboles
        */
        
        int count = is_symbol_present(symboles, name);
        if(count == 0) {
            empiler(symboles, name);
        } else {
            printf("There is already a variable with the name %s \n", type); 
            exit(EXIT_FAILURE);
        }
        /*
        créer l’AST correspondant à la variable
        ajouter l’AST à la liste des paramètres
        */

        //todo : create ast methode for nodes

        /*
        si le prochain symbole de ponctuation est ‘,’, continuer sinon si c’est ‘)’, arrêter
        */

        char next = buf_getchar_after_blank(buffer);
        if(next == ',') {
           //continue
        } 
        else if (next == ')')
        {
           //stop the while 
           should_continue = 0;
        } else
        {
            printf("Expected , or ) but got %c \n", next); 
            exit(EXIT_FAILURE);
        }
    }
    //return params but we have it in symbols
    
}

void analyse_corps_de_fonction(buffer_t * buffer) {}
void analyse_type_de_retour(buffer_t * buffer) {}

symbol_t *creer_symbole(char* name, sym_type_t type, ast_t *attributes) {
    symbol_t *symbole = (symbol_t *)malloc(sizeof(symbol_t));
    symbole->name = name;
    symbole->type = type;
    symbole->attributes = attributes;
    symbole->next = NULL;
    symbole->function_table = NULL;
    return symbole;
}

void empiler(symbol_t **pile, symbol_t *symbole){
    symbol_t *temp;

    temp = *pile;
    if (temp != NULL)
    {
        if (temp->name != NULL)
        {
            symbole->next = temp;
        }
        pile = &symbole;
    }
}

int is_symbol_present(symbol_t *pile, char *name) {

    symbol_t *temp = pile;
    int found = 0;

    while (temp != NULL)
    {
        if(temp->name == name){
            found++;
        }
        temp = temp->next;
    }
    return found;
}