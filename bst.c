/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct structure {
	int val;
	struct structure *left,*right;
};
struct structure* start = NULL;

int find (struct structure *root) {
	struct structure *ptr = root;
	if (ptr->right == NULL) {
		int val = ptr->val;
		free(ptr);
		return val;
	} else {
		return find(ptr->right);
	}
}
void delete (int val) {     
	if (start==NULL) {
		printf("absent\n");
		return;
	}
	struct structure *ptr = start;
	struct structure *parent = NULL;
	while (ptr!=NULL) {
		if (ptr->val==val) {
			if (ptr->right == NULL && ptr->left == NULL) {
				if (parent == NULL) {
					start = NULL;
						printf("deleted\n");     
					free(ptr);
					return;
				} else {
					if (val >= parent->val) {
					    	parent->right = NULL;
						free(ptr);
						printf("deleted\n");
						return;}
				     else {parent->left = NULL;
						free(ptr);
						printf("deleted\n");
						return;
					}
				}
			}
			if (ptr->right !=NULL && ptr->left == NULL) {
				if (parent == NULL) {
					start = ptr->right;
					free(ptr);
					printf("deleted\n");
					return;
				} else {
					if (parent->val > val) {
						parent->left = ptr->right;
					}else {
						parent->right = ptr->right;
					}
					free(ptr);
					printf("deleted\n");
					return;
				}
			}
			if (ptr->left != NULL && ptr->right == NULL) {   
				if (parent == NULL) {
					start = ptr->left;
					free (ptr);
					printf("deleted\n");
					return;
				} else {
					if (parent->val > val) {
						parent->left = ptr->left;
					}else {
						parent->right = ptr->left;
					}
					free(ptr);
					printf("deleted\n");
					return;
				}
			}
			if(ptr->right!=NULL && ptr->left!= NULL) {
				int replacement = find(ptr->left);
				ptr->val = replacement;
				printf("deleted\n");
				return;
			}
		}else if (ptr->val>val) {
			parent = ptr;
			ptr = ptr->left;
		}else {
			parent = ptr;
			ptr = ptr->right;
		}
	}
	printf("absent\n");
	return;
}
void print (struct structure* parent) {

	if (parent == NULL) {
		return;
	}
	printf("(");
	print(parent->left);
	printf("%d", parent->val);
	print(parent->right);
	printf(")");		
	return;
}
void search (int val) {
	if (start == NULL) {
		printf("absent\n");
		return;}
	struct structure * ptr = start;
	while (ptr!=NULL) {
		if (ptr->val == val) {
			printf("present\n");
			return;
		} else if (ptr->val < val) {	
			ptr = ptr->right;
		} else {
			ptr = ptr->left;
		}
	}
	if (ptr==NULL) {
		printf("absent\n");
	}
	return;
}
void insert (int val) {
	if (start==NULL) {
		start = (struct structure *)malloc(sizeof(struct structure));
		start->right = NULL;
		start->left = NULL;
		start->val = val;
		printf("inserted\n");
		return;
	} 
	struct structure * ptr = start;
	struct structure * parent = NULL;
	

	while (ptr!=NULL) {
		if (ptr->val == val) {
			printf("not inserted\n"); return;      
		} else if (val > ptr->val) {
			parent = ptr;
			ptr = ptr->right;
		} else {
			parent = ptr;
			ptr = ptr->left;
		}
	}
	if (ptr==NULL) {
		struct structure* new = (struct structure *)malloc(sizeof(struct structure));
		new->right = NULL;
		new->left = NULL;
		new->val = val;

		if (val < parent->val) {
			parent->left = new;
		} else {
			parent->right = new;
		}
		printf("inserted\n");
	}
		return;
}

void scanner(){
     char mode;
    int number;
    char fgetter[1000];		
   
  while(fgets(fgetter, 1000, stdin)) {		
      sscanf(fgetter," %c %d", &mode, &number);
    
  //  if (scanthingy == EOF){ exit(0);}	     
  
    if(mode == 'i'){
        insert(number);
    } else if(mode == 's'){
        search(number);
    } else if (mode == 'd'){
        delete(number);
    } else {
        print(start);
        printf("\n");
    }
  }
if(feof(stdin))
{
   exit(0);
}
    return scanner();
}
int main (int argc, char** argv) {
    
    scanner();
   
    
	return 0;
}
