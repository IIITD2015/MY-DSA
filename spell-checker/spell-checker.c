#include"stdio.h"
#include"stdlib.h"
#include"string.h"

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

int findCharacIndex(char charac){
	
	int characIndex= (int)charac - 'a'; 
	printf("Curr charac is: %c and characIndex is: %d\n", charac, characIndex);	

	return characIndex;
}

int insertTrieFunc(trie *myTrie, char *word){
	
	printf("Inside insert function, inserting : %s \n", word);
	printf("length of the word is %lu\n", strlen(word)-1);	
	int word_len=strlen(word)-1, index=0, characIndex;
	char currCharac;

	while(word_len--){
		printf("%c\t",word[index]);
		currCharac=word[index];
	
		characIndex=findCharacIndex(currCharac);
		printf("Insert it on %d index\n", characIndex);

		index++;
	}	
	printf("\n");

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
