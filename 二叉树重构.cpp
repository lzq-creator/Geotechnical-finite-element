#include<stdio.h>
#pragma warning(disable:4996)
#define BinNodePosi BinNode<T>* //节点位置
template <typename T> struct BinNode {
	T data;                           //数值
	BinNodePosi parent;          //父节点
	BinNodePosi lc;
	BinNodePosi rc;//左、右孩子
};
template <typename T>
void printree(BinNodePosi root)
{
	if (root == NULL) return;
	printree(root->lc);
	printf("%d ", root->data);
	printree(root->rc);
}
int find1(int j,int b[],int a)
{
	while(1)
	{
		if (b[j] == a) return j;
		j++;
	}
}
int find2(int j, int b[], int a)
{
	while (1)
	{
		if (b[j] == a) return j;
		j--;
	}
}
template <typename T>
void recon(BinNode<T>* p, int pre0, int pre1, int post0, int post1,int pre[],int last[])
{
	if (post1 - post0 == 0||pre1-pre0==0) return;
	int prel0 = pre0 + 1;
	int prel1 = find1(pre0,pre, last[post1 - 1]) - 1;
	int postl0 = post0;
	int postl1 = find2(post1,last, pre[pre0 + 1]);
	int prer0 = prel1 + 1;
	int prer1 = pre1;
	int postr0 = postl1 + 1;
	int postr1 = post1 - 1;
	if (prel1-prel0 >= 0)
	{
		BinNodePosi pl = new BinNode<int>{ pre[prel0],p };
		p->lc = pl;
		recon(pl, prel0, prel1, postl0, postl1,pre,last);
	}
	if (prer1 - prer0 >= 0)
	{
		BinNodePosi pr = new BinNode<int>{ last[postr1],p };
		p->rc = pr;
		recon(pr, prer0, prer1, postr0, postr1,pre,last);
	}
}
int main() 
{
	int n, i,s;
	int *pre,*last;
	scanf("%d", &n);
	pre = new int[n];
	last = new int[n];
	for (i = 0; i < n; i++)
	{
		scanf("%d", &pre[i]);
	}
	//for (i = 0; i < n; i++)
	//{
		//printf("%d ", pre[i]);
	//}
	for (i = 0; i < n; i++)
	{
		scanf("%d", &last[i]);
	}
	BinNode<int>* root = new BinNode<int>{ pre[0] };
	recon(root, 0, n-1, 0, n-1,pre,last);
	printree(root);
	return 0;
}

