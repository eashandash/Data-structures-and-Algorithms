//palindrome

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
        char data;
        struct node *next;
};

typedef struct node NODE;

NODE *head = NULL, *current;
char str[30],revStr[30];

/* Function definition */
void pushChar(char str[],int size);
void checkPalindrome(char str[], char revStr[]);
void print(void);
void destroy(void);

int main(void) {

        printf("Enter your choice\n1.Enter character for string\n2.Check Palindrome\n3.Print String(befor reversal)\n4.Exit\n");
        int ch, size;

        while(1) {
                scanf("%d",&ch);
                switch(ch) {
                        case 1: printf("Enter the string\n");
                                scanf("%s",str);
                                size = strlen(str);
                                pushChar(str,size);
                                break;
                        case 2: checkPalindrome(str,revStr);
                                destroy();
                                break;
                        case 3: print();
                                break;
                        case 4: exit(0);
                }
        }
return 0;
}

/* pushChar function definition */
void pushChar(char str[], int size) {
        int i;
        for(i = 0; i < size; i++) {
                NODE *new_node = malloc(sizeof(struct node));
                if(head == NULL) {
                        head = new_node;
                        new_node->data = str[i];
                        new_node->next = NULL;
                        current = head;
                }
                else {
                        new_node->data = str[i];
                        new_node->next = NULL;
                        current->next = new_node;
                        current = new_node;
                }
        }
}

/* checkPalindrome function definition */
void checkPalindrome(char str[], char revStr[]) {
    NODE *prev   = NULL;
    NODE *current = head;
    NODE *next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    NODE *temp = head;
    int i = 0;
    while(temp != NULL)
    {
        revStr[i] = temp->data;
        temp = temp->next;
        i++;
    }
    revStr[i] = '\0';
    int val;
    val = strcmp(str,revStr);
    if(val!=0) {
      printf("It is not a Palindrome\n");
    }
    else {
      printf("It is a Palindrome\n");
    }
}

/* print function definition */
void print(void) {
  NODE *temp = head;
  while(temp != NULL)
  {
      printf("%c",temp->data);
      temp = temp->next;
  }
}

/* destroy */
void destroy(void)
{
    NODE *top1 = head;

    while (top1 != NULL)
    {
        top1 = head->next;
        free(head);
        head = top1;
        top1 = top1->next;
    }
    free(top1);
    head = NULL;
}
