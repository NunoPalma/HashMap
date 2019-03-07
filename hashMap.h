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
 * hash
 *
 * Hashes a certain element considering the given key that represents
 * 													that same element
`*
 * @param hashMap: a pointer to an hashMap structure
 * @param key: an int, value used to hash the element
 * @return: hash value that will be used as the index for the Hash Map
 * =============================================================================
 */
static int hash(hash_map_t hashMap, int key);


/* =============================================================================
 * initializeHashMap
 *
 * Initializes the nodes' structure
 *
 * @param hashMap: a pointer to an hashMap structure
 * @param size: the size of the nodes
 * @param amount: amount of elements in the nodes. Used for internal purposes
 * @return: the created hashMap
 * =============================================================================
 */
static hash_map_t initializeHashMap(hash_map_t hashMap, int size, int amount);


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
void insert(hash_map_t hashMap, int key, void * data);


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
 * getNode
 *
 * Gets the requested node, containing a certain item, 
 * 					 that's attached to the given key
`*
 * @param hashMap: a pointer to an hashMap structure
 * @param key: an int, value used to hash the element
 * @return: a pointer to a node
 * =============================================================================
 */
static void * getNode(hash_map_t hashMap, int key);


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
 * hasItem
 *
 * Checks if the given Hash Map structure contains the given key
`*
 * @param hashMap: a pointer to an hashMap structure
 * @param key: an int, value used to hash the element
 * @return:
 * =============================================================================
 */
int hasItem(hash_map_t hashMap, int key);


/* =============================================================================
 * freeNode
 *
 * Frees the memory used by the given node
 * Makes the pointer in the Hash Map strucure containing that node point to NULL
`*
 * @param hashMap: a pointer to an hashMap structure
 * @param key: an int, value used to hash the element
 * @return:
 * =============================================================================
 */
static void freeNode(hash_map_t hashMap, node_t node);

#endif