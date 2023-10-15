#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lists.h"

void push_element_begining(struct g_node* head, char* new_name, float new_grade) {
    struct g_node* new_element = malloc(sizeof(struct g_node));

    strcpy(new_element->name, new_name);
    new_element->grade = new_grade;
    new_element->next = head->next;
    head->next = new_element;
}

void push_element_end(struct g_node* head, char *new_name, float new_grade) {
    struct g_node* new_element = malloc(sizeof(struct g_node));
    struct g_node* iterator = head;
    struct g_node* last_element;

    while (iterator->next != NULL) {
        iterator = iterator->next;
    }
    last_element = iterator;

    last_element->next = new_element;
    strcpy(new_element->name, new_name);
    new_element->grade = new_grade;
    new_element->next = NULL;
}

int find_postion_by_name(struct g_node* head, char* searched_name) {
    int position = -1; //list is empty
    struct g_node* iterator = head;
    int element_found = 0;

    while (iterator->next != NULL) {
        if (!strcmp(iterator->name, searched_name)){
            element_found = 1;
            break;
        }
        position++;
        iterator = iterator->next;
    }

    if (element_found == 1) {
        printf("%s %.2f\n", iterator->name, iterator->grade);
        printf("------------------------"); printf("\n");
        //return position;
    }
    else {
        printf("Concurentul %s nu se afla in lista.\n", searched_name);
        printf("------------------------"); printf("\n");
        //return -2; // not found in list
    }

}

int separate_lists(struct g_node* head, struct g_node* passed, struct g_node* failed) {
    struct g_node* iterator = head;
    
    

    while (iterator->next != NULL) {
        if (iterator->next->grade >= 5) 
            push_element_end(passed, iterator->next->name, iterator->next->grade);
        else
            push_element_end(failed, iterator->next->name, iterator->next->grade);

        iterator = iterator->next;
    }
}

void swap_nodes(struct g_node* node1, struct g_node* node2) {
    float aux_grade; char aux_name[25];

    aux_grade = node1->grade;
    node1->grade = node2->grade;
    node2->grade = aux_grade;

    strcpy(aux_name, node1->name);
    strcpy(node1->name, node2->name);
    strcpy(node2->name, aux_name);
}

void sort_list(struct g_node* head) {
    struct g_node* iterator1;
    struct g_node* iterator2;
    struct g_node* min;

    iterator1 = head;

    while (iterator1->next->next != NULL) {
        min = iterator1;
        iterator2 = iterator1->next;
        
        while (iterator2->next != NULL) {
            if (iterator2->grade < min->grade) {
                min = iterator2;
            }
            iterator2 = iterator2->next;
        }
        if (min->grade < iterator1->grade) {
            swap_nodes(min, iterator1);
        }
        iterator1 = iterator1->next;

    }
}

void print_list(struct g_node* head) {
    struct g_node* iterator = head;
    while (iterator->next != NULL) {
        printf("%s %.2f ", iterator->next->name, iterator->next->grade);
        printf("\n");
        iterator = iterator->next;
    }
    printf("------------------------"); printf("\n");
}