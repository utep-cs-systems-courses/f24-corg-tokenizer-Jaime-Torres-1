#ifndef TOKENIZER_H
#define TOKENIZER_H

int space_char(char c);
int non_space_char(char c);
char *token_start(char *s);
char *token_terminator(char *token);
int count_tokens(char *s);
char *copy_str(char *inStr, short len);
char **tokenize(char *s);
void print_tokens(char **tokens);
void free_tokens(char **tokens);

#endif // TOKENIZER_H
