#include <stdio.h>
#include <stdlib.h>
typedef struct node {
char letter;
struct node* next;
} node;
// Returns number of nodes in the linkedList.
int length(node* head)
{
    int count = 0;
    node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char* toCString(node* head)
{

 int len = length(head);

 char* res = malloc((len+1)*sizeof(char));
 int i=0;

 while (head != NULL) {
 res[i] = head->letter;
 head = head->next;
 i++;
 }

 res[len] = '\0';

 return res;
}
// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
    node* current = *pHead;

    struct node* new_node = malloc(sizeof(node));
    new_node->letter = c;
    new_node->next=NULL;

    if ((*pHead) == NULL)
    {
        (*pHead) = new_node;

    }
    else {
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new_node;
    }
}
// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{

   struct node* current = *pHead;
   struct node* next;

   while (current != NULL)
   {
       next = current->next;
       free(current);
       current = next;
   }

   *pHead = NULL;
}
int main(void)
{
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;
    FILE* inFile = fopen("input.txt","r");
    fscanf(inFile, " %d\n", &numInputs);
    while (numInputs-- > 0)
    {
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++)
        {
            fscanf(inFile," %c", &c);
            insertChar(&head, c);
        }
        str = toCString(head);
        printf("String is : %s\n", str);
        free(str);
        deleteList(&head);
        if (head != NULL)
        {
            printf("deleteList is not correct!");
            break;
        }
    }
    fclose(inFile);
}
