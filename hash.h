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


/* =============================================================================
 * createHashMap
 *
 * Initializes the Hash Map structure
 *
 * @param data: a pointer to an hashMap structure
 * @return: the created hashMap
 * =============================================================================
 */
hash_map_t createHashMap(int size);


/* =============================================================================
 * resetHashMap
 *
 * Sets the values inside of every node to null
 *
 * @param hashMap: a pointer to an hashMap structure
 * @return:
 * =============================================================================
 */
void resetHashMap(hash_map_t hashMap);


/* =============================================================================
 * insert
 *
 * Inserts the given element into the given Hash Map structure
`*
 * @param hashMap: a pointer to an hashMap structure
 * @param key: an int, value used to hash the element
 * @param data: a pointer to the given abstract data type
 * @return:
 * =============================================================================
 */
void hash_insert(hash_map_t hashMap, int key, void * data);


/* =============================================================================
 * getItem
 *
 * Gets the requested item that's attached to the given key
`*
 * @param hashMap: a pointer to an hashMap structure
 * @param key: an int, value used to hash the element
 * @return: a pointer to an item
 * =============================================================================
 */
void * getItem(hash_map_t hashMap, int key);


/* =============================================================================
 * removeItem
 *
 * Removes the requested item that's atached to the given key
`*
 * @param hashMap: a pointer to an hashMap structure
 * @param key: an int, value used to hash the element
 * @return:
 * =============================================================================
 */
void removeItem(hash_map_t hashMap, int key);


/* =============================================================================
 * expand
 *
 * Expands the size of the given Hash Map structure
`*
 * @param hashMap: a pointer to an hashMap structure
 * @return:
 * =============================================================================
 */
hash_map_t expand(hash_map_t hashMap);


/* =============================================================================
 * hash_hasItem
 *
 * Checks if the given Hash Map structure contains the given key
`*
 * @param hashMap: a pointer to an hashMap structure
 * @param key: an int, value used to hash the element
 * @return:
 * =============================================================================
 */
int hash_hasItem(hash_map_t hashMap, int key);


/* =============================================================================
 * hash_isEmpty
 *
 * Checks if the given Hash Map structure is empty
`*
 * @param hashMap: a pointer to an hashMap structure
 * @return: 1 if it's empty, 0 otherwise
 * =============================================================================
 */
int hash_isEmpty(hash_map_t hashMap);


void hash_popItem(hash_map_t hashMap);

void * getTopItem(hash_map_t hashMap);


#endif