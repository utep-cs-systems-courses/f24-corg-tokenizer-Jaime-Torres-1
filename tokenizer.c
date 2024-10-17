#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"

int space_char(char c) {
  return (c == ' ' || c == '\t');
}

int non_space_char(char c) {
  return (c != ' ' && c != '\t' && c != '\0');
}

char *token_start(char *s) {
  while (*s && space_char(*s)) {
    s++;
  }
  return (*s ? s : NULL);
}

char *token_terminator(char *token) {
  while (*token && non_space_char(*token)) {
    token++;
  }
  return token;
}

int count_tokens(char *s) {
  int count = 0;
  char *token = token_start(s);
  while (token) {
    count++;
    token = token_terminator(token);
    token = token_start(token);
  }
  return count;
}

char *copy_str(char *inStr, short len) {
  char *copy = malloc(len + 1);
  if (copy) {
    strncpy(copy, inStr, len);
    copy[len] = '\0'; // Null-terminate the string
  }
  return copy;
}


char **tokenize(char *s) {
  int num_tokens = count_tokens(s);
  char **tokens = malloc((num_tokens + 1) * sizeof(char *));
  if (!tokens) return NULL;

  char *token;
  int i = 0;
  token = token_start(s);
  while (token) {
    char *end = token_terminator(token);
    tokens[i++] = copy_str(token, end - token);
    token = token_start(end);
  }
  tokens[i] = NULL; // Null-terminate the array of tokens
  return tokens;
}

void print_tokens(char **tokens) {
  for (int i = 0; tokens[i] != NULL; i++) {
    printf("Token %d: %s\n", i + 1, tokens[i]);
  }
}

void free_tokens(char **tokens) {
  for (int i = 0; tokens[i] != NULL; i++) {
    free(tokens[i]);
  }
  free(tokens);
}
