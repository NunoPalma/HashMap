/* =============================================================================
 *
 * list.h
 *
 * =============================================================================
 */

#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdio.h>
#include <stdlib.h>

#define ERR(str) { fprintf(stderr, "%s\n", str); exit(EXIT_FAILURE); }

typedef struct hash_map {
	int size;
	int elementsCount;
	struct node **nodeElements;
} * hash_map_t;

typedef struct node {
	void * data;
	int key;
} * node_t;

hash_map_t createHashMap(int size);

void resetHashMap(hash_map_t hashMap);

static hash_map_t initializeHashMap(hash_map_t hashMap, int size, int amount);

void insert(hash_map_t hashMap, int key, void * data);

void remove()

hash_map_t expand(hash_map_t hashMap);

#endif