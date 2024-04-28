// Saves popular dog names in a trie
// https://www.dailypaws.com/dogs-puppies/dog-names/common-dog-names

#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_ALPHABET 26
#define MAXCHAR 20

typedef struct node
{
    bool is_word;
    struct node *children[SIZE_OF_ALPHABET];
} node;

// Function prototypes
bool check(char *word);
bool unload(void);
void unloader(node *current);

// Root of trie
node *root = NULL;

// Buffer to read dog names into
char name[MAXCHAR];

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./trie infile\n");
        return 1;
    }

    // File with names
    FILE *infile = fopen(argv[1], "r");
    if (!infile)
    {
        printf("Error opening file!\n");
        return 1;
    }

    // Allocate root of trie
    root = malloc(sizeof(node));

    if (root == NULL)
    {
        return 1;
    }

    root->is_word = false;
    for (int i = 0; i < SIZE_OF_ALPHABET; i++)
    {
        root->children[i] = NULL;
    }

    // Add words to the trie
    while (fscanf(infile, "%s", name) == 1)
    {
        node *cursor = root;
// Q::Q here we created a root node called cursor, assign to an index int the alphabetical num of name[i]
// we have previously assigned to root children[i] with [i] going from 0 to 25, == Null, cursor = node.
// so in the CURRENT FOR LOOP (i is not the same it s a new loop), we check for each cursor -> children[index] == NULL
// it should be. if it is we create a node *new with 26 children[j] from 0 to 25.
// we assign each children of cursor to new. it meeans we now have: cursor -> children[index of current letter of name] = new
// with new having 26 children from 0 to 25. What the fuck does it do??
// for name[0] = a for instance, we have:
// cursor -> children[0] THEN new -> 26 children[j] from 0 to 25 THEN cursor -> children[0] = new
// SO children[0] is a node with 26 children from 0 to 25.
// THEN cursor == children[0]
// THEN for name[3] = d
// SO the linked list is now: cursor -> children[0] -> children [3] then at the end for last children[] -> is_word = true Q::Q

        for (int i = 0, n = strlen(name); i < n; i++)
        {
            int index = tolower(name[i]) - 'a';
            if (cursor->children[index] == NULL)
            {

                // Make node
                node *new = malloc(sizeof(node));
                new->is_word = false;
                for (int j = 0; j < SIZE_OF_ALPHABET; j++)
                {
                    new->children[j] = NULL;
                }
                cursor->children[index] = new;
            }

            // Go to node which we may have just been made
            cursor = cursor->children[index];
        }

        // if we are at the end of the word, mark it as being a word
        cursor->is_word = true;
    }

    if (check(get_string("Check word: ")))
    {
        printf("Found!\n");
    }
    else
    {
        printf("Not Found.\n");
    }

    if (!unload())
    {
        printf("Problem freeing memory!\n");
        return 1;
    }

    fclose(infile);
}

// TODO: Complete the check function, return true if found, false if not found
bool check(char *word)
{
    node *checkcursor = root;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        int index = tolower(word[i]) - 'a';

        if (checkcursor->children[index] == NULL)
        {
            return false;
        }
        else if (checkcursor ->children[index] != NULL )
        {
            checkcursor = checkcursor->children[index];
        }
    }
    if (checkcursor->is_word == true)
    {
        return true;
    }
    return false;
}

// Unload trie from memory
bool unload(void)
{

    // The recursive function handles all of the freeing
    unloader(root);

    return true;
}

void unloader(node *current)
{

    // Iterate over all the children to see if they point to anything and go
    // there if they do point
    for (int i = 0; i < SIZE_OF_ALPHABET; i++)
    {
        if (current->children[i] != NULL)
        {
            unloader(current->children[i]);
        }
    }

    // After we check all the children point to null we can get rid of the node
    // and return to the previous iteration of this function.
    free(current);
}
