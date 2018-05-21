#include<stdio.h>
#include<stddef.h>
#include <time.h>


#define MAX_MEM_SIZE 100000000  //Maximum size of entire memory 2MB
#define MAX_PROCESS 50 //Maximum number of processes
#define MIN_PROCESS_SIZE 10000  //Minimum size of entire memory  10kB
#define MAX_PROCESS_SIZE 2000000 //Maximum size of process 100MB

//using namespace std;



char memory[20000];

struct process_block
{
 	size_t size;
	//int process_number;
 	int free;
 	struct process_block *next; 
};

struct process_block *freeList=(void*)memory;

void initialize();
void split(struct process_block *fitting_slot,size_t size);
void *MyMalloc(size_t noOfBytes);
void merge();
void MyFree(void* ptr);


void initialize()
{
 	freeList->size = 20000-sizeof(struct process_block);
	//Initialize process_block_number;
 	freeList->free = 1;
 	freeList->next = NULL;
}

void split(struct process_block *fitting_slot, size_t size)
{
 	struct process_block *new = (void*)((void*)fitting_slot+size+sizeof(struct process_block));
 	new->size = (fitting_slot->size)-size-sizeof(struct process_block);
 	new->free = 1;
 	new->next = fitting_slot->next;
 	fitting_slot->size = size;
 	fitting_slot->free = 0;
 	fitting_slot->next = new;
}


void *MyMalloc(size_t noOfBytes){
	struct process_block *curr,*prev;
 	void *result;
 	if(!(freeList->size))
	{
  		initialize();
  		printf("1. Memory of size %d Bytes initialized\n", noOfBytes);
 	}
 	curr=freeList;
 	while((((curr->size)<noOfBytes)||((curr->free)==0))&&(curr->next!=NULL))
	{
  		prev = curr;
  		curr = curr->next;
  		printf("2. One block of %d Bytes checked\n", noOfBytes);
	}
 	if((curr->size)==noOfBytes)
	{
  		curr->free = 0;
  		result = (void*)(++curr);
  		printf("3. Exact fitting block of %d Bytes allocated\n", noOfBytes);
  		return result;
 	}
 	else if((curr->size)>(noOfBytes+sizeof(struct process_block)))
	{
  		split(curr,noOfBytes);
  		result = (void*)(++curr);
  		printf("4. Fitting block allocated of %d Bytes with a split\n", noOfBytes);
  		return result;
 	}
 	else
	{
  		result = NULL;
  		printf("5. Sorry. No sufficient memory to allocate %d Bytes available\n", noOfBytes);
  		return result;
 	}
}

void merge()
{
 	struct process_block *curr,*prev;
 	curr = freeList;
 	while((curr->next)!=NULL)
	{
  		if((curr->free) && (curr->next->free))
		{
   			curr->size += (curr->next->size)+sizeof(struct process_block);
   			curr->next = curr->next->next;
  		}
  		prev = curr;
  		curr = curr->next;
 	}
}

void MyFree(void* ptr)
{
 	if(((void*)memory <= ptr) && (ptr <= (void*)(memory+20000)))
	{
  		struct process_block* curr = ptr;
  		--curr;
  		curr->free = 1;
  		merge();
		printf("Memory of size %d released/freed\n", curr->size);
 	}
 	else 
		printf("Please provide a valid pointer allocated by MyMalloc\n");
}

