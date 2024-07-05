#include "LinkedList.h"
#include <iostream>

int main(){

    list* head = nullptr;

    add_list(&head, 10);
    add_list(&head, 20);
    add_list(&head, 30);
    add_list(&head, 40);

    std::cout << "List after adding elements: " << std::endl;

    print_list(&head);

    delete_head(&head);
    
    std::cout << "List after delete one element: " << std::endl;

    print_list(&head);

    delete_list(&head);

    return 0;
    
}
