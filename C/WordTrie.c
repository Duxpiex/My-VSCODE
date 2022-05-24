#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node { // 이진 트리의 노드 정의
	struct node* left; // 왼쪽
	char* word;			// 입력받은 단어를 저장할  변수
	struct node* right; // 오른쪽

} NODETYPE; // 이름

int insert_node(NODETYPE* root, char* str); // 함수 선언
NODETYPE* search(NODETYPE* root, char* key);
void inorder(NODETYPE* root);




void main() // 메인 함수
{
	NODETYPE* tree = NULL; // NULL로 초기화
	NODETYPE* ptr;
	char wbuf[30];

	printf(" 검색 트리에 저장할 단어를 입력하세요.\n 입력의 끝에는 quit를 입력하세요.\n");

	while (strcmp(gets(wbuf), "quit")) { // quit를 입력할 때까지
		if (!tree) { // 트리가 비었을 때	
			tree = (NODETYPE*)malloc(sizeof(NODETYPE)); // NODETYPE 만큼의 메모리 할당
			tree->word = (char*)malloc(strlen(wbuf) + 1);
			strcpy(tree->word, wbuf);
			tree->left = tree->right = NULL;
		}
		else
			insert_node(tree, wbuf);
	}
	printf("\n\nEnter a key to search: "); // 찾을 단어 입력
	gets(wbuf);
	ptr = search(tree, wbuf); 
	if (ptr)
		printf("%s is in this tree.\n\n", ptr->word);
	else
		printf("%s is not exist.\n\n", wbuf);

	printf("------ 트리 안의 단어들 (사전식 순서) --------\n");
	inorder(tree);
}

NODETYPE* search(NODETYPE* root, char* key) {
	NODETYPE* tptr = root;
	int cmp;
	while (tptr) {
		cmp = strcmp(key, tptr->word);
		if (cmp < 0)
			tptr = tptr->left; // 왼쪽 탐색
		else if (cmp > 0)
			tptr = tptr->right; // 오른쪽 탐색
		else // found 
			return tptr;
	}
	return NULL; // not found

}


int insert_node(NODETYPE* root, char* word) {
	NODETYPE* tptr = root, * before = NULL;
	int cmp;
	while (tptr) {
		cmp = strcmp(word, tptr->word);
		if (cmp < 0) {
			before = tptr;
			tptr = tptr->left;
		}
		else if (cmp > 0) {
			before = tptr;
			tptr = tptr->right;
		}
		else // found
			return 0;
	}
	tptr = (NODETYPE*)malloc(sizeof(NODETYPE));
	tptr->word = (char*)malloc(strlen(word) + 1);
	strcpy(tptr->word, word);
	tptr->left = tptr->right = NULL;
	if (cmp < 0) before->left = tptr;
	else before->right = tptr;
	return 1;
}

void inorder(NODETYPE* ptr) {
	if (ptr) {
		inorder(ptr->left); 
		printf("%s\n", ptr->word); 
		inorder(ptr->right);
	}
}