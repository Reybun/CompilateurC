#include "buffer.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include "lexer.h"
#include "parser.h"
#include "ast.h"


//gcc -Wall -o app *.c

int main()
{
    buffer_t *buffer = malloc(sizeof(buffer_t));
    FILE *fp = fopen("test.txt", "r");
<<<<<<< HEAD
=======
    symbol_t *symboles = malloc(sizeof(symbol_t));
>>>>>>> a459b3217c5716481c9915d5c0fc751a86365492

    buf_init(buffer, fp);

    //char letter = buf_getchar(buffer);

    //char* nb = lexer_getalphanum_rollback(buffer);
    //printf("\n %s \n", nb);

    /*
    char* p = lexer_getalphanum(buffer);
    printf("%s", p);
    buf_print(buffer);



    lexer_assert_twopoints(buffer, "expected :");
    */

   //parser(buffer, symboles);
    symbol_t *symb = creer_symbole("name", SYM_VAR, ast_new_integer(1l));
    int result = is_symbol_present(symb, "name");

    printf("\n result is %d \n", result);




   //afficher ast
    return 0;
}