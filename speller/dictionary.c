// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
long word_count = 0;
// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    if ((table[hash(word)]) == NULL)
    {
        return false;
    }
    node *checkcursor = table[hash(word)];
    while (checkcursor != NULL)
    {
        if (strcasecmp(word, checkcursor->word) == 0)
        {
            return true;
        }
        else
        {
            checkcursor = checkcursor->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");

    if (source == NULL)
    {
        printf("Error opening dictionnary file!\n");
        return false;
    }

    char word[LENGTH + 1];

    // Read each word in the file
    while (fscanf(source, "%s", word) == 1)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(source);
            return false;
        }
        new_node->next = NULL;
        strcpy(new_node->word, word);

        if (table[hash(word)] == NULL)
        {
            table[hash(word)] = new_node;
        }
        // Q::Q if table already exists with a word in it such as banana
        // Then we will assign the new_node -> next value to the banana node
        // our new word blumpkin will be assigned the table hash position 0,
        // temporary occupy the new_node position and banana will be in new_node next.
        // then bubbley will come in as new_node, new_node next will be blumpkin

        else
        {
            new_node->next = table[hash(word)];
            table[hash(word)] = new_node;
        }
        word_count++;
    }

    // Close the dictionary file
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
long size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{

    for (int i = 0; i < N; i++)
    {
        node *unload_cursor = table[i];
        while (unload_cursor != NULL)
        {
            node *temp = unload_cursor;
            unload_cursor = unload_cursor->next;
            free(temp);
        }
        table[i] = NULL;
    }
    return true;
}
