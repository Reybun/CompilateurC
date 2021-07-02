#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <string.h>  
#include <ctype.h>
#include "lexer.h"

char * lexer_getalphanum (buffer_t * buffer) {
    char letter = buf_getchar(buffer);

    int sizeAlloc = 1;
    char* preresult = malloc(sizeof(char)*(sizeAlloc * LEXEM_SIZE));
    int nb = 0;
    int cptAlloc = 0;
    
    while (isalpha(letter) || isdigit(letter) )
    {
        if(nb == LEXEM_SIZE - 1) {
            sizeAlloc++;
            preresult = realloc(preresult, sizeof(char)*(sizeAlloc * LEXEM_SIZE));
            cptAlloc = 0;
        }
        //DO STUFF
        append(preresult, letter);
        nb++;
        cptAlloc++;
        letter = buf_getchar(buffer);
    } 
    buf_lock(buffer);
    buf_rollback(buffer, 1);
    buf_unlock(buffer);
    
    //buf_rollback(buffer, nb);

    return preresult;    
}

char * lexer_getalphanum_rollback(buffer_t * buffer){
    char letter = buf_getchar(buffer);

    int sizeAlloc = 1;
    char* preresult = malloc(sizeof(char)*(sizeAlloc * LEXEM_SIZE));
    int nb = 0;
    int cptAlloc = 0;
    
    while (isalpha(letter) || isdigit(letter) )
    {
        if(cptAlloc == LEXEM_SIZE - 1) {
            sizeAlloc++;
            preresult = realloc(preresult, sizeof(char)*(sizeAlloc * LEXEM_SIZE));
            cptAlloc = 0;
        }
        append(preresult, letter);
        nb++;
        cptAlloc++;
        letter = buf_getchar(buffer);
    } 
    
    buf_lock(buffer);
    buf_rollback(buffer, nb +1);
    buf_unlock(buffer);

    return preresult;    

}

long lexer_getnumber (buffer_t * buffer) {
    char chiffre = buf_getchar(buffer);

    int sizeAlloc = 1;
    char* preresult = malloc(sizeof(char)*(sizeAlloc * LEXEM_SIZE));

    int nb = 0;
    int cptAlloc = 0;

    if(chiffre == '-') {
        append(preresult, chiffre);
        nb++;
        cptAlloc++;
        chiffre = buf_getchar(buffer);
    }

    while (isdigit(chiffre))
    {
        if(nb == LEXEM_SIZE - 1) {
            sizeAlloc++;
            preresult = realloc(preresult, sizeof(char)*(sizeAlloc * LEXEM_SIZE));
            cptAlloc = 0;
        }
        //DO STUFF
        append(preresult, chiffre);
        //preresult += chiffre;
        nb++;
        cptAlloc++;
        chiffre = buf_getchar(buffer);
    } 

    return strtol(preresult, NULL, 10);

}

void append(char* string, char car) {
     int len = strlen(string);
     string[len] = car;
     string[len+1] = '\0';
}

void assert_msg(char car, char wanted, char *msgerror) {
    if(car != wanted) printf(" %s \n ", msgerror);
    exit(EXIT_FAILURE);
}

void lexer_assert_simplechar (buffer_t *buffer, char chr, char *msg){
    assert_msg(buf_getchar(buffer), chr, msg);
}
void lexer_assert_twopoints (buffer_t *buffer, char *msg){
    assert_msg(buf_getchar(buffer), ':', msg);
}
void lexer_assert_newline (buffer_t *buffer, char *msg){
    assert_msg(buf_getchar(buffer), '\n', msg);
}
void lexer_assert_semicolon (buffer_t *buffer, char *msg){
    assert_msg(buf_getchar(buffer), ';', msg);
}
void lexer_assert_openbrace (buffer_t *buffer, char *msg){
    assert_msg(buf_getchar(buffer), '(', msg);
}
void lexer_assert_closebrace (buffer_t *buffer, char *msg){
    assert_msg(buf_getchar(buffer), ')', msg);
}
void lexer_assert_openbracket (buffer_t *buffer, char *msg){
    assert_msg(buf_getchar(buffer), '[', msg);
}
void lexer_assert_closebracket (buffer_t *buffer, char *msg){
    assert_msg(buf_getchar(buffer), ']', msg);
}
void lexer_assert_equalsign (buffer_t *buffer, char *msg){
    assert_msg(buf_getchar(buffer), '=', msg);
}
void lexer_assert_blank (buffer_t *buffer, char *msg){
    assert_msg(buf_getchar(buffer), ' ', msg);
}

//exit(EXIT_FAILURE);