#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
	struct TreeNode* left;
	char* data;
	struct TreeNode* right;
} TreeNode;

// 노드 생성
TreeNode* createNode(const char* data) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = (char*)malloc(strlen(data) + 1);
	strcpy(node->data, data);
	node->left = NULL;
	node->right = NULL;
	return node;
}

// 트리 메모리 해제
void freeTree(TreeNode* node) {
	if (node == NULL) return;
	freeTree(node->left);
	freeTree(node->right);
	free(node->data);
	free(node);
}

// 전위 순회 (Preorder): 루트 -> 왼쪽 -> 오른쪽
void preorder(TreeNode* node) {
	if (node == NULL) return;
	printf("%s ", node->data);
	preorder(node->left);
	preorder(node->right);
}

// 중위 순회 (Inorder): 왼쪽 -> 루트 -> 오른쪽
void inorder(TreeNode* node) {
	if (node == NULL) return;
	inorder(node->left);
	printf("%s ", node->data);
	inorder(node->right);
}

// 후위 순회 (Postorder): 왼쪽 -> 오른쪽 -> 루트
void postorder(TreeNode* node) {
	if (node == NULL) return;
	postorder(node->left);
	postorder(node->right);
	printf("%s ", node->data);
}

int main() {
	TreeNode* root;

	TreeNode* node1 = createNode("화사");
	root = node1;

	TreeNode* node2 = createNode("솔라");
	node1->left = node2;

	TreeNode* node3 = createNode("문별");
	node1->right = node3;

	TreeNode* node4 = createNode("휘인");
	node2->left = node4;

	TreeNode* node5 = createNode("쿼위");
	node2->right = node5;

	TreeNode* node6 = createNode("선미");
	node3->left = node6;

	// 출력
	printf("전위 순회 (Preorder): ");
	preorder(root);
	printf("\n");

	printf("중위 순회 (Inorder): ");
	inorder(root);
	printf("\n");

	printf("후위 순회 (Postorder): ");
	postorder(root);
	printf("\n");

	// 메모리 해제
	freeTree(root);

	return 0;
}