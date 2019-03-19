#include <stdlib.h>
#include <time.h>
#include<stdio.h>

//only global variable for counting purpose
int counter=0;

typedef struct node {
    int value;
    struct node* next;
}Node ;

/**
 * Add node to front of the list. Covers empty list situation.
 * @param value
 * @param head
 */
void insert(int value, Node** head) {
    if(*head == NULL){
        *head = malloc(sizeof(Node));
        if(*head==NULL) {
            fprintf(stderr, "malloc falied\n");
            exit(-1);
        }
        (*head)->value = value;
        (*head)->next = NULL;
    } else {
        Node *oldHead = *head;
        *head = malloc(sizeof(Node));
        if(*head==NULL) {
            fprintf(stderr, "malloc falied\n");
            exit(-1);
        }
        (*head)->value=value;
        (*head)->next= oldHead;
    }
}

/**
 * Deletes element from list (makes previous pointer skip one value and point to one after deleted value).
 * @param value
 * @param head
 * @return {0} if found and deleted, {1} if not found.
 */
int delete(int value, Node** head){
    if(*head==NULL) {
        return 0;
    }

    Node* temp = (*head)->next;
    Node* previous=*head;

    /**
     *  If deleted value is in head, assign next element as a head.
     */
    if(counter++, (*head)->value==value){ //comparison
        *head=((*head)->next);
        return 1;
    }

    /**
     * Program will be here only if deleted value wasn't found in head. Then, if list contains only head, return false.
     */
    if((*head)->next==NULL){
        return 0;
    }

     /**
      * Code specific for situation where searched value is in second place - therefore we need direct reference to head pointer.
      */
    if(counter++, temp->value==value){ //comparison
        (*head)->next=temp->next;
        return 1;
    }

    /**
     * Iterate through nodes; if proper value is found it makes previous element point to value pointed by deleted element.
     */
    do {
      if(counter++, temp->value==value){   //comparison
          previous->next=temp->next;
        return 1;
      }
    } while(temp->next!=NULL, previous=temp,temp=temp->next);

    return 0;
}

/**
 *  Check if head pointer points to some value (aka list is not empty).
 * @param head
 * @return 0 if list is empty, 1 if not.
 */
int isEmpty(Node *head) {
    if (head==NULL){
        return 1;
    }
    else return 0;
}

/**
 * Its
 * @param head
 * @param value
 * @return {0} if found and moved, {1} if not found.
 */
int findMTF (Node** head, int value) {
    if(isEmpty(*head)==1){
        return 0;
    }
    if(delete(value, head)==1){
        insert(value, head);
        return 1;
    }
    return 0;
}
/**
 * Moves found value one place "up" in head direction. Its simply changing value between two adjacent nodes (using temp value).
 */
int findTRANS(Node** head, int value) {
    if(isEmpty(*head)==1){
        return 0;
    }

    Node* current = (*head)->next;
    Node* previus=*head;
    int temp;

    if(counter++, (*head)->value==value) {  //comparison
        //nothing to do here, already in front BUT found this value
        return 1;
    }

    if((*head)->next==NULL){
        return 0;
    }

    if (counter++, current->value==value){ //comparison
        temp=(*head)->value;
        (*head)->value=current->value;
        current->value=temp;
        return 1;
    }

    do {
        if(counter++, current->value==value){  //comparison
            temp=previus->value;
            previus->value=current->value;
            current->value=temp;
            return 1;
        }

    } while(current->next!=NULL, previus=current,current=current->next);

    return 0;
}
/**
 * Prints values till next pointer is NULL
 * @param head
 * @return
 */
int print(Node *head){
    if(isEmpty(head)==1){
        printf("empty list");
        return 1;
    }
    Node* temp = head;
    int counter=0;
    printf("Head-> ");
    do {
        counter++;
        printf("%d ; ", temp->value);
    } while(temp->next!=NULL, temp=temp->next);
    printf("<-End.  Nr of elements: %d\n\n", counter);
    return 0;
}

void randomFill(Node** head) {
    //Uncomenting srand function will result in (almost) true random values.
    srand(time(NULL));
    int numbers[100];
    for(int i=0;i<100;i++){
        numbers[i]=rand()%100+1;
    }
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(numbers[i]==numbers[j] && i!=j){
                numbers[j]=rand()%100+1;
                i=0;
            }
        }
    }
    for(int i=0;i<100;i++){
        insert(numbers[i], head);
    }
}

void testWithTRANS(Node** head){
    counter=0;
    int max;
    while(isEmpty(*head)==0) {
        max=1;
        for (int i = 1; i <= 100; i++) {
            if(findTRANS(head, i)==1 && i>max){max=i;}
        }
        delete(max, head);
    }
    printf("Comparison(TRANS): %d\n", counter);
}

void testWithMTF(Node** head){
    counter=0;
    int max;
    while(isEmpty(*head)==0) {
        max=1;
        for (int i = 1; i <= 100; i++) {
            if(findMTF(head, i)==1 && i>max){max=i;}
        }
        delete(max, head);
    }
    printf("Comparison(MTF): %d\n", counter);
}

int main() {
    Node* head = NULL;
    Node* head2 = NULL;
    randomFill(&head);
    randomFill(&head2);
    print(head);
    print(head2);

    testWithMTF(&head);
    testWithTRANS(&head2);

    return 1;
}