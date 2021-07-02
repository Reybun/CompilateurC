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
    symbols *symboles = malloc(sizeof(symbols));

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
   ast_list_t *list = malloc(sizeof(ast_list_t));
   list->data = ast_new_integer(23l);
   printf("\n GOT %d \n", list->data->type);




   //afficher ast
    return 0;
}