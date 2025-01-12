#include <stdio.h>
#include <stdlib.h>

/*트리에 대한 구조체를 선언하지 않는이유?
하나의 노드만 존재하여도, 이진트리를 만족하기 때문이다.
*/
typedef struct _bTreeNode
{

    int data;
    struct _bTreeNode *left;
    struct _bTreeNode *right;

} TreeNode;

TreeNode *MakeNode(); // 노드의 생성

void setData(TreeNode *node, int data); // 노드에 데이터 저장
int getData(TreeNode *node);            // 노드에 저장된 데이터 반환

void SetLeftSubTree(TreeNode *parentNode, TreeNode *nodeToAdd);  // 왼쪽 서브 트리의 연결
void SetRightSubTree(TreeNode *parentNode, TreeNode *nodeToAdd); // 오른쪽 서브트리의 연결
TreeNode *GetLeftSubTree(TreeNode *parentNode);                  // 왼쪽 서브 트리의 주소반환
TreeNode *GetRightSubTree(TreeNode *parentNode);                 // 오른쪽 서브 트리의 주소반환
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

    printf("Node1의 왼쪽 : %d\n", getData(GetLeftSubTree(node1)));
    printf("Node2의 오른쪽 : %d\n\n", getData(GetRightSubTree(node2)));
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