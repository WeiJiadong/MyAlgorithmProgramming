#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node * right;
}TreeNode;

TreeNode **Q = (TreeNode **)malloc(11 * sizeof(TreeNode *));
int front=0, rear=0;
 

TreeNode* creatTree( int a[], int n)
{
	TreeNode *r, *t, *p;
	t = NULL;
	
	r = (TreeNode *)malloc(sizeof(TreeNode));
	r->left = r->right = NULL;
	r->data = a[0];
	
	Q[++rear] = r;
	for (int i = 1; i < n; i++)
	{
		if (t == NULL)		//tΪNULLʱ(�״λ�����֧����)����ջһ���½ڵ� 
			t = Q[++front];
		p = (TreeNode *)malloc(sizeof(TreeNode));
		p->left = p->right = NULL;
		p->data = a[i];
		if (t->left)			//������ˣ����ұ� 
		{
			t->right = p;		//�����ұ߽�t��ΪNULL 
			t = NULL;
		}
		else
			t->left = p;
		Q[++rear] = p;
	}

	return r;
}

//��������� 
void PHeap(TreeNode *r)
{
	TreeNode * t;
	int a;
	int k = front;
	int tag = 0;

	while (1)
	{
		k = front;
		tag = 0;
		while (k > 0)
		{
			t = Q[k--];
			//�ҵ��жϴ��������࣬������ٸĸ� 
				if (t->right){	//��˫��֧ 
					if (t->right->data > t->left->data){	//�ұ���� 
						if (t->right->data > t->data){	//�������� 
							//����t->data��t->right->data 
							a = t->data;
							t->data = t->right->data;
							t->right->data = a;
							tag = 1;
						}	
						//else ���󲻽��� 
					}
					else{		//����Ҵ� 
						if (t->left->data > t->data){
							//����t->data��t->left->data 
							a = t->data;
							t->data = t->left->data;
							t->left->data = a;
							tag = 1;
						}
						//else ���󲻻� 
					}
				}
				else{			//�ǵ���֧ 
					if (t->left->data > t->data){
						//���� t->left->data �� t->data
						a = t->data;
						t->data = t->left->data;
						t->left->data = a;
						tag = 1;
					} 
					//else ���󲻻� 
				} 
		}
		if (!tag)
			break;
	}
}

void Sort(TreeNode * r)
{

	TreeNode * t;
	while (rear>1) 
	{
		int a;
		PHeap(r);
		t = Q[front];
		if (t->right)
		{		//�����ҷ�֧�͸� 
			t->right->data = (t->right->data + r->data) - (r->data = t->right->data);
			t->right = NULL;
			 
		}
		else
		{
				//�������֧�͸� 
			t->left->data = (t->left->data + r->data) - (r->data = t->left->data);
			t->left = NULL;
			front--;
		}
		rear--;
		
	}
}

int main(void)
{
	int d[10];
	for (int j; j < 10; j++){
		scanf("%d", d + j);
	}
	TreeNode *root = creatTree(d, 10);
	Sort(root);
	//�����õ�������Q[]�����У����Կ���ֱ�����(�õ�C++�����ʽ) 
	printf("\n");
	for (int i = 1; i <= 10; i++){
		printf("%5d", Q[i]->data); 
	}
	getchar();
	return 0;
}
