#include "hashMap.h"

struct data_t {
	int num;
	int key;
};

typedef struct data_t data;

int main()
{
	hash_map_t hashMap;
	int i;
	hashMap = createHashMap(5);

	data newData1;
	newData1.num = 5;
	newData1.key = 30;

	data newData2;
	newData2.num = 6;
	newData2.key = 31;

	data newData3;
	newData3.num = 10;
	newData3.key = 35;

	data newData4;
	newData4.num = 19;
	newData4.key = 35;

	data newData5;
	newData5.num = 23;
	newData5.key = 37;

	insert(hashMap, newData1.key, &newData1);
	insert(hashMap, newData2.key, &newData2);
	insert(hashMap, newData3.key, &newData3);
	insert(hashMap, newData4.key, &newData4);
	insert(hashMap, newData5.key, &newData5);

	for (i = 0; i < hashMap->size; i++) {
		if (hashMap->nodeElements[i] == NULL)
			printf("NULL\n");
		else {
			data *d = (data*)hashMap->nodeElements[i]->data;
			printf("%d\n", d->num);
		}
	}
	

}