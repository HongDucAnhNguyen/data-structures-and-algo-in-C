#pragma once

#include <stdbool.h>
#include "./node.h"
#include <stdlib.h>

bool is_empty(Node* head);
void traverse_linked_list(Node* head);
void free_list(Node* head);


Node* find_element_by_value(int node_data, Node* head);
Node* find_element_by_index(int node_index, Node* head);


void insert_at_beginning(int node_data, Node** pointer_to_head_pointer);
void insert_at_end(int node_data, Node* head, Node** pointer_to_head_pointer);
int insert_at_index(int node_data, int insert_index, Node* head, Node** pointer_to_head_pointer);



int remove_at_index(int remove_index, Node* head, Node** pointer_to_head_pointer);
void remove_at_end(Node* head);
void remove_at_beginning(Node** pointer_to_head_pointer, Node* head);




