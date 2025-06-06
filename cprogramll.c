#include <stdio.h>
#include <stdlib.h>

// ----------- Singly Linked List Code -----------

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void printll();
void ins_beg();
void ins_end();
void ins_aft();
void ins_bef();
void del_beg();
void del_mid();
void del_end();
void clearll();

int sll() {
    int opt;
    while (1) {
        printf("\n--------- Operations on Singly Linked List ---------\n");
        printf("1. Insertion in the beginning\n");
        printf("2. Insertion at the end\n");
        printf("3. Insertion after a specified node\n");
        printf("4. Insertion before a specified node\n");
        printf("5. Deletion in the beginning\n");
        printf("6. Deletion of a specific node\n");
        printf("7. Deletion at the end\n");
        printf("8. Print the linked list\n");
        printf("9. Exit to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1: ins_beg(); break;
            case 2: ins_end(); break;
            case 3: ins_aft(); break;
            case 4: ins_bef(); break;
            case 5: del_beg(); break;
            case 6: del_mid(); break;
            case 7: del_end(); break;
            case 8: printll(); break;
            case 9: clearll(); return 0;
            default: printf("Invalid option\n");
        }
    }
}

void printll() {
    struct node *ptr = head;
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }

    printf("The list is:\n");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void ins_beg() {
    struct node *new_node = malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &new_node->data);
    new_node->next = head;
    head = new_node;
    printll();
}

void ins_end() {
    struct node *new_node = malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct node *ptr = head;
        while (ptr->next != NULL) ptr = ptr->next;
        ptr->next = new_node;
    }
    printll();
}

void ins_aft() {
    int pos;
    printf("Enter the data of the node after which to insert: ");
    scanf("%d", &pos);

    struct node *ptr = head;
    while (ptr != NULL && ptr->data != pos) ptr = ptr->next;

    if (ptr == NULL) {
        printf("Node not found.\n");
        return;
    }

    struct node *new_node = malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &new_node->data);
    new_node->next = ptr->next;
    ptr->next = new_node;
    printll();
}

void ins_bef() {
    int pos;
    printf("Enter the data of the node before which to insert: ");
    scanf("%d", &pos);

    struct node *new_node = malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &new_node->data);

    if (head == NULL || head->data == pos) {
        new_node->next = head;
        head = new_node;
        printll();
        return;
    }

    struct node *ptr = head, *prev = NULL;
    while (ptr != NULL && ptr->data != pos) {
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Node not found.\n");
        return;
    }

    new_node->next = ptr;
    prev->next = new_node;
    printll();
}

void del_beg() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    printll();
}

void del_mid() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    int val;
    printf("Enter value to delete: ");
    scanf("%d", &val);

    if (head->data == val) {
        del_beg();
        return;
    }

    struct node *ptr = head, *prev = NULL;
    while (ptr != NULL && ptr->data != val) {
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Node not found\n");
        return;
    }

    prev->next = ptr->next;
    free(ptr);
    printll();
}

void del_end() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct node *ptr = head, *prev = NULL;
        while (ptr->next != NULL) {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = NULL;
        free(ptr);
    }
    printll();
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

// ----------- Circular Singly Linked List Code -----------

struct node2 {
    int data;
    struct node2 *next;
};

struct node2 *start2 = NULL;

void printll2();
void ins_beg2();
void ins_end2();
void ins_aft2();
void ins_bef2();
void del_beg2();
void del_mid2();
void del_end2();

int scll() {
    int opt;
    while (1) {
        printf("\n--------- Operations on Circular Singly Linked List ---------\n");
        printf("1. Insertion in the beginning\n");
        printf("2. Insertion at the end\n");
        printf("3. Insertion after a specified node\n");
        printf("4. Insertion before a specified node\n");
        printf("5. Deletion in the beginning\n");
        printf("6. Deletion of a specific node\n");
        printf("7. Deletion at the end\n");
        printf("8. Print the linked list\n");
        printf("9. Exit to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1: ins_beg2(); break;
            case 2: ins_end2(); break;
            case 3: ins_aft2(); break;
            case 4: ins_bef2(); break;
            case 5: del_beg2(); break;
            case 6: del_mid2(); break;
            case 7: del_end2(); break;
            case 8: printll2(); break;
            case 9: return 0;
            default: printf("Invalid option\n");
        }
    }
}

