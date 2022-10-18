#include <stdio.h>
#include <string.h>

#include <cairo.h>
#define CACHE_SIZE 16

struct CacheEntryT {
    const char * path;
    cairo_surface_t * picture;
} CACHE[CACHE_SIZE];

int next = 0;

void cache_init() {
    for (int i = 0; i < CACHE_SIZE; ++i) {
        CACHE[i].path = NULL;
    }
}

cairo_surface_t * cache_get(const char * path) {
    for (int i = 0; i < CACHE_SIZE; ++i) {
        printf("Looking at position %d...", i);
        if (strcmp(path, CACHE[i].path) == 0) {
            printf("Found!");
            printf("\n");
            return CACHE[i].picture;
        }
        printf("\n");
    }
    return NULL;
}

void cache_put(const char * path, cairo_surface_t * picture) {
    struct CacheEntryT t = {path, picture};
    printf("Putting in position %d\n", next);
    CACHE[next++] = t;
    next %= CACHE_SIZE;
}