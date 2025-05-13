#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
	struct TreeNode* left;
	char* data;
	struct TreeNode* right;
} TreeNode;

TreeNode* createNode(const char* data) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = (char*)malloc(strlen(data) + 1);  // 문자열 공간 확보
	strcpy(node->data, data);                      // 문자열 복사
	node->left = NULL;
	node->right = NULL;
	return node;
}
void freeTree(TreeNode* node) {
	if (node == NULL) return;
	freeTree(node->left);
	freeTree(node->right);
	free(node->data);
	free(node);
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
	printf("%s\n", root->data);
	printf("%s %s\n", root->left->data, root->right->data);
	printf("%s %s %s\n", root->left->left->data, root->left->right->data, root->right->left->data);

	// 메모리 해제
	freeTree(root);

	return 0;
}
