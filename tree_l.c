#include<stdio.h>
#include<stdlib.h>
typedef struct TREE
{
	int data;
	struct TREE*left;
	struct TREE*right;
}TREE;
int numberOfLeaf(TREE* root)
{
	if(root==NULL)
		return 0;
	else
	{
		if(root->left==NULL&&root->right==NULL)
			return 1;	

		int xl= numberOfLeaf(root->left);
		int xr= numberOfLeaf(root->right);

		return (xl+xr);
	}
}
int main()
{
	TREE root[]={
							{'x',root+1,root+4},
							{'y',root+2,root+3},
							{'z',NULL,NULL},
							{'a',NULL,NULL},
							{'b',root+5,root+6},
							{'c',NULL,NULL},
							{'d',NULL,NULL}	};

	printf("%d",numberOfLeaf(root));
	return 0;
}
