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
    char input[100];
    struct map m[8];
    int hash[8];
    int index[8];

    for (int i = 0; i < 8; i++)
    {
    m[i].str = NULL; 
    }

    for (int i = 0; i < 8; i++)
    {
    printf("Enter a word: \n"); 
    scanf(" %s", input);
    hash[i] = hashString(input, strlen(input));
    index[i] = hash[i]%8;
    m[index[i]].str = strdup(input); // to create a copy of the string and then store it.
    // also we can use strcpy(m[index[i]], input) 
    // m[index[i]] = first you go to the "i'th" position in the index array and then the index'th position in the
    // m struct and then assign respective values
    m[index[i]].index = hash[i];
    }
    
    // int len = strlen(m.str);
    // int hash = hashString(m.str, len);
    // m.index = hash % 8;
    return 0;
}