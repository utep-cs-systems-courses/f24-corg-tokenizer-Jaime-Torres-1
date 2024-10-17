#ifndef HISTORY_H
#define HISTORY_H

typedef struct HistoryNode {
  int id;
  char *string;
  struct HistoryNode *next;
} HistoryNode;

void add_to_history(HistoryNode **history, char *input);
void print_history(HistoryNode *history);
char *recall_history(HistoryNode *history, int id);
void free_history(HistoryNode *history);

#endif // HISTORY_H
