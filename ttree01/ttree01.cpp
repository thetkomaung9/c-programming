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
	node->data = (char*)malloc(strlen(data) + 1);  // ���ڿ� ���� Ȯ��
	strcpy(node->data, data);                      // ���ڿ� ����
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

	TreeNode* node1 = createNode("ȭ��");
	root = node1;

	TreeNode* node2 = createNode("�ֶ�");
	node1->left = node2;

	TreeNode* node3 = createNode("����");
	node1->right = node3;

	TreeNode* node4 = createNode("����");
	node2->left = node4;

	TreeNode* node5 = createNode("����");
	node2->right = node5;

	TreeNode* node6 = createNode("����");
	node3->left = node6;

	// ���
	printf("%s\n", root->data);
	printf("%s %s\n", root->left->data, root->right->data);
	printf("%s %s %s\n", root->left->left->data, root->left->right->data, root->right->left->data);

	// �޸� ����
	freeTree(root);

	return 0;
}
