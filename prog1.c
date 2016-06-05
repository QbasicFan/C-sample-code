


#include<stdlib.h>
#include<stdio.h>

#define recod_size 142 // It works on my computer 


typedef struct bst_node
 {
   char  val[recod_size];
   int key;
   struct bst_node * right, * left;
}BST_NODE;

/*
typedef struct bst_node
{
char key[K_LEN + 1];
off_t offset;
struct bst_node *parent;
}BST_NODE;
*/


void insert(BST_NODE ** node, BST_NODE * value) {
   if(!(*node)) {
      *node = value;
      return;
   }
   
   if(value->key < (*node)->key){
	if ((*node)->left==NULL)   
	   (*node)->left=value;
	else 
	   insert(&(*node)->left, value);
   }else {
	if ((*node)->right==NULL)   
	   (*node)->right=value;
	else 
	   insert(&(*node)->right, value);
    
   }
   
}


// find 

void find(BST_NODE * node , int value)
{
	
   if(node->left) find(node->left , value);
   
   if (node->key == value) printf("\nResult : %s\n",node->val);// change to display char
   
   if(node->right) find(node->right , value);
   
}

// end find

void print_key(BST_NODE * node) {
   if(node->left) print_key(node->left);
   printf("%d\n",node->key);// display key
   if(node->right) print_key(node->right);
}
void print_string(BST_NODE * node) {
   if(node->left) print_string(node->left);
   printf("%s\n",node->val);// display string
   if(node->right) print_string(node->right);
}



void main() {
   BST_NODE * curr, * root;
   int i;

   root = NULL;
   
   // try this
int c,ii;   
char * test ;
char bb[recod_size] , key[5] ;
   FILE *fp;
fp=fopen("records.txt", "r");

//************************************************************************

int mn=0;
  while((c=fgetc(fp))!=EOF){
	 if ((c=fgetc(fp))=='\n'){
		 mn=mn+1;
	 }
 }
 fclose(fp);
  
fp=fopen("records.txt", "r");
	for (c=0;c<=mn;c++){
	   fseek(fp, 1 ,SEEK_CUR);
	fread(bb ,recod_size , 1 , fp) ;
         printf("\n%s",bb);
         for (ii =0;ii<5;ii++){
         key[ii]=bb[ii];
         }
         int yy = atoi(key);
         printf("\n%s=>should be the key!!",key);
        
	
      curr = (BST_NODE *)malloc(sizeof(BST_NODE));
      curr->left = curr->right = NULL;
      curr->key=yy;
   int a;
   for (a=0;a<=recod_size;a++){
      curr->val[a] = bb[a];
   }
  
      insert(&root, curr); 
      
      
      bb[0]='\0';
      key[0]='\0';
	}
 

    fclose(fp);


   // menu 
   int ch, key_search;
    

do {

  printf("\n\t\t\tBinary Search Tree ");
  printf("\n(1) Display (Key list) ... (11) Display (String List)");
  printf("\n(2) Find");
  printf("\n(3) Exit");
  printf("\nEnter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
   print_key(root);
   break;
   case 2:
   printf("\n->Enter a key : ");
   scanf("%d",&key_search);
   find(root , key_search);
   break;
   case 11 :
    print_string(root);  
    break;
    
}


}while(ch!=3);

}
