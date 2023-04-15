#include <stdio.h>
#include <stdlib.h>

/* 
code incomplete, couldn't figure out a solution, my apologies
hope i can still get some credit for what is written
*/

// RecordType
struct RecordType
{
	int		id;
	char	name;
	int		order; 
};

// Fill out this structure
struct HashType
{
	struct RecordType record;
	struct HashType *next ;
};

// Compute the hash function
int hash(int x, int hashSize)
{
	return x % hashSize;
}

// parses input file to an integer array
int parseData(char* inputFileName, struct RecordType** ppData)
{
	FILE* inFile = fopen(inputFileName, "r");
	int dataSz = 0;
	int i, n;
	char c;
	struct RecordType *pRecord;
	*ppData = NULL;

	if (inFile)
	{
		fscanf(inFile, "%d\n", &dataSz);
		*ppData = (struct RecordType*) malloc(sizeof(struct RecordType) * dataSz);
		// Implement parse data block
		if (*ppData == NULL)
		{
			printf("Cannot allocate memory\n");
			exit(-1);
		}
		for (i = 0; i < dataSz; ++i)
		{
			pRecord = *ppData + i;
			fscanf(inFile, "%d ", &n);
			pRecord->id = n;
			fscanf(inFile, "%c ", &c);
			pRecord->name = c;
			fscanf(inFile, "%d ", &n);
			pRecord->order = n;
		}

		fclose(inFile);
	}

	return dataSz;
}

// prints the records
void printRecords(struct RecordType pData[], int dataSz)
{
	int i;
	printf("\nRecords:\n");
	for (i = 0; i < dataSz; ++i)
	{
		printf("\t%d %c %d\n", pData[i].id, pData[i].name, pData[i].order);
	}
	printf("\n\n");
}

// display records in the hash structure
// skip the indices which are free
// the output will be in the format:
// index x -> id, name, order -> id, name, order ....
void displayRecordsInHash(struct HashType *pHashArray, int hashSz)
{
	int i;

	for (i=0;i<hashSz;++i)
	{
		// if index is occupied with any records, print all
		struct HashType* pHashItem = &pHashArray[i];

		if (pHashItem->record.id != -1)
		{

			printf("index %d -> ", i);

			while (pHashItem != NULL)
			{

				printf("%d %c %d -> ", pHashItem->record.id, pHashItem->record.name, pHashItem->record.order);
				pHashItem = pHashItem->next;

			}
			printf("\n");

		}
	}
}

int main(void)
{
	struct RecordType *pRecords;
	int recordSz = 0;
	int index;

	recordSz = parseData("input.txt", &pRecords);
	printRecords(pRecords, recordSz);

	struct HashType *pHashArray;
	
	// Your hash implementation
	for(int i = 0; i < recordSz; i++)
	{
		index = hash(pRecords[i].id, recordSz); //take id input, mod by size, and get index


	}

	displayRecordsInHash(pHashArray, recordSz);
	
}
