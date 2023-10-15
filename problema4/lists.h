#pragma once
struct g_node {
    char name[25];
    float grade;
    struct g_node* next;
};

void push_element_begining(struct g_node* head, char* new_name, float new_grade);
void push_element_end(struct g_node* head, char* new_name, float new_grade);
int find_postion_by_name(struct g_node* head, char* searched_name);
int separate_lists(struct g_node* head, struct g_node* passed, struct g_node* failed);
void sort_list(struct g_node* head);
void print_list(struct g_node* head);
