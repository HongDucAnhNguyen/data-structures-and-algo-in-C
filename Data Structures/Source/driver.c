#include <stdio.h>
#include <stdlib.h>
#include "../Header Files/SLL_DS_functions.h"



int main() {

	int option = -1;
	int data = -1;
	int index = -1;

	Node* head = NULL;
	Node* result = NULL;


	while (1) {

		printf("Choose an option [1-12]:\n");
		printf("0. Exit program\n1. Insert:\n2. Insert at index\n3. Prepend\n");
		printf("4. Remove at beginning\n5. Remove at end\n6. Remove at index\n");
		printf("7. Show list\n9. Check if empty\n10. Find node by value\n11. Find node by index\n12. Reverse the list\n");
		printf("Enter option: ");
		scanf_s("%d", &option);


		switch (option)
		{
		case 1:

			printf("Selected option: Insert\n");
			printf("Enter data of node: ");
			scanf_s("%d", &data);


			printf("\n");
			insert_at_end(data, head, &head);
			break;
		case 2:
			printf("Selected option: Insert at index\n");
			printf("Enter data of node: ");
			scanf_s("%d", &data);

			printf("\n");

			printf("Enter index of node: ");
			scanf_s("%d", &index);

			printf("\n");
			insert_at_index(data, index, head, &head);
			break;
		case 3:
			printf("Selected option: Prepend\n");
			printf("Enter data of node: ");
			scanf_s("%d", &data);

			printf("\n");


			insert_at_beginning(data, &head);
			break;
		case 4:
			printf("Selected option: Remove at beginning\n");
			remove_at_beginning(&head, head);
			break;
		case 5:
			printf("Selected option: Remove at end\n");
			remove_at_end(head);
			break;
		case 6:
			printf("Selected option: Remove at index\n");


			printf("Enter index of node: ");
			scanf_s("%d", &index);

			printf("\n");
			remove_at_index(index, head, &head);
			break;
		case 7:
			printf("Selected option: Show list\n");
			traverse_linked_list(head);
			break;

		case 9:
			printf("Selected option: Check if empty\n");
			printf("Linked list is %s", is_empty(head) ? "empty\n" : "not empty\n");
			break;
		case 10:
			printf("Selected option: Find by Value\n");
			printf("Enter data of node: ");
			scanf_s("%d", &data);



			printf("\n");
			result = find_element_by_value(data, head);
			if (result == NULL) {
				printf("No matching nodes found\n");
			}
			break;
		case 11:
			printf("Selected option: Find by index\n");

			printf("Enter index of node: ");
			scanf_s("%d", &index);

			printf("\n");
			result = find_element_by_index(index, head);
			if (result == NULL) {
				printf("No matching nodes found\n");
			}
			break;
		case 12:
			printf("Selected option: Reverse List\n");

			reverse_linked_list(head, &head);
			break;
		case 0:
			printf("Selected option: Exit program\n");
			free_list(head);
			printf("GOODBYE!\n");
			exit(0); // Exit the program


		default:
			printf("Invalid option! Please choose again.\n");
			break;
		}




	}
	return 0;
}

bool is_empty(Node* head) {


	return (head == NULL);

}


void traverse_linked_list(Node* head) {
	Node* current_location = head;
	while (current_location != NULL) {
		printf("%d --> ", current_location->data);
		current_location = current_location->next_node_ptr;
	}
	printf("\n");
}

void free_list(Node* head) {

	Node* current_location = head;
	Node* next_node = NULL;
	while (current_location != NULL) {

		next_node = current_location->next_node_ptr;
		free(current_location);
		current_location = next_node;
	}
	if (next_node != NULL) {
		free(next_node);
	}
	printf("Linked list is freed from mem\n");

}



//-------------------INSERTION------------------------------//

