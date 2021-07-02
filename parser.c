#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lexer.h"
#include "parser.h"

void parser(buffer_t *buffer, symbol_t *symboles)
{
    while (buf_eof(buffer) == false)
    {
        char *first = lexer_getalphanum(buffer);
        if (strcmp(first, "fonction") != 0)
        {
            printf("----------------- Expected function but was %s \n", first);
            exit(EXIT_FAILURE);
        }
        else
        {
            analyse_fonction(buffer, symboles);
        }
    }
}

void analyse_fonction(buffer_t *buffer, symbol_t *symboles)
{
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
    analyse_parametre(buffer, symboles);
    analyse_type_de_retour(buffer);
    analyse_corps_de_fonction(buffer);
}

void analyse_parametre(buffer_t *buffer, symbol_t *symboles)
{

    lexer_assert_openbrace(buffer, "Expected (");
    int should_continue = 1;
    while (should_continue == 1)
    {
        char *type = lexer_getalphanum(buffer);
        if (strcmp(type, "entier") != 0)
        {
            printf("Expected a type but was %s \n", type);
            exit(EXIT_FAILURE);
        }

        char *name = lexer_getalphanum(buffer);
        /*
        vérification de l’inexistance du lexème dans la table des symboles
        si le symbole n’existe pas, l’ajouter dans la table des symboles
        */
        int count = is_symbol_present(symboles, name);
        if (count == 0)
        {
            empiler(symboles, name);
        }
        else
        {
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
        if (next == ',')
        {
            //continue
        }
        else if (next == ')')
        {
            //stop the while
            //stop the while
            should_continue = 0;
        }
        else
        {
            printf("Expected , or ) but got %c \n", next);
            exit(EXIT_FAILURE);
        }
    }
    //return params but we have it in symbols
}

void analyse_corps_de_fonction(buffer_t *buffer) {}
void analyse_type_de_retour(buffer_t *buffer) {}

int is_symbol_present(symbols *symboles, char *name)
{

    symbol *temp = symboles->datas;
    int found = 0;

    while (temp != NULL)
    {
        printf("%s ", temp->name);
        if (temp->name == name)
        {
            found++;
        }
        temp = temp->next;
    }
    return found;
}

void empiler(symbols *pile, char *name)
{
    if (pile != NULL)
    {
        symbol *op = creerSymbol(name);
        if (pile->datas != NULL)
        {
            op->next = pile->datas;
        }
        pile->datas = op;
    }
}

symbol *creerSymbol(char *name)
{
    symbol *op = (symbol *)malloc(sizeof(symbol));
    op->name = name;
    op->next = NULL;
    return op;
}
