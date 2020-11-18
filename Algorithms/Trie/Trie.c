/* Implementation of trie data_structure in C*/
#include <stdio.h>
#include <stdlib.h>
#include "Trie.h"

int main(int argc, char const *argv[]) {
		trie *head = create_trie();
		char word[10];
		int c;
		while(1)
		{
				printf("1_Insert a node\n");
				printf("2_Search a node\n");
				printf("3_Delete a node\n");
				printf("4_View the trie\n");
				printf("5_Exit\n");
				scanf("%d",&c );
				fflush(stdin);
				system("cls");
				switch  (c)
				{
				case (1):
				{
						gets(word);
						insertNode(head,word);
						break;
				}
				case (2):
				{
						gets(word);
						search(head,word)!=NULL ? printf("%s found\n",word) : printf("Not found\n");
						break;
				}
				case (3):
				{
						gets(word);
						delete(head,word);
						break;
				}
				case (4):
				{
						printAllWords(head,word,0);
						break;
				}
				case (5):
						return 0;
				default:
						printf("Enter valid choice\n");
				}
		}
		return 0;
}