void insert_at_beginning(int node_data, Node** ptr_to_head_ptr) {




	Node* new_node = malloc(sizeof(Node));


	new_node->data = node_data;

	//dereference to get head_ptr value which is head node's mem
	new_node->next_node_ptr = *ptr_to_head_ptr;


	//reassign headptr val to mem of new node
	*ptr_to_head_ptr = new_node;



}
void insert_at_end(int node_data, Node* head, Node** ptr_to_head_ptr)
{

	if (is_empty(head)) {
		insert_at_beginning(node_data, ptr_to_head_ptr);

	}

	else {
		Node* current_location = head;
		Node* new_node = malloc(sizeof(Node));
		new_node->data = node_data;
		new_node->next_node_ptr = NULL;



		while (current_location->next_node_ptr != NULL) {

			current_location = current_location->next_node_ptr;



		}
		current_location->next_node_ptr = new_node;
	}





}


int insert_at_index(int node_data, int insert_index, Node* head, Node** ptr_to_head_ptr)
{

	if (insert_index == 0) {

		insert_at_beginning(node_data, ptr_to_head_ptr);
		return 0;
	}


	if (is_empty(head)) {

		printf("list is currently empty\n");
		return 0;
	}


	Node* node_retrieved = find_element_by_index(insert_index, head);
	if (node_retrieved == NULL) {
		printf("No matching nodes found\n");
		return 1;
	}


	Node* new_node = malloc(sizeof(Node));

	new_node->data = node_data;
	new_node->next_node_ptr = node_retrieved->next_node_ptr;

	node_retrieved->next_node_ptr = new_node;


	return 0;
}

//-------------------INSERTION------------------------------//





//-------------------FIND ELEMENT------------------------------//
Node* find_element_by_value(int node_data, Node* head) {

	int index_counter = 0;
	Node* current_location = head;
	while (current_location != NULL) {
		if (current_location->data == node_data) {
			printf("\nfound the first node with matching val at index: %d\n", index_counter);
			return current_location;
		}

		current_location = current_location->next_node_ptr;
		index_counter += 1;

	}



	return NULL;

}


Node* find_element_by_index(int node_index, Node* head) {

	int index_counter = 0;
	Node* current_location = head;
	while (current_location != NULL) {
		if (index_counter == node_index) {
			printf("\nfound node with matching index with value: %d\n", current_location->data);
			return current_location;
		}

		current_location = current_location->next_node_ptr;
		index_counter += 1;
	}



	return NULL;

}
//-------------------FIND ELEMENT------------------------------//






//-------------------REMOVAL----------------------------------//

int remove_at_index(int remove_index, Node* head, Node** ptr_to_head_ptr)
{
	if (remove_index == 0) {
		remove_at_beginning(ptr_to_head_ptr, head);
		return 0;
	}
	if (is_empty(head)) {

		printf("list is currently empty\n");
		return 0;
	}

	Node* node_retrieved = find_element_by_index(remove_index, head);
	if (node_retrieved == NULL) {
		printf("\nNo matching nodes found\n");
		return 1;
	}



	Node* node_before_target_node = find_element_by_index(remove_index - 1, head);

	node_before_target_node->next_node_ptr = node_retrieved->next_node_ptr;


	free(node_retrieved);





	return 0;

}

void remove_at_end(Node* head)
{

	if (is_empty(head)) {

		printf("list is currently empty\n");
	}
	else {
		Node* current_location = head;
		while (current_location->next_node_ptr->next_node_ptr != NULL) {

			current_location = current_location->next_node_ptr;

		}
		free(current_location->next_node_ptr->next_node_ptr);
		current_location->next_node_ptr = NULL;
	}


}

void remove_at_beginning(Node** ptr_to_head_ptr, Node* head)
{


	if (is_empty(head)) {

		printf("list is currently empty\n");
	}
	else {
		Node* prev_head_next = head->next_node_ptr;
		free(head);

		*ptr_to_head_ptr = prev_head_next;
	}
}

//-------------------REMOVAL----------------------------------//


//-------REVERSAL------------//


void reverse_linked_list(Node* head, Node** ptr_to_head_ptr) {

	Node* current = head;
	Node* prev = NULL;
	Node* next = NULL;
	int index_counter = 0;
	while (current != NULL) {

		next = current->next_node_ptr;
		current->next_node_ptr = prev;
		prev = current;
		current = next;
		index_counter += 1;
	}
	*ptr_to_head_ptr = prev;


}


//-------REVERSAL------------//


