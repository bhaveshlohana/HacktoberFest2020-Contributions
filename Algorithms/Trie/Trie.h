//constants
#define ALPHABAT_SIZE 26
#define CASE 'a'

//struct defination
typedef struct Trie_t {
		struct Trie_t* Parent;
		struct Trie_t* Child[ALPHABAT_SIZE];
		int Occurence;
}trie;

//Function Prototypes
void insertNode(trie *head,char *word);//insert a node into trie
trie *create_trie();//create a new_Node and intiliaze it
trie *search(trie *head,char *word);//search a word in trie
void delete(trie *head,char *word);//delete a word from trie
void printAllWords(trie* root, char* wordArray, int pos);//to print the trie
void printWord(char* str, int n);//to print a word
