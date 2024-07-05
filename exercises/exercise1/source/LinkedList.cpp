#include "LinkedList.h"
#include <iostream>

struct List{

    int data;
    list* next;

};


void add_list(list** head, int value){

    list* new_head;
    new_head =  new list;
    new_head->data = value;
    new_head->next = *head;  
    *head = new_head;

}

void delete_head(list** head){
    if(*head != nullptr){
        list* temp;
        temp = *head;
        *head = (*head)->next;
        delete temp;
    }

}

void print_list(list** head){
    list *start = *head;

    while(*head != nullptr){

        std::cout << (*head)-> data << std::endl;
        *head = (*head)->next;  // modify head pointer

    }

    *head = start;   // revert the head pointer after modification

}

void delete_list(list** head){
    list* head_next;

    while(*head != nullptr){
        head_next = (*head)->next;
        delete *head;
        *head = head_next;

    }

}