#include "buffer.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include "lexer.h"
#include "parser.h"


//gcc -Wall -o app *.c

int main()
{
    buffer_t *buffer = malloc(sizeof(buffer_t));
    FILE *fp = fopen("test.txt", "r");
    symbol_t *symboles = malloc(sizeof(symbol_t));

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

   parser(buffer, symboles);


   //afficher ast
    return 0;
}