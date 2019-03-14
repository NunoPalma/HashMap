/* =============================================================================
 *
 * hashTable.c
 *
 * =============================================================================
 */

#include "hash.h"


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
static hash_map_t initializeHashMap(hash_map_t hashMap, int size, int amount)
{
	hashMap->size = size;
	hashMap->elementsCount = amount;
	hashMap->nodeElements = malloc(sizeof(struct node)*size);

	resetHashMap(hashMap);

	return hashMap;

}


/* =============================================================================
 * createHashMap
 *
 * Initializes the Hash Map structure
 *
 * @param data: a pointer to an hashMap structure
 * @return: the created hashMap
 * =============================================================================
 */
hash_map_t createHashMap(int size)
{
	hash_map_t hashMap = malloc(sizeof(struct hash_map));;
	hashMap = initializeHashMap(hashMap, size, 0);

	return hashMap;
}


/* =============================================================================
 * resetHashMap
 *
 * Sets the values inside of every node to null
 *
 * @param hashMap: a pointer to an hashMap structure
 * @return:
 * =============================================================================
 */
void resetHashMap(hash_map_t hashMap)
{
	int i;

	for (i = 0; i < hashMap->size; i++)
		hashMap->nodeElements[i] = NULL;
}

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
static int hash(hash_map_t hashMap, int key)
{
	return key%hashMap->size;
}


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
void hash_insert(hash_map_t hashMap, int key, void * data)
{

	int index = hash(hashMap, key);

	while(hashMap->nodeElements[index] != NULL)
		index = (index + 1) % hashMap->size;

	node_t newNode = malloc(sizeof(struct node));
	newNode->data = data;
	newNode->key = key;
	hashMap->nodeElements[index] = newNode;
	hashMap->elementsCount++;

	if (hashMap->elementsCount > hashMap->size / 2) 
		hashMap = expand(hashMap);

}


/* =============================================================================
 * expand
 *
 * Expands the size of the given Hash Map structure
`*
 * @param hashMap: a pointer to an hashMap structure
 * @return:
 * =============================================================================
 */
hash_map_t expand(hash_map_t hashMap)
{
	int i;

	hash_map_t newHashMap = malloc(sizeof(struct hash_map));
	newHashMap = initializeHashMap(newHashMap, hashMap->size * 2, 0);
	hashMap->size = newHashMap->size;

	for (i = 0; i < hashMap->size; i++)
		if (hashMap->nodeElements[i] != NULL)
			hash_insert(newHashMap, hashMap->nodeElements[i]->key, hashMap->nodeElements[i]);

	return newHashMap;
}

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
void * getItem(hash_map_t hashMap, int key)
{
	int index = hash(hashMap, key);

	while(hashMap->nodeElements[index] != NULL) {
		if (hashMap->nodeElements[index]->key == key)
			return hashMap->nodeElements[index]->data;
		else
			index = (index + index) % hashMap->size;
	}

	return NULL;
}

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
static void * getNode(hash_map_t hashMap, int key)
{
	int index = hash(hashMap, key);

	while(hashMap->nodeElements[index] != NULL) {
		if (hashMap->nodeElements[index]->key == key)
			return hashMap->nodeElements[index];
		else
			index = (index + index) % hashMap->size;
	}

	return NULL;
}


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
static void freeNode(hash_map_t hashMap, node_t node)
{
	int index = hash(hashMap, node->key);

	while(hashMap->nodeElements[index] != NULL) {
		if (hashMap->nodeElements[index]->key == node->key) {
			free(hashMap->nodeElements[index]);
			hashMap->nodeElements[index] = NULL;
			return;
		}
		else
			index = (index + index) % hashMap->size;
	}
}


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
void removeItem(hash_map_t hashMap, int key)
{
	node_t item = (node_t) getNode(hashMap, key);

	if (!item) {
		ERR("The requested item with the corresponding key doesn't exist.\n");
		return;
	}

	freeNode(hashMap, item);
}

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
int hash_hasItem(hash_map_t hashMap, int key)
{
	return (getItem(hashMap, key) != NULL) ? 1 : 0;
}

int hash_isEmpty(hash_map_t hashMap)
{
	for (int i = 0; i < hashMap->size; i++) {
		if (hashMap->nodeElements[i] != NULL)
			return 0;
	}

	return 1;
}

void hash_popItem(hash_map_t hashMap)
{
	if (!hash_isEmpty(hashMap))
		for (int i = 0; i < hashMap->size; i++)
			if (hashMap->nodeElements[i] != NULL) {
				removeItem(hashMap, hashMap->nodeElements[i]->key);
				return;
			}	
}

void * getTopItem(hash_map_t hashMap)
{
	if (!hash_isEmpty(hashMap))
		for (int i = 0; i < hashMap->size; i++)
			if (hashMap->nodeElements[i] != NULL)
				return getItem(hashMap, hashMap->nodeElements[i]->key);
}


