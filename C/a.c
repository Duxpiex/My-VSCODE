#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	struct node* left;	
	char* word;
	int count;
	struct node* right;
} NODETYPE;

int build_node(NODETYPE* root, char* str);
NODETYPE* search(NODETYPE* root, char* key);
void traversal(NODETYPE* root);

void main()
{
	NODETYPE* tree = NULL, * ptr;
	char wbuf[30];

	printf("검색트리에 저장할 단어를 입력하시고 입력의 끝에는 quit를 입력하세요.\n");

	while (strcmp(gets(wbuf), "quit")) {
		if (!tree) {
			tree = (NODETYPE*)malloc(sizeof(NODETYPE));
			tree->word = (char*)malloc(strlen(wbuf) + 1);
			strcpy(tree->word, wbuf);
			tree->count = 1;
			tree->left = tree->right = NULL;
		}
		else
			build_node(tree, wbuf);

   }
   printf("\n\nEnter a key to search: ");
   gets(wbuf);
   ptr = search(tree, wbuf);
	   if (ptr)
		   printf("%s is in this tree.\n\n", ptr->word);
	   else
		   printf("%s is not exist.\n\n", wbuf);
   printf("------트리안의 단어들 (사전식 순서) -------\n\n");
   traversal(tree);
}

NODETYPE* search(NODETYPE* root, char* key) {
	NODETYPE* tptr = root;
	int cmp;
	while (tptr) {
		cmp = strcmp(key, tptr->word);
		if (cmp < 0)
			tptr = tptr->left;

		else if (cmp > 0)
			tptr = tptr->right;
		else //found
			return tptr;
	}
	return NULL;
}

int build_node(NODETYPE* root, char* word) {
	NODETYPE* tptr = root, * before;
	NODETYPE* temp = NULL;
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
		else {
			(tptr->count)++;
			return 0;
		}

	}


	temp = (NODETYPE*)malloc(sizeof(NODETYPE));
	temp->word = (char*)malloc(strlen(word)+1);
	strcpy(temp->word, word);
	temp->count = 1;
	temp->left = temp->right = NULL;
	if (cmp < 0) before->left = temp;
	else before->right = temp;
	return 1;
}

void traversal(NODETYPE* head) {
	if (head) {
		traversal(head->left);
		printf("%s\t%d\n", head->word, head->count);
		traversal(head->right);
	}
}

