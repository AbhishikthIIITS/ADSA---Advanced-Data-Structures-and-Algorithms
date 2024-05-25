
#include <stdio.h>
#include <stdlib.h>

struct AdjListNode {
	int dest;
	struct AdjListNode* next;
};

struct AdjList {
	struct AdjListNode* head;
};


struct Graph {
	int V;
	struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest)
{
	struct AdjListNode* newNode	= (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}


struct Graph* createGraph(int V)
{
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->V = V;


	graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

	
	int i;
	for (i = 0; i < V; ++i){
		graph->array[i].head = NULL;
    }
	return graph;
}


void addEdge(struct Graph* graph, int src, int dest)
{
	struct AdjListNode* check = NULL;
	struct AdjListNode* newNode = newAdjListNode(dest);

	if (graph->array[src].head == NULL) {
		newNode->next = graph->array[src].head;
		graph->array[src].head = newNode;
	}
	else {

		check = graph->array[src].head;
		while (check->next != NULL) {
			check = check->next;
		}
		check->next = newNode;
	}

	newNode = newAdjListNode(src);
	if (graph->array[dest].head == NULL) {
		newNode->next = graph->array[dest].head;
		graph->array[dest].head = newNode;
	}
	else {
		check = graph->array[dest].head;
		while (check->next != NULL) {
			check = check->next;
		}
		check->next = newNode;
	}

}

void printGraph(struct Graph* graph)
{
	int v;
	for (v = 0; v < graph->V; ++v) {
		struct AdjListNode* pCrawl = graph->array[v].head;
		printf("\n Adjacency list of vertex %d\n head ", v);
		while (pCrawl) {
			printf("-> %d", pCrawl->dest);
			pCrawl = pCrawl->next;
		}
		printf("\n");
	}
}

void q3()
{
	int V = 5;
	struct Graph* graph = createGraph(V);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);

	printGraph(graph);

}

#define size 5

void adj_init(int adjarr[][size]){

    for (int i = 1; i <= size; i++){

        for (int j = 1; j <= size; j++){

            adjarr[i][j] = 0;
        
        }
    
    }
}

void edge(int arr[][size], int src, int dest){

    arr[src][dest] = 1;
    arr[dest][src] = 1;
}

void print_adjmatrix(int arr[][size]){

    for (int i = 1; i <= size; i++){

        for (int j = 1; j <= size; j++){

            printf("%d ", arr[i][j]);
        
        }
        
        printf("\n");
    
    }

}



void connection_check(int arr[][size]){

    int c;
    
    for (int i = 1; i <= size; i++){

        c = 0;
        
        for (int j = 1; j <= size; j++){

            if (arr[i][j] == 0){
             
                c++;
            
            }
        
        }
    
    }
    
    if (c == size){

        printf("Not connected\n");
    
    }
    
    else{
        
        printf("connected\n");
    
    }

}

void q2(){

    int arr1[size][size], arr2[size][size];
    
    adj_init(arr1);
    printf("Graph 1\n");
    edge(arr1, 1, 2);
    edge(arr1, 1, 3);
    edge(arr1, 1, 4);
    edge(arr1, 2, 4);
    edge(arr1, 3, 4);
    
    print_adjmatrix(arr1);
    
    connection_check(arr1);

    adj_init(arr2);
    
    printf("Graph 2\n");
    edge(arr2, 1, 2);
    edge(arr2, 1, 3);
    edge(arr2, 1, 4);
    edge(arr2, 2, 4);
    edge(arr2, 2, 5);
    edge(arr2, 3, 4);
    edge(arr2, 4, 5);
    
    print_adjmatrix(arr2);
    
    connection_check(arr2);

}

#define Nsize 200;
int n=5;

int * ptr=NULL;
int toGetPositionInHashTable(int key,int sizeOfTable)
{
    return key%sizeOfTable;
}

void addelemntintohastable(int key,int size1)
{
    int position=toGetPositionInHashTable(key,size1);
    for(int i=0;i<size1;i++)
    {
        if(*(ptr+(position+i)%size1)==0)
        {
           *(ptr+((position+i)%size1))=key;
           break;
        }
    }

}

void printhashtable(int size1)
{
    printf("\n");
    for(int i=0;i<size1;i++)
    {
        if(*(ptr+i)!=0)
        {
            printf("%d ", *(ptr+i));
        }
        else
        {
            printf("__ ");
        }
    }
}

void question1(int*arr,int size1)
{
    int i=1,k=5;
    ptr=(int *)malloc(sizeof(int)*5);
    int pos=toGetPositionInHashTable(*arr,k);
    *(ptr+pos)=*arr;

    while(i<size1)
    {
        while((i+1)<=(0.8)*k && i<size1)
        {
            ptr=(int *)realloc(ptr,sizeof(int)*k);
            printhashtable(k);
            addelemntintohastable(*(arr+i),k);
            i++;

        }
        if(i<size1)
        k=k*2;
       
    }

    printhashtable(k);
}

void q1()
{
    int arr[]={5,4,6,12,3,10,9};
    question1(arr,sizeof(arr)/sizeof(arr[0]));
}

int main()
{
    printf("****************************\n");
    printf("NAME:- ABHISHIKTH BODA\nCOURSE:- ADSA\nASSIGNMENT NUMBER:- 8\nDATE:- 11-10-2022\n\n");
    printf("****************************\n");
    printf("Question 1 \n");
    q1();
    printf("\n");

    printf("Question 1 executed successfully\n\n");
    printf("****************************\n");

    printf("Question 3\n");
    q3();

    printf("\n");

    printf("Question 3 executed successfully\n\n");
    printf("****************************\n");
    printf("Question 2\n");
    q2();

    printf("\n");

    printf("Question 2 executed successfully\n\n");
    printf("****************************\n");
    return 0;
}