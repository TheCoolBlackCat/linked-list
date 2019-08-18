#include <malloc.h>

typedef struct node {
    int c;
    struct node* next;
} node;

//node* blank_list();
node* create_node(int c);
void print_list(node* head);
node* add_to_list(node** head, int c);
int pop_from_list(node** head);
int remove_from_list(node* head);
void reverse_list(node** head);

/// Creates a blank singly-linked list
//node* blank_list() {
//    return NULL;
//}

/// Creates a new node, pointing to NULL
node* create_node(int c) {
  node *n = malloc(sizeof(node));
  n->c = c;
  n->next = NULL;
  return n;
}

/// Prints a singly-linked list
void print_list(node* head) {
  node* current = head;
    while (current != NULL) {
        printf("%c -> ", current->c);
        current = current->next;
    }
    printf("NULL\n");
}

/// Adds a new node to the singly-linked list
node* add_to_list(node** head, int c) {
    // Empty List
    if (*head == NULL) {
        *head = create_node(c);
        return *head;
    }
//    printf("HIT\n");

    // Appending
    node* current = *head;
    while (current->next)
        current = current->next;
    current->next = create_node(c);
    return current;
}

/// Removes a node from the end of a singly-linked list and returns its value
int remove_from_list(node* head) {
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
int pop_from_list(node** head) {
  node* removed = *head;
  int r = removed->c;
  node* newHead = removed->next;
  free(removed);
  *head = newHead;
  return r;
}

/// Reverse a linked list
void reverse_list(node** head) {
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
