#include <stdio.h>
#include <stdlib.h>

/*Ʈ���� ���� ����ü�� �������� �ʴ�����?
�ϳ��� ��常 �����Ͽ���, ����Ʈ���� �����ϱ� �����̴�.
*/
typedef struct _bTreeNode
{

    int data;
    struct _bTreeNode *left;
    struct _bTreeNode *right;

} TreeNode;

TreeNode *MakeNode(); // ����� ����

void setData(TreeNode *node, int data); // ��忡 ������ ����
int getData(TreeNode *node);            // ��忡 ����� ������ ��ȯ

void SetLeftSubTree(TreeNode *parentNode, TreeNode *nodeToAdd);  // ���� ���� Ʈ���� ����
void SetRightSubTree(TreeNode *parentNode, TreeNode *nodeToAdd); // ������ ����Ʈ���� ����
TreeNode *GetLeftSubTree(TreeNode *parentNode);                  // ���� ���� Ʈ���� �ּҹ�ȯ
TreeNode *GetRightSubTree(TreeNode *parentNode);                 // ������ ���� Ʈ���� �ּҹ�ȯ
void Inorder(TreeNode *node);
void Preorder(TreeNode *node);
void Postorder(TreeNode *node);

int main()
{
    TreeNode *node1 = MakeNode();
    setData(node1, 1);
    TreeNode *node2 = MakeNode();
    setData(node2, 2);
    TreeNode *node3 = MakeNode();
    setData(node3, 3);
    TreeNode *node4 = MakeNode();
    setData(node4, 4);
    TreeNode *node5 = MakeNode();
    setData(node5, 5);
    TreeNode *node6 = MakeNode();
    setData(node6, 6);

    SetLeftSubTree(node1, node2);
    SetRightSubTree(node1, node3);
    SetLeftSubTree(node2, node4);
    SetRightSubTree(node2, node5);
    SetRightSubTree(node3, node6);

    printf("Node1�� ���� : %d\n", getData(GetLeftSubTree(node1)));
    printf("Node2�� ������ : %d\n\n", getData(GetRightSubTree(node2)));
    printf("preorder : ");
    Preorder(node1);
    printf("\n");

    printf("inorder : ");
    Inorder(node1);
    printf("\n");

    printf("postorder : ");
    Postorder(node1);
    printf("\n");
    return 0;
}
TreeNode *MakeNode()
{

    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void setData(TreeNode *node, int data)
{

    node->data = data;
}
int getData(TreeNode *node)
{

    return node->data;
}

void SetLeftSubTree(TreeNode *parentNode, TreeNode *nodeToAdd)
{

    if (parentNode->left != NULL)
        free(parentNode->left);

    parentNode->left = nodeToAdd;
}
void SetRightSubTree(TreeNode *parentNode, TreeNode *nodeToAdd)
{

    if (parentNode->right != NULL)
        free(parentNode->right);

    parentNode->right = nodeToAdd;
}
TreeNode *GetLeftSubTree(TreeNode *parentNode)
{

    return parentNode->left;
}
TreeNode *GetRightSubTree(TreeNode *parentNode)
{

    return parentNode->right;
}

void Inorder(TreeNode *node)
{
    if (node == NULL)
        return;
    Inorder(node->left);
    printf("%d ", node->data);
    Inorder(node->right);
}
void Preorder(TreeNode *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    Preorder(node->left);
    Preorder(node->right);
}
void Postorder(TreeNode *node)
{
    if (node == NULL)
        return;
    Postorder(node->left);
    Postorder(node->right);
    printf("%d ", node->data);
}