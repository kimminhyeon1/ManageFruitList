#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_last(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	strcpy(node->data, data);
	node->link = NULL;
	if (head == NULL) {
		return node;
	}
	else {
		ListNode* p = head;
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = node;
		return head;
	}
}

ListNode* search_list(ListNode* head, element x) {
	ListNode* p = head;

	while (p != NULL) {
		if (strcmp(p->data, x) == 0) {
			return p;
		}
		p = p->link;
	}
	return NULL;
}

ListNode* delete(ListNode* head, element data) {
	ListNode* removed = head;
	ListNode* pre = NULL;
	while (removed != NULL && strcmp(removed->data, data) != 0) {
		pre = removed;
		removed = removed->link;
	}
	if (removed == NULL) {
		return head;
	}
	else if (pre == NULL) {
		head = head->link;
	}
	else {
		pre->link = removed->link;
	}
	free(removed);
	return head;
}
void print_list(ListNode* head) {
	ListNode* p = head;
	if (p == NULL) {
		printf("목록이 비어있습니다.");
	}
	while (p != NULL) {
		printf("%s ", p->data);
		p = p->link;
	}
	printf("\n");
}

int main() {
	ListNode* head = NULL;
	ListNode* DeletedHead = NULL;
	element data;
	int choice;
	
	head = insert_last(head, "Mango");
	head = insert_last(head, "Orange");
	head = insert_last(head, "Apple");
	head = insert_last(head, "Grape");
	head = insert_last(head, "Cherry");
	head = insert_last(head, "Plum");
	head = insert_last(head, "Guava");
	head = insert_last(head, "Raspberry");
	head = insert_last(head, "Banana");
	head = insert_last(head, "Peach");
	

	while (1) {
		printf("\n메뉴\n");
		printf("1.리스트의 맨 마지막에 새로운 과일 추가\n");
		printf("2.리스트에 있는 과일을 삭제\n");
		printf("3.삭제된 과일 목록 출력\n");
		printf("4.종료\n");
		printf("선택하세요: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("추가할 과일 이름을 입력하시오: ");
			scanf("%s", data);
			if (search_list(head, data) != NULL) {
				printf("리스트에 이미 존재하는 과일입니다.\n");
			}
			else {
				head = insert_last(head, data);
				printf("리스트에 추가하였습니다.\n");
			}
			break;
		case 2:
			printf("삭제할 과일 이름을 입력하시오: ");
			scanf("%s", data);
			if (search_list(head, data) != NULL) {
				head = delete(head, data);
				DeletedHead = insert_last(DeletedHead, data);
				printf("해당 과일을 삭제하였습니다.\n");
			}
			else {
				printf("리스트에 해당 과일이 없습니다.\n");
			}
			break;
		case 3:
			printf("삭제된 과일 목록: ");
			print_list(DeletedHead);
			break;
		case 4:
			exit(0);
		default:
			printf("잘못된 선택입니다.\n");
		}
	}
	return 0;
}