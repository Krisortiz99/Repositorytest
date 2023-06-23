#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    char letter;
    struct node* next;
} node;
// Returns number of nodes in the linkedList.
int length(node* head){
    int i = 0;
    while (head != NULL){
        i++;
        head = head->next;
    }
    return i;
}
// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char* toCString(node* head)
{
    
    char L;
    int i = length(head);
    char String[i];
    
        for (int k = 0; k < i; k++){
            L = head->letter;
            String[k] = L;
            head = head->next;
        }
    return String;
}
// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{   node* newNode = (node*) malloc(sizeof(node));
    newNode-> letter = c;
    node* curr = *pHead;
    newNode->next = NULL;
    if (!*pHead)
    {
        *pHead=newNode;
        return;
    }
    while (curr->next != NULL)
        curr = curr->next;
    
    curr->next = newNode;
    
    return curr;
}
// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{   node* temp;
    node* current;
    current = *pHead;
    while(current!= NULL){
        temp = current->next;
        free(current);
        current = temp;
    }
    *pHead=NULL;
}
int main(void) {
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;
    FILE* inFile = fopen("input.txt","r");
    fscanf(inFile, " %d\n", &numInputs);
    while (numInputs-- > 0) {
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++) {
        fscanf(inFile," %c", &c);
        insertChar(&head, c);
        }
        str = toCString(head);
        printf("String is : %s\n", str);
        free(str);
        deleteList(&head);
        if (head != NULL) {
            printf("deleteList is not correct!");
            break;
        }
    }
    fclose(inFile);
}