#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
	struct TreeNode* left;
	char* data;
	struct TreeNode* right;
} TreeNode;

// ��� ����
TreeNode* createNode(const char* data) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = (char*)malloc(strlen(data) + 1);
	strcpy(node->data, data);
	node->left = NULL;
	node->right = NULL;
	return node;
}

// Ʈ�� �޸� ����
void freeTree(TreeNode* node) {
	if (node == NULL) return;
	freeTree(node->left);
	freeTree(node->right);
	free(node->data);
	free(node);
}

// ���� ��ȸ (Preorder): ��Ʈ -> ���� -> ������
void preorder(TreeNode* node) {
	if (node == NULL) return;
	printf("%s ", node->data);
	preorder(node->left);
	preorder(node->right);
}

// ���� ��ȸ (Inorder): ���� -> ��Ʈ -> ������
void inorder(TreeNode* node) {
	if (node == NULL) return;
	inorder(node->left);
	printf("%s ", node->data);
	inorder(node->right);
}

// ���� ��ȸ (Postorder): ���� -> ������ -> ��Ʈ
void postorder(TreeNode* node) {
	if (node == NULL) return;
	postorder(node->left);
	postorder(node->right);
	printf("%s ", node->data);
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
	printf("���� ��ȸ (Preorder): ");
	preorder(root);
	printf("\n");

	printf("���� ��ȸ (Inorder): ");
	inorder(root);
	printf("\n");

	printf("���� ��ȸ (Postorder): ");
	postorder(root);
	printf("\n");

	// �޸� ����
	freeTree(root);

	return 0;
}