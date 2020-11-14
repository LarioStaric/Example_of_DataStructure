#include <stdio.h>
#include <stdlib.h>
#define STACKINITSIZE 20//ջ��ʼ�ռ��С
#define INCREASEMENT 10//ջ�ռ��С������

typedef struct BiTNode
{
	char data;//�������ڵ�����
	BiTNode *lchild,*rchild;//ָ�����������������������ָ��
}BiTNode,*BiTree,bitnode;//����������ڵ�ṹ

typedef struct SqStack
{
	BiTNode *base;//ջ��ָ��
	BiTNode *top;//ջ��ָ��
	int stacksize;//˳��ջ�ռ��С
}SqStack;//����˳��ջ�ṹ

//����һ����ջ�������ɹ�������1��ʧ�ܣ�����0
int InitStack(SqStack &S)
{
	S.base = (BiTNode*)malloc(STACKINITSIZE * sizeof(BiTNode));//20Ϊջ�Ĵ�С�����Ը���
	if(!S.base)
		return 0;
	S.top = S.base;
	S.stacksize = STACKINITSIZE;
	return 1;
}

//��ջ����
int Push(SqStack &S,BiTNode e)
{
	if(S.top - S.base >= S.stacksize)
	{
		S.base = (BiTNode*)realloc(S.base,(STACKINITSIZE + INCREASEMENT) * sizeof(BiTNode));
		if(!S.base)
			return 0;
		S.stacksize = 30;
	}
	*S.top = e;
	S.top ++;
	return 1;
}

//��ջ��������ջΪ�գ��򷵻�0��ջ��Ϊ�գ��򷵻�1
int Pop(SqStack &S,BiTNode &e)
{
	if(S.base == S.top)
		return 0;
	S.top --;
	e = *S.top;
	return 1;
}

//�ж�ջ�Ƿ�Ϊ�գ���ջΪ�գ��򷵻�true��ջ��Ϊ�գ��򷵻�false
bool StackEmpty(SqStack S)
{
	if(S.base == S.top)
		return true;
	else
		return false;
}


//�������������
int InOrderTraverse(BiTree T)
{
	if(!T)
		return 0;
	SqStack S;
	int n = InitStack(S);//������ջ
	if(!n)
		return 0;
	BiTree p = T;
	BiTNode e;//�������ڵ㣬���ڴ�Ŵ�ջ��ȡ���Ľڵ�
	while(p || !StackEmpty(S))
	{
		if(p)
		{
			Push(S,*p);
			p = p->lchild;
		}
		else
		{
			Pop(S,e);
			printf("%c ",e.data);
			p = e.rchild;
		}
	}
	printf("\n");
	return 1;
}
void creatnode(bitnode *root,char key,char data)
{
    bitnode *newnode = NULL;
    newnode = (bitnode*)malloc(sizeof(bitnode));
    if(newnode == NULL)
    {
        printf("error!");
        exit(0);
    }
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    newnode->data = data;
    if(key == 'l')
    {
        root->lchild = newnode;
    }
    if(key == 'r')
    {
        root->rchild = newnode;
    }
}
void init(bitnode *root)
{   
    root->data='-';
    creatnode(root,'l','+');
    creatnode(root,'r','/');
    creatnode(root->rchild,'r','f');
    creatnode(root->rchild,'l','e');
    creatnode(root->lchild,'l','a');
    creatnode(root->lchild,'r','*');
    creatnode(root->lchild->rchild,'l','b');
    creatnode(root->lchild->rchild,'r','-');
    creatnode(root->lchild->rchild->rchild,'l','c');
    creatnode(root->lchild->rchild->rchild,'r','d');
}
int main()
{
	bitnode root;
	init(&root);
	InOrderTraverse(&root);
	return 0;
}
