#ifndef LEXER_H
#include  "buffer.h"

char * lexer_getalphanum (buffer_t * buffer);
char * lexer_getalphanum_rollback(buffer_t * buffer);
long lexer_getnumber (buffer_t * buffer);
void append(char* string, char car);

void assert_msg(char car, char wanted, char *msgerror);

void lexer_assert_simplechar (buffer_t *buffer, char chr, char *msg); //si chr character
void lexer_assert_twopoints (buffer_t *buffer, char *msg); // : 
void lexer_assert_newline (buffer_t *buffer, char *msg); // /n
void lexer_assert_semicolon (buffer_t *buffer, char *msg); // 
void lexer_assert_openbrace (buffer_t *buffer, char *msg);
void lexer_assert_closebrace (buffer_t *buffer, char *msg);
void lexer_assert_openbracket (buffer_t *buffer, char *msg);
void lexer_assert_closebracket (buffer_t *buffer, char *msg);
void lexer_assert_equalsign (buffer_t *buffer, char *msg);
void lexer_assert_blank (buffer_t *buffer, char *msg);
//CRASH WITH EXIT

char *lexer_getop (buffer_t *buffer); //get operateur

#define LEXER_H
#endif /* LEXER_H */
