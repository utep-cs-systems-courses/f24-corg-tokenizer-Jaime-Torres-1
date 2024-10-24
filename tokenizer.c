#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"

// Check if the character is a space or tab
int space_char(char c) {
  return (c == ' ' || c == '\t');
}

// Check if the character is not a space or tab
int non_space_char(char c) {
  return !space_char(c);
}

// Find the start of the first token
char *token_start(char *s) {
  while (*s && space_char(*s)) {
    s++;
  }
  return (*s ? s : NULL);  // Return the first non-space character or NULL
}

// Find the terminator of the token
char *token_terminator(char *token) {
  while (*token && non_space_char(*token)) {
    token++;
  }
  return token;  // Return the pointer to the character after the token
}

// Count the number of tokens in the string
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

// Create a copy of the string with specified length
char *copy_str(char *inStr, short len) {
  char *newStr = malloc(len + 1); // +1 for the null terminator
  if (newStr) {
    strncpy(newStr, inStr, len);
    newStr[len] = '\0';  // Null terminate the new string
  }
  return newStr;
}

// Tokenize the input string
char **tokenize(char *s) {
  int token_count = count_tokens(s);
  char **tokens = malloc((token_count + 1) * sizeof(char *)); // +1 for NULL terminator
  if (!tokens) return NULL;

  char *token = token_start(s);
  int index = 0;

  while (token) {
    char *end = token_terminator(token);
    tokens[index] = copy_str(token, end - token);
    index++;
    token = token_start(end);
  }
  tokens[index] = NULL; // Null terminate the array
  return tokens;
}

// Print the tokens
void print_tokens(char **tokens) {
  if (!tokens) return;
  for (int i = 0; tokens[i] != NULL; i++) {
    printf("Token %d: %s\n", i + 1, tokens[i]);
  }
}

// Free the tokens
void free_tokens(char **tokens) {
  if (!tokens) return;
  for (int i = 0; tokens[i] != NULL; i++) {
    free(tokens[i]);
  }
  free(tokens);
}


