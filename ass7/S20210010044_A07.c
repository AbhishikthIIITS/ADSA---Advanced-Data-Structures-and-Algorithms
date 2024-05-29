#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_OF_ALPHABETS (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

char *String_Set[20];
int Set_index;
typedef struct Trie
{
    struct Trie *children[26];
    int word;
    int index;
} Trie;

Trie *getNode()
{
    Trie *pNode = NULL;

    pNode = (Trie *)malloc(sizeof(Trie));

    if (pNode)
    {
        int i;

        pNode->word = 0;
        pNode->index = -1;
        for (i = 0; i < NUM_OF_ALPHABETS; i++)
        {
            pNode->children[i] = NULL;
        }
    }

    return pNode;
}

Trie *trieCreate()
{
    Trie *root = getNode();
    return root;
}

void Insert_Trie(Trie *root, char *s)
{
    int level;
    int length = strlen(s);
    int index;

    Trie *pCrawl = root;

    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(s[level]);
        if (!pCrawl->children[index])
        {
            pCrawl->children[index] = getNode();
        }

        pCrawl = pCrawl->children[index];
    }

    pCrawl->word = 1;
    pCrawl->index = Set_index;
    String_Set[Set_index] = s;
    Set_index++;
}

int Search_Trie(Trie *obj, char *s)
{
    int level;
    int length = strlen(s);
    int index;
    Trie *pCrawl = obj;

    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(s[level]);

        if (!pCrawl->children[index])
            return 0;

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl->word);
}

int isEmpty(Trie *root)
{
    for (int i = 0; i < NUM_OF_ALPHABETS; i++)
        if (root->children[i])
            return 0;
    return 1;
}

Trie *Delete_Trie(Trie *root, char *key, int depth)
{

    if (!root)
        return NULL;

    if (depth == strlen(key))
    {

        if (root->word == 1)
            root->word = 0;

        if (isEmpty(root))
        {
            free(root);
            root = NULL;
        }

        return root;
    }

    int index = key[depth] - 'a';
    root->children[index] = Delete_Trie(root->children[index], key, depth + 1);

    if (isEmpty(root) && root->word == 0)
    {
        free(root);
        root = NULL;
    }

    return root;
}

void Display_Trie(Trie *root, char str[], int level)
{
    if (root && root->word == 1)
    {
        str[level] = '\0';
        printf("%s\n", str);
    }

    int i;
    for (i = 0; i < NUM_OF_ALPHABETS; i++)
    {
        if (root->children[i] != NULL)
        {
            str[level] = i + 'a';
            Display_Trie(root->children[i], str, level + 1);
        }
    }
}

int main(void)
{
    printf("****************************\n");
    printf("****************************\n\n");
    printf("NAME:- ABHISHIKTH BODA\n");
    printf("COURSE:- ADSA\n");
    printf("ASSIGNMENT NUMBER:- 7\n");
    printf("DATE:- 04-10-2022\n\n");
    printf("****************************\n");
    printf("****************************\n\n");
    Trie *root = trieCreate();
    Set_index = 0;

    Insert_Trie(root, "harry");
    Insert_Trie(root, "ron");
    Insert_Trie(root, "fred");
    Insert_Trie(root, "george");
    Insert_Trie(root, "arrange");
    Insert_Trie(root, "array");
    Insert_Trie(root, "trie");

    printf("\ninitial inorder travesal of strings in the trie before deletion\n\n");
    char s[200];
    Display_Trie(root, s, 0);

    printf("\nif string is present output is 1, if not present 0 \n");
    printf("%d \n", Search_Trie(root, "arrange"));
    printf("%d \n", Search_Trie(root, "graph"));
    Delete_Trie(root, "arrange", 0);
    // we can see the below printf prints 0 after Delete_Trie operation
    printf("%d \n", Search_Trie(root, "arrange"));

    printf("\ninorder traversal of Strings in the trie after deletion\n\n");
    Display_Trie(root, s, 0);
}
