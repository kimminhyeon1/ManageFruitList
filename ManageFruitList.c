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
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;
}

ListNode* delete(ListNode* head, ListNode* node) {
	ListNode* removed, * pre;
	if (head == NULL)return;
	else if(head == head->link) {
		removed = head;
		head = NULL;
	}
	else {
		pre = node->link;
		while (pre->link != node) {
			pre = pre->link;
		}
		removed = node;
		pre->link = removed->link;
		node = pre;
	}
	free(removed);
	return head;
}
void print_list(ListNode* head) {
	ListNode* p;

}
ListNode* search_list(ListNode* head, element x) {
	ListNode* p = head;

	while (p != NULL) {
		if (p->data == x) return p;
		p = p->link;
	}
	return NULL;
}
int main() {
	ListNode* head = NULL;
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
	element data;
	int choice;
	ListNode* p;

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
			getchar();
			if (search_list(head, data) != NULL) {
				printf("리스트에 이미 존재하는 과일입니다.\n");
			}
			else {
				insert_last(head, data);
				printf("리스트에 추가하였습니다.\n");
			}
			break;
		case 2:
			printf("삭제할 과일 이름을 입력하시오: ");
			scanf("%s", data);
			getchar();
			p = search_list(head, data);
			if (search_list(head, data) != NULL) {
				delete(head, p);
				printf("해당 과일을 삭제하였습니다.\n");
			}
			else {
				printf("리스트에 해당 과일이 없습니다.\n");
			}
			break;
		case 3:
			break;
		case 4:
			exit(0);
		default:
			printf("잘못된 선택입니다.\n");
		}
	}
}