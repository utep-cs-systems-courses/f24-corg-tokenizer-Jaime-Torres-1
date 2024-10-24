#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    // Trim newline character
    input[strcspn(input, "\n")] = 0;

    // Check if input is a recall command
    if (input[0] == '!') {
      int id = atoi(&input[1]); // Convert to integer
      char *recalled = recall_history(history, id);
      if (recalled) {
	printf("Recalled: %s\n", recalled);
	strcpy(input, recalled); // Use recalled input for tokenization
      } else {
	printf("No history for ID %d\n", id);
	continue; // Skip the rest of the loop
      }
    } else {
      // Store input in history
      add_to_history(&history, input);
    }
    // Echo input back to user
    printf("%s\n", input);

    // Tokenization logic
    char **tokens = tokenize(input);
    print_tokens(tokens);
    free_tokens(tokens);
  }

  // Free memory before exit
  free_history(history);
  return 0;
}
