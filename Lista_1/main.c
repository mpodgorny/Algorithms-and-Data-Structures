//Czyste C

#include <unistd.h>
#include <malloc.h>
//biblioteki potrzebne do rand(), malloc() oraz printf()
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
        (*head)->value = value;
        (*head)->next = NULL;
    } else {
        Node *oldHead = *head;
        *head = malloc(sizeof(Node));
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
    Node* previus=head;


    /**
     *  If deleted value is in head, assign next element as a head.
     */
    if(++counter>-1 && (*head)->value==value){ //comparison
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
    if(++counter>-1 && temp->value==value){ //comparison
        (*head)->next=temp->next;
        return 1;
    }



    do {
      if(++counter>-1 && temp->value==value){   //comparison
          /**
           * If found, make list skip this element.
           */
          previus->next=temp->next;
        return 1;
      }

    } while(temp->next!=NULL, previus=temp,temp=temp->next);

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
    if(isEmpty(head)==1){
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
    if(isEmpty(head)==1){
        return 0;
    }

    Node* current = (*head)->next;
    Node* previus=head;
    int temp;

    if(++counter>-1 && (*head)->value==value) {  //comparison
        //nothing to do here, already in front BUT found this value
        return 1;
    }

    if((*head)->next==NULL){
        return 0;
    }

    if (++counter>-1 && current->value==value){ //comparison
        temp=(*head)->value;
        (*head)->value=current->value;
        current->value=temp;
        return 1;
    }

    do {
        if(++counter>-1 && current->value==value){  //comparison
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
    /**
     * uncommenting @srand will result in (almost) real random values.
     */
    //srand(time(NULL));
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

int main() {
    Node* head = NULL;
    Node* head2 = NULL;
    randomFill(&head2);

    randomFill(&head);
    print(head);
    counter=0;
    int max=1;
    while(isEmpty(head)==0) {
        max=1;
        for (int i = 1; i <= 100; i++) {
            if(findTRANS(&head, i)==1 && i>max){max=i;}
        }
        delete(max, &head);

    }
    printf("%d comparison(TRANS)\n", counter);

    randomFill(&head);
    print(head);
    printf("")
    counter=0;
    while(isEmpty(head)==0) {
        max=1;
        for (int i = 1; i <= 100; i++) {
            if(findMTF(&head, i)==1 && i>max){max=i;}
        }
        delete(max, &head);
    }
    printf("%d comparison(MTF)\n", counter);



    return 0;
}