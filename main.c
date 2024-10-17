#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main() {
  char input[256];
  HistoryNode *history = NULL;

  while (1) {
    printf("$ "); // Prompt user
    if (fgets(input, sizeof(input), stdin) == NULL) {
      break; // Exit if input fails
    }

    // Store input in history
    add_to_history(&history, input);

    // Echo input back to user
    printf("%s", input);

    // Tokenization logic
    char **tokens = tokenize(input);
    print_tokens(tokens);
    free_tokens(tokens);
  }

  // Free memory before exit
  free_history(history);
  return 0;
}
