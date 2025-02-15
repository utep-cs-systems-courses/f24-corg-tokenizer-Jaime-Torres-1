#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"

void add_to_history(HistoryNode **history, char *input) {
  HistoryNode *new_node = malloc(sizeof(HistoryNode));
  if (!new_node) return;

  new_node->id = (*history ? (*history)->id + 1 : 1);
  new_node->string = strdup(input); // Duplicate the input string
  new_node->next = *history; // Link the new node to the history
  *history = new_node; // Update history to point to the new node
}

void print_history(HistoryNode *history) {
  while (history) {
    printf("%d: %s", history->id, history->string);
    history = history->next;
  }
}

char *recall_history(HistoryNode *history, int id) {
  while (history) {
    if (history->id == id) {
      return history->string;
    }
    history = history->next;
  }
  return NULL;
}

void free_history(HistoryNode *history) {
  while (history) {
    HistoryNode *temp = history;
    history = history->next;
    free(temp->string);
    free(temp);
  }
}