void printll2() {
    if (start2 == NULL) {
        printf("The list is empty\n");
        return;
    }
    struct node2 *ptr = start2;
    printf("The list is: ");
    do {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    } while (ptr != start2);
    printf("(back to start)\n");
}

void ins_beg2() {
    struct node2 *new_node = malloc(sizeof(struct node2));
    printf("Enter data: ");
    scanf("%d", &new_node->data);
    if (start2 == NULL) {
        start2 = new_node;
        new_node->next = start2;
    } else {
        struct node2 *temp = start2;
        while (temp->next != start2)
            temp = temp->next;
        new_node->next = start2;
        start2 = new_node;
        temp->next = start2;
    }
    printll2();
}

void ins_end2() {
    struct node2 *new_node = malloc(sizeof(struct node2));
    printf("Enter data: ");
    scanf("%d", &new_node->data);
    if (start2 == NULL) {
        start2 = new_node;
        new_node->next = start2;
    } else {
        struct node2 *ptr = start2;
        while (ptr->next != start2)
            ptr = ptr->next;
        ptr->next = new_node;
        new_node->next = start2;
    }
    printll2();
}

void ins_aft2() {
    int pos;
    printf("Enter data of the node after which to insert: ");
    scanf("%d", &pos);
    struct node2 *ptr = start2;
    if (ptr == NULL) {
        printf("List is empty.\n");
        return;
    }
    do {
        if (ptr->data == pos) {
            struct node2 *new_node = malloc(sizeof(struct node2));
            printf("Enter data: ");
            scanf("%d", &new_node->data);
            new_node->next = ptr->next;
            ptr->next = new_node;
            printll2();
            return;
        }
        ptr = ptr->next;
    } while (ptr != start2);
    printf("Node not found\n");
}

void ins_bef2() {
    int pos;
    printf("Enter data of the node before which to insert: ");
    scanf("%d", &pos);

    if (start2 == NULL) {
        printf("List is empty\n");
        return;
    }

    if (start2->data == pos) {
        ins_beg2();
        return;
    }

    struct node2 *ptr = start2, *prev = NULL;
    do {
        prev = ptr;
        ptr = ptr->next;
    } while (ptr != start2 && ptr->data != pos);

    if (ptr->data == pos) {
        struct node2 *new_node = malloc(sizeof(struct node2));
        printf("Enter data: ");
        scanf("%d", &new_node->data);
        new_node->next = ptr;
        prev->next = new_node;
        printll2();
    } else {
        printf("Node not found\n");
    }
}

void del_beg2() {
    if (start2 == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node2 *ptr = start2;
    if (start2->next == start2) {
        free(start2);
        start2 = NULL;
    } else {
        while (ptr->next != start2) ptr = ptr->next;
        struct node2 *temp = start2;
        start2 = start2->next;
        ptr->next = start2;
        free(temp);
    }
    printll2();
}

void del_mid2() {
    int val;
    printf("Enter value to delete: ");
    scanf("%d", &val);
    if (start2 == NULL) {
        printf("List is empty\n");
        return;
    }
    if (start2->data == val) {
        del_beg2();
        return;
    }

    struct node2 *ptr = start2, *prev = NULL;
    do {
        prev = ptr;
        ptr = ptr->next;
    } while (ptr != start2 && ptr->data != val);

    if (ptr->data == val) {
        prev->next = ptr->next;
        free(ptr);
        printll2();
    } else {
        printf("Node not found\n");
    }
}

void del_end2() {
    if (start2 == NULL) {
        printf("List is empty\n");
        return;
    }

    if (start2->next == start2) {
        free(start2);
        start2 = NULL;
        return;
    }

    struct node2 *ptr = start2, *prev = NULL;
    while (ptr->next != start2) {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = start2;
    free(ptr);
    printll2();
}

// ----------- Main Function -----------

int main() {
    int opt;
    printf("Welcome to the Linked List Operations Program!\n");

    while (1) {
        printf("\nSelect the type of linked list you want to work with:\n");
        printf("1. Singly Linked List\n");
        printf("2. Circular Singly Linked List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1: sll(); break;
            case 2: scll(); break;
            case 3: exit(0);
            default: printf("Invalid option.\n");
        }
    }

    return 0;
}
