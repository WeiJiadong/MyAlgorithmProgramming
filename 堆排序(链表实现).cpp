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
		if (t == NULL)		//t为NULL时(首次或者右支连完)，出栈一个新节点 
			t = Q[++front];
		p = (TreeNode *)malloc(sizeof(TreeNode));
		p->left = p->right = NULL;
		p->data = a[i];
		if (t->left)			//左边连了，连右边 
		{
			t->right = p;		//连完右边将t置为NULL 
			t = NULL;
		}
		else
			t->left = p;
		Q[++rear] = p;
	}

	return r;
}

//调整大根堆 
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
			//我的判断代码有冗余，你可以再改改 
				if (t->right){	//是双分支 
					if (t->right->data > t->left->data){	//右比左大 
						if (t->right->data > t->data){	//如果右最大 
							//交换t->data和t->right->data 
							a = t->data;
							t->data = t->right->data;
							t->right->data = a;
							tag = 1;
						}	
						//else 根大不交换 
					}
					else{		//左比右大 
						if (t->left->data > t->data){
							//交换t->data和t->left->data 
							a = t->data;
							t->data = t->left->data;
							t->left->data = a;
							tag = 1;
						}
						//else 根大不换 
					}
				}
				else{			//是单分支 
					if (t->left->data > t->data){
						//交换 t->left->data 和 t->data
						a = t->data;
						t->data = t->left->data;
						t->left->data = a;
						tag = 1;
					} 
					//else 根大不换 
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
		{		//交换右分支和根 
			t->right->data = (t->right->data + r->data) - (r->data = t->right->data);
			t->right = NULL;
			 
		}
		else
		{
				//交换左分支和根 
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
	//调整好的序列在Q[]数组中，所以可以直接输出(用的C++输出形式) 
	printf("\n");
	for (int i = 1; i <= 10; i++){
		printf("%5d", Q[i]->data); 
	}
	getchar();
	return 0;
}
