#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

int main()
{
	struct g_node* lista = malloc(sizeof(struct g_node));
	lista->next = NULL;
	struct g_node* passed = malloc(sizeof(struct g_node));
	passed->next = NULL;
	struct g_node* failed = malloc(sizeof(struct g_node));
	failed->next = NULL;


	push_element_end(lista, "George", 6.23);
	push_element_end(lista, "Mihai", 2.12);
	push_element_end(lista, "Liviu", 8.34);
	push_element_end(lista, "Ana", 6.43);
	push_element_end(lista, "Alex", 3.23);
	push_element_end(lista, "Maria", 2.56);
	push_element_end(lista, "Rebeca", 7.62);
	push_element_end(lista, "Bianca", 5.37);
	push_element_end(lista, "Andrei", 4.93);
	push_element_end(lista, "Alina", 9.59);
	push_element_end(lista, "Catalina", 9.96);

	print_list(lista);

	

	sort_list(lista);
	print_list(lista);

	find_postion_by_name(lista, "Bianca");

	find_postion_by_name(lista, "Ionut");

	separate_lists(lista, passed, failed);

	printf("Concurentii admisi:\n");
	print_list(passed);
	printf("Concurentii respinsi:\n");
	print_list(failed);


	return 0;
}
