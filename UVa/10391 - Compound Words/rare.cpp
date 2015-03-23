/*
 * UVa  10391 - Compound Words
 * 哈希表
 * Time: 0.020s (UVa)
 * Author: D_Double
 */
#include<iostream>   
#include<cstdio>   
#include<cstring>
#include <time.h>
#define MAXN 120003 
using namespace std;
typedef char Word[30];


Word word[MAXN];
const int HashSize = MAXN;
int N, head[HashSize], myNext[HashSize];

inline void init_lookup_table() {
    N = 1;
    memset(head, 0, sizeof (head));
}

inline int myHash(char *str) { // 字符串哈希函数 
    int seed = 131;
    int hash = 0;
    while (*str)
        hash = hash * seed + (*str++);
    return (hash & 0x7FFFFFFF) % HashSize;
}

int add_hash(int s) {
    int h = myHash(word[s]);
    //printf("Hash for %s: %d\n", word[s], h);
    int u = head[h];
    while (u) u = myNext[u];
    myNext[s] = head[h];
    head[h] = s;
    return 1;
}

int search(char *s) {
    int h = myHash(s);
    int u = head[h];
    //printf("SearhHash for %s: %d; HEAD: %d\n", s, h, u);
    while (u) {
        //printf(">>>COMP for %s: %s; HEAD: %d\n", word[u], s);
        if (strcmp(word[u], s) == 0) return u;
        u = myNext[u];
    }
    return 0;
}

int main() {
    clock_t tStart = clock();
    
    Word str;
    N = 1;
    
    init_lookup_table();
    while (gets(word[N])) {
        add_hash(N);
        ++N;
    }
    // 查询 
    for (int i = 1; i < N; ++i)
        if (word[i][1]) {
            for (int j = 0; j < strlen(word[i]) - 1; ++j) {
                strcpy(str, word[i]);
                str[j + 1] = '\0';
                if (search(str) && search(word[i] + j + 1)) {
                    puts(word[i]);
                    break;
                }
            }
        }
    printf("Time taken: %.2fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}

