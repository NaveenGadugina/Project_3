#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    printf("Welcome to the Linked List Operations Program!\n");
    printf("Select the type of linked list you want to work with:\n");
    printf("1. Singly Linked List\n");
    printf("2. Doubly Linked List\n");
    printf("3. Circular Singly Linked List\n");
    printf("Select an option\n");

    int opt;
    scanf("%d", &opt);
    switch(opt){
        case 1:
            // Call the function for singly linked list
            printf("You selected Singly Linked List.\n");
           sll();
            break;
        case 2:
            // Call the function for doubly linked list
            printf("You selected Doubly Linked List.\n");
            dll();
            break;
        case 3:
            // Call the function for circular singly linked list
            printf("You selected Circular Singly Linked List.\n");
            scll();
            break;
	default:
            printf("Invalid option. Please select a valid option.\n");
    }
}

//sll.c
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL; // Initialize head to NULL

void printll();

void ins_beg() {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    printf("Enter the data of the new node: \n");

    scanf("%d", &new_node->data);

    new_node->next = head;
    head = new_node;

    printll();
}

void ins_aft()
{
    struct node *ptr, *preptr;
    int pos;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Enter the data of the node after which the new node is to be inserted: \n");
    scanf("%d", &pos);
    printf("Enter the data of the new node: ");
    scanf("%d", &new_node->data);
    preptr = head;
    if (preptr == NULL) {
        printf("List is empty.\n");
        free(new_node);
        return;
    }
    ptr = preptr->next;
    while (preptr != NULL && preptr->data != pos)
    {
        ptr = preptr->next;
        preptr = preptr->next;
    }
    if (preptr == NULL) {
        printf("Node with data %d not found.\n", pos);
        free(new_node);
        return;
    }
    new_node->next = ptr;
    preptr->next = new_node;

    printll();
}

void ins_bef() {
    struct node *ptr, *preptr;
    int pos;

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
         printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Enter the data of the node before which the new node is to be inserted: \n");
    scanf("%d", &pos); // <-- fixed missing semicolon

    printf("Enter the data of the new node: ");
    scanf("%d", &new_node->data);

    // Handle if list is empty
    if (head == NULL) {
        printf("List is empty. Cannot insert before.\n");
        free(new_node);
        return;
    }

    // Special case: insert before the first node
    if (head->data == pos) {
        new_node->next = head;
        head = new_node;
        printll();
        return;
    }

    preptr = head;
    ptr = head->next;

    while (ptr != NULL && ptr->data != pos) {
        preptr = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Node with data %d not found.\n", pos);
        free(new_node);
        return;
    }

    new_node->next = ptr;
    preptr->next = new_node;

    printll();
}

void del_beg()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *ptr;
    ptr = head;
    head = ptr->next;
    free(ptr);

    printll();
}

void del_mid()
{
    if(head == NULL){
        printf("List is empty.\n");
    }
    else{
        struct node *ptr, *preptr;
        int data;
        printf("Enter the data of the node to be deleted \n");
        scanf("%d", &data);

        // Special case: delete head
        if (head->data == data) {
            ptr = head;
            head = head->next;
            free(ptr);
            printll();
            return;
        }

        preptr = head;
        ptr = preptr->next;
        while (ptr != NULL && ptr->data != data)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        if (ptr == NULL) {
            printf("Node with data %d not found.\n", data);
            return;
        }
        preptr->next = ptr->next;
        free(ptr);

        printll();
    }
}

void del_end()
{
    if(head==NULL){
        printf("The list is empty");
    }
    else if (head->next == NULL) {
        // Only one node
        free(head);
        head = NULL;
        printll();
    }
    else{
        struct node *ptr, *preptr;
        preptr = head;
        ptr = preptr->next;
        while (ptr->next != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = NULL;
        free(ptr);

        printll();
    }
}

void printll()
{
    struct node *ptr = head;
    if(head == NULL){
        printf("The list is empty");
    }

    else{
        printf("The list is:\n");
    while (ptr != NULL)
    {

        printf("%d\n ", ptr->data);
        ptr = ptr->next;
    } }
}

void clearll() {
    struct node *ptr = head;
    while (ptr != NULL) {
        struct node *temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    head = NULL;
}

int sll()
{
    int opt;
    while (1)
    {
        printf("---------Operations on Linked list---------\n");
        printf("1. Insertion in the beginning\n");
        printf("2. Insertion at the end\n");
        printf("3. Insertion after the specified node\n");
        printf("4. Insertion before the specified node\n");
        printf("5. Deletion in the beginning\n");
        printf("6. Deletion of specific node\n");
        printf("7. Deletion at the End\n");
        printf("8. Print the linked list\n");
        printf("9. Exit\n");

        printf("Select the operation to be performed\n");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            ins_beg();
            break;
        case 2:
            ins_end();
            break;
        case 3:
            ins_aft();
            break;
        case 4:
            ins_bef();
            break;
        case 5:
            del_beg();
            break;
        case 6:
            del_mid();
            break;
        case 7:
            del_end();
            break;
        case 8:
            printll();
            break;
        case 9:
            clearll(); // free memory before exit
            exit(0);
            break;
        default:
            printf("Invalid option\n");
        }
    }
    return 0;
}

def greet(name):
    """Return a greeting message."""
    return f"Hello, {name}!"

if __name__ == "__main__":
    name = input("Enter your name: ")
    print(greet(name))

