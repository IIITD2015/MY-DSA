#include"stdio.h"
#include"stdlib.h"

#define WORD_LENGTH 25
#define NUM_ALPHA 26

typedef struct trieNode{
	char value;
	struct trie *child[NUM_ALPHA];
}node;

typedef struct trie{
	node *root;
}trie;

int initTrieFunc(trie *myTrie){
	
	myTrie=(trie *)malloc(sizeof(trie));
	myTrie=NULL;
	
	return 0;
}

int insertTrieFunc(trie *myTrie, char *word){
	
	printf("Inside insert function, inserting : %s \n", word);
		

	return 0;
}

int main(int argc, char *argv[]){
	
	char *filename=argv[1], line[WORD_LENGTH], *word;
	trie *myTrie;
	
	initTrieFunc(myTrie);

	FILE *file=fopen(filename,"r");
	while(fgets(line, sizeof line, file) != NULL){
		word=line;
		insertTrieFunc(myTrie, word);
	}

	return 0;
}
