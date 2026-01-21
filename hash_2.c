// To implement linear search for empty spots
// make indexing faster 

#include <stdio.h>
#include <stdint.h>  
#include <string.h>

struct map {
    char* str;
    int index;
};


uint32_t hashString(const char* key, int length) {
    uint32_t hash = 2166136261u;  
    for (int i = 0; i < length; i++) {
        hash ^= (uint8_t)key[i];  
        hash *= 16777619;         
    }
    return hash;
}

int main(){
    // we can take input from user and then change what and how much we are storing accordingly.
    char input[100];
    struct map m[8];
    int hash[8];
    int index[8];

    for (int i = 0; i < 8; i++)
    {
    m[i].str = NULL; 
    m[i].index = 0;
    }

    for (int i = 0; i < 8; i++)
    {
    printf("Enter a word: \n"); 
    scanf(" %s", input);
    hash[i] = hashString(input, strlen(input));
    index[i] = hash[i]%8; 
    while (m[index[i]].str != NULL)
    {

        m[index[i]+1].str = strdup(input);
        m[index[i]+1].index = hash[i];

        if (m[index[i]].str == NULL)
    {
        m[index[i]].str = strdup(input); 
        m[index[i]].index = hash[i];
    }

    }

    }
}