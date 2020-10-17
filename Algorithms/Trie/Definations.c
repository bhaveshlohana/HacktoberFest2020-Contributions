#include "Trie.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
//Function defination
void insertNode(trie *head,char *word){
		trie *currentNode=head;
		while(*word!='\0')
		{
				if(currentNode->Child[*word-CASE]==NULL)
				{
						currentNode->Child[*word-CASE]=create_trie();
						currentNode->Child[*word-CASE]->Parent=currentNode;
				}
				currentNode= currentNode->Child[*word-CASE];
				++word;
		}
		++currentNode->Occurence;
}

trie *create_trie(){
		trie *new_Node=malloc(sizeof *new_Node);
		new_Node->Parent=NULL;
		new_Node->Occurence=0;
		for(int i=0; i<ALPHABAT_SIZE; i++)
				new_Node->Child[i]=NULL;
		return new_Node;
}

trie *search(trie *head,char *word){
		trie *currentNode=head;
		while(*word!='\0')
		{
				if(currentNode->Child[*word-CASE]!=NULL)
						currentNode=currentNode->Child[*word-CASE];
				else return NULL;
				++word;
		}
		return currentNode->Occurence!=0 ? currentNode : NULL;
}

void delete(trie *head,char *word){
		trie *currentNode=search(head,word);
		if(currentNode!=NULL)
		{
				--currentNode->Occurence;
				trie *parent=NULL;
				bool isleaf=true;
				for (int i=0; i<ALPHABAT_SIZE; i++)
				{
						if(currentNode->Child[i]!=NULL)
						{
								isleaf=false;
								break;
						}
				}
				while(currentNode->Parent!=NULL && isleaf && currentNode->Occurence==0)
				{
						parent=currentNode->Parent;
						for (int i=0; i<ALPHABAT_SIZE; i++)
						{
								if(parent->Child[i]==currentNode)
								{
										parent->Child[i]=NULL;
										free (currentNode);
										currentNode=parent;
								}
								else if(parent->Child[i]!=NULL)
								{
										isleaf=false;
										break;
								}
						}
				}
		}
}
void printAllWords(trie* root, char* wordArray, int pos)
{
		if(root == NULL)
				return;

		if(root->Occurence>0)
		{
				printWord(wordArray, pos);
				printf(" %d\n",root->Occurence );
		}
		for(int i=0; i<ALPHABAT_SIZE; i++)
		{
				if(root->Child[i] != NULL)
				{
						wordArray[pos] = i+CASE;
						printAllWords(root->Child[i], wordArray, pos+1);
				}
		}
}
void printWord(char* str, int n)
{
		printf("\n");
		for(int i=0; i<n; i++)
		{
				printf("%c",str[i] );
		}
}
