#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//int InsertNode(ListNode *ptrhead, int value);


typedef struct Node {
	struct Node *next;
	int data;
}Node;

Node* head;
void init() {
	head = NULL;
}

void insert(int data) {
    Node* ptr;
    Node* newNode = (Node*)malloc(sizeof(Node));    // newNode 할당 
    newNode->data = data;    // 데이터 할당 
    newNode->next = NULL;    // next 포인터 초기화 

    if (head == NULL) {    // empty
        head = newNode;
    }
    else {
        if (head->data > newNode->data) {    // not empty, 가장 앞에 노드 추가 
            newNode->next = head;
            head = newNode;
            return;
        }
        for (ptr = head; ptr->next; ptr = ptr->next) {    // 중간에 노드 추가 
            if (ptr->data < newNode->data && ptr->next->data > newNode->data) {
                newNode->next = ptr->next;
                ptr->next = newNode;
                return;
            }
        }

        ptr->next = newNode;    // 마지막에 노드 추가  
    }

}

void printList() {
    Node* ptr;
    for (ptr = head; ptr->next; ptr = ptr->next) {
        printf("%d->", ptr->data);
    }
    printf("%d\n", ptr->data);
}

int main()
{
    srand((unsigned)time(NULL));
    int temp = 0;
    init();

    for (int i = 0;i < 50;i++) {
        temp = 1 + rand() % 100;
        insert(temp);
    }

    printList();

	return 0;
}


/*
int insertNode(ListNode **ptrhead, int value) {
	ListNode* tempNode = (ListNode*)malloc(sizeof(ListNode));
	if (!tempNode) return -1;
	tempNode->value = value;
	tempNode->next = *ptrhead;
	*ptrHead = tempNode;
	return -1;
}

Node * list1 = (int *)malloc(sizeof(Node));
list1->next = NULL;
*/
