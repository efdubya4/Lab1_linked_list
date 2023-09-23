// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

list_t *list_alloc() { 
  list_t* mylist =  (list_t *) malloc(sizeof(list_t)); 
  mylist->head = NULL;
}

void list_free(list_t *l) {Node* current = list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

void list_print(list_t *l) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

}

char * listToString(list_t *l) {
  char* buf = (char *) malloc(sizeof(char) * 1024);
  char tbuf[20];

	node_t* curr = l->head;
  while (curr != NULL) {
    sprintf(tbuf, "%d->", curr->value);
    curr = curr->next;
    strcat(buf, tbuf);
  }
  strcat(buf, "NULL");
  return buf;
}

int list_length(list_t *l) { 
    int length = 0;
    Node* current = list->head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}


void list_add_to_back(list_t *l, elem value) {
    Node* newNode = createNode(value);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void list_add_to_front(list_t *l, elem value) {
     node_t* cur_node = (node_t *) malloc(sizeof(node_t));
     cur_node->value = value;
     cur_node->next = NULL;

     /* Insert to front */

     node_t* head = l->head;  // get head of list

     cur_node->next = head;
     head = cur_node;


}
void list_add_at_index(list_t *l, elem value, int index) {
    if (index < 0) {
        fprintf(stderr, "Invalid index: %d\n", index);
        return;
    }
}

elem list_remove_from_back(list_t *l) { {
    if (list->head == NULL) {
        fprintf(stderr, "List is empty\n");
        return -1; // Return a default value (you can change this as needed)
    }

    Node* current = list->head;
    Node* prev = NULL;

    // Traverse to the last node
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    // Store the data to be returned
    elem removedValue = current->data;

    // Remove the last node
    if (prev != NULL) {
        prev->next = NULL;
    } else {
        list->head = NULL;
    }

    free(current);
    return removedValue;
}
 }
elem list_remove_from_front(list_t *l) { 
    if (list->head == NULL) {
        fprintf(stderr, "List is empty\n");
        return -1; // Return a default value (you can change this as needed)
    } 
elem list_remove_at_index(list_t *l, int index) { 
    if (list->head == NULL) {
        fprintf(stderr, "List is empty\n");
        return -1; // Return a default value (you can change this as needed)
    }

    if (index < 0) {
        fprintf(stderr, "Invalid index: %d\n", index);
        return -1; // Return a default value (you can change this as needed)
    }

    if (index == 0) {
        return list_remove_from_front(list);
    }

    Node* current = list->head;
    Node* prev = NULL;
    int currentIndex = 0;

    while (current != NULL && currentIndex < index) {
        prev = current;
        current = current->next;
        currentIndex++;
    }

    if (current == NULL) {
        fprintf(stderr, "Invalid index: %d\n", index);
        return -1; // Return a default value (you can change this as needed)
    }

    elem removedValue = current->data;
    prev->next = current->next;
    free(current);
    return removedValue;
}

bool list_is_in(list_t *l, elem value) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == value) {
            return true; // Element found in the list
        }
        current = current->next;
    }
    return false; // Element not found in the list
}

elem list_get_elem_at(list_t *l, int index) {
    if (index < 1) {
        fprintf(stderr, "Invalid index: %d\n", index);
        return -1; // Return an error value (you can change this as needed)
    }

    Node* current = list->head;
    int currentIndex = 1;

    while (current != NULL && currentIndex < index) {
        current = current->next;
        currentIndex++;
    }

    if (current == NULL) {
        fprintf(stderr, "Index out of bounds: %d\n", index);
        return -1; // Return an error value (you can change this as needed)
    }

    return current->data;
}

int list_get_index_of(list_t *l, elem value) {
    Node* current = list->head;
    int currentIndex = 0;

    while (current != NULL) {
        currentIndex++;
        if (current->data == value) {
            return currentIndex; // Element found, return its index (starting from 1)
        }
        current = current->next;
    }

    return -1; // Element not found in the list
}


