#include<stdio.h>
#include<stdlib.h>
typedef struct TREE
{
	int data;
	struct TREE*left;
	struct TREE*right;
}TREE;
int number_leaf(TREE*root);
int main()
{
	int data,depth;
	TREE*tree=NULL;
	TREE*InsertTree(int data,TREE*p);
	TREE*PrintTreeTriangle(TREE*tree,int level);

	while(1)
	{
		printf("\nKey to insert|");
		scanf("%d", &data);
		if (data==0)
			  break;
		tree =InsertTree(data,tree);
		printf("\n Tree Display;\n");
		PrintTreeTriangle(tree,1);
		depth=0;
	}
printf("%d",number_leaf(tree));
	return(0);
}
TREE *InsertTree(int data,TREE *p) {
	if(!p) {
		p=(TREE*)malloc(sizeof(TREE));
		p->data=data;
		p->left=NULL;
		p->right=NULL;
		return(p);
	}
	if(data < p->data)
		p->left=InsertTree(data,p->left); else
		if(data > p->data)
		p->right=InsertTree(data,p->right);
	return(p);
}
int number_leaf(TREE*root)
{
	if(root==NULL)
		return 0;
	else
	{
		if(root->left==NULL&&root->right==NULL)
			return 1;	

		int xl= number_leaf(root->left);
		int xr= number_leaf(root->right);

		return (xl+xr);
	}
}
TREE *PrintTreeTriangle(TREE *tree, int level) {
	int i;
	if(tree) {
		PrintTreeTriangle(tree->right,level+1);
		printf("\n\t");
		for (i=0;i<level;i++)
				printf("    ");
		printf("%d",tree->data);
		PrintTreeTriangle(tree->left,level+1);
	}
	return(NULL);
}
