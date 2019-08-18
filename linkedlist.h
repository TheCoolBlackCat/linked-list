#include <malloc.h>

typedef struct node {
    int c;
    struct node* next;
} node;

node* createLL(int c);
node* createNullNode(int c);
void printLL(node* head);
node* addToLL(node* head, int c);
int popFromLL(node** head);
int removeFromLL(node* head);
void reverseLL(node** head);

/// Creates a new singly-linked list
node* createLL(int c) {
    return createNullNode(c);
}

/// Creates a new node, pointing to NULL
node* createNullNode(int c) {
  node *n = (node*) malloc(sizeof(node));
  n->c = c;
  n->next = NULL;
  return n;
}

/// Prints a singly-linked list
void printLL(node* head) {
  node* current = head;
    while (current != NULL) {
        printf("%c -> ", current->c);
        current = current->next;
    }
    printf("NULL\n");
}

/// Appends a new node to the end of a singly-linked list
node* addToLL(node* head, int c) {
    node* current = head;
    while (current->next)
        current = current->next;
    current->next = createNullNode(c);
    return current;
}

/// Removes a node from the end of a singly-linked list and returns its value
int removeFromLL(node* head) {
  int r = 0;
  if (head == NULL) return 0;
  // If one node long
  if (head->next == NULL) {
    r = head->c;
    // free(head);
    head = NULL;
    return r;
  }

  node* current = head;
  while (current->next->next != NULL)
    current = current->next;

  node* removed = current->next;
  r = removed->c;
  free(removed);
  current->next = NULL;
  return r;
}

/// Removes a node from the start of a singly-linked list and returns its value
int popFromLL(node** head) {
  node* removed = *head;
  int r = removed->c;
  node* newHead = removed->next;
  free(removed);
  *head = newHead;
  return r;
}

/// Reverse a linked list
void reverseLL(node** head) {
  node* previous = NULL;
  node* current = *head;
  node* next = NULL;

  while (current != NULL) {
      next = current->next;

      current->next = previous; // Reverse

      previous = current;
      current = next;
  }
  *head = previous;
}
