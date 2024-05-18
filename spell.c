#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define DICTIONARY_SIZE 1000

// Structure for a key-value pair
struct KeyValuePair {
    char key[50];
    struct KeyValuePair* next;
};

// Structure for the hash table
struct HashTable {
    int size;
    struct KeyValuePair** table;
};

// Hash function for strings (djb2 algorithm)
unsigned long hashFunction(const char* str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++) != '\0') {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return hash;
}

// Function to create a new key-value pair
struct KeyValuePair* createKeyValuePair(const char* key) {
    struct KeyValuePair* newPair = (struct KeyValuePair*)malloc(sizeof(struct KeyValuePair));
    if (newPair != NULL) {
        strcpy(newPair->key, key);
        newPair->next = NULL;
    }
    return newPair;
}

// Function to create a new hash table
struct HashTable* createHashTable(int size) {
    struct HashTable* newTable = (struct HashTable*)malloc(sizeof(struct HashTable));
    if (newTable != NULL) {
        newTable->size = size;
        newTable->table = (struct KeyValuePair*)calloc(size, sizeof(struct KeyValuePair));
    }
    return newTable;
}

// Function to insert a word into the dictionary hash table
void insertWord(struct HashTable* dictionary, const char* word) {
    unsigned long index = hashFunction(word) % dictionary->size;

    // Create a new key-value pair
    struct KeyValuePair* newPair = createKeyValuePair(word);

    // Insert the new pair at the beginning of the linked list
    newPair->next = dictionary->table[index];
    dictionary->table[index] = newPair;
}

// Function to check if a word is in the dictionary
int isWordInDictionary(struct HashTable* dictionary, const char* word) {
    unsigned long index = hashFunction(word) % dictionary->size;
    struct KeyValuePair* current = dictionary->table[index];

    // Traverse the linked list at the index
    while (current != NULL) {
        if (strcmp(current->key, word) == 0) {
            return 1; // Word found in the dictionary
        }
        current = current->next;
    }
    return 0; // Word not found in the dictionary
}

// Function to free the memory allocated for the hash table
void freeHashTable(struct HashTable* dictionary) {
    for (int i = 0; i < dictionary->size; i++) {
        struct KeyValuePair* current = dictionary->table[i];
        while (current != NULL) {
            struct KeyValuePair* temp = current;
            current = current->next;
            free(temp);
        }
    }

    free(dictionary->table);
    free(dictionary);
}

int main() {
    // Create a hash table to store the dictionary
    struct HashTable* dictionary = createHashTable(DICTIONARY_SIZE);

    // Load dictionary words into the hash table
    insertWord(dictionary, "red");
    insertWord(dictionary, "green");
    insertWord(dictionary, "blue");
    
    // Add more words as needed

    // Check the spelling of input words
    char inputWord[50];
    printf("Input a word to check the spelling: ");
    scanf("%s", inputWord);

    // Convert the input word to lowercase for case-insensitive checking
    for (int i = 0; i < strlen(inputWord); i++) {
        inputWord[i] = tolower(inputWord[i]);
    }

    // Check if the input word is in the dictionary
    if (isWordInDictionary(dictionary, inputWord)) {
        printf("Spelling is correct!\n");
    } else {
        printf("Spelling is incorrect!\n");
    }

    // Free allocated memory
    freeHashTable(dictionary);

}
