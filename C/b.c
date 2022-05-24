#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
	struct node* left;
	long id;
	float grade;
	struct node* right;
} SNODETYPE;

int insert_node(SNODETYPE* root, long sid, float grade);
SNODETYPE* search(SNODETYPE* root, long keyid);
void inorder(SNODETYPE* root);
void over4(SNODETYPE* root);

void main(int argc, char* argv[])
{
	SNODETYPE* tree = NULL;
	SNODETYPE* ptr;
	long sid;
	float grade;
	FILE* input;


	if ((input = fopen("student.txt", "r")) == NULL) {
		printf("Invalid Open input file...\n");
		exit(1);
	}

	while (fscanf(input, "%ld %f", &sid, &grade) != EOF) {
		if (!tree) {
			tree = (SNODETYPE*)malloc(sizeof(SNODETYPE));
			tree->id = sid;
			tree->left = tree->right = NULL;
			tree->grade = grade;
		}
		else
			insert_node(tree, sid, grade);
	}
	printf("\n-------- 저장된 트리 순회 리스트 ---------\n");

	inorder(tree);

	printf("Enter student id number to search: ");
	scanf("%ld", &sid);
	ptr = search(tree, sid);
	if (ptr) {
		printf("%ld is in this tree(%.2f).\n", ptr->id, ptr->grade);
	}
	else {
		printf("%ld is not exist.\n", sid);
	}
	printf("\n4.0이상인 학생 검색결과 : \n");
	over4(tree);
}

SNODETYPE* search(SNODETYPE* root, long keyid) {
	SNODETYPE* tptr = root;

	while (tptr) {

		if (keyid < tptr->id)
			tptr = tptr->left;
		else if (keyid > tptr->id)
			tptr = tptr->right;
		else // found
			return tptr;
	}
	return NULL; // not found
}

int insert_node(SNODETYPE* root, long sid, float grade) {
	SNODETYPE* tptr = root, * before = NULL;
	int left;
	while (tptr) {
		if (sid < tptr->id) {
			before = tptr;
			tptr = tptr->left;
			left = 1;
		}
		else if (sid > tptr->id) {
			before = tptr;
			tptr = tptr->right;
			left = 0;
		}
		else { // found
			return 0;
		}
	}
	tptr = (SNODETYPE*)malloc(sizeof(SNODETYPE));
	tptr->id = sid;
	tptr->left = tptr->right = NULL;
	tptr->grade = grade;
	if (left) before->left = tptr;
	else before->right = tptr;
	return 1;
}

void inorder(SNODETYPE* ptr) {

	if (ptr) {
		inorder(ptr->left);
		printf("%ld\n", ptr->id);
		inorder(ptr->right);
	}

}

void over4(SNODETYPE* ptr) {

	if (ptr) {
		over4(ptr->left);
		if (ptr->grade >= 4.0)
			printf("%ld\t%.2f\n", ptr->id, ptr->grade);
		over4(ptr->right);
	}
}