/*
NAME:- ABHISHIKTH BODA
COURSE:- ADSA
ASSIGNMENT NUMBER:- 11
DATE:- 11-11-2022
*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#define DEBUG 0

typedef struct edge
{
    int dest;
    int lngth;
    struct edge *next;
    struct edge *src;
} edge;

typedef struct vertex
{
    int vertices;
    struct edge *listArr;
} vertex;

typedef struct heap_element
{
    int v, d;
} heap_element;

typedef struct MinHeap
{
    int *positionInheap;
    int heap_size;
    int number_of_nodes;
    heap_element **arr;
} MinHeap;

void minHeapify(int index, MinHeap *mh);

vertex *graph_create(int total_vertices)
{
    int i = 0;
    vertex *vertex = (struct vertex *)malloc(sizeof(vertex));
    vertex->vertices = total_vertices;
    vertex->listArr = (edge *)malloc(total_vertices * sizeof(edge));

    while (i != total_vertices)
    {
        vertex->listArr[i].src = NULL;
        i++;
    }
    if (DEBUG)
        printf("Graph is created\n");
    return vertex;
}

void edge_add(vertex *vertex, int v1, int v2, int leng)
{
    edge *srcNode = (edge *)malloc(sizeof(edge));
    srcNode->dest = v2;
    srcNode->lngth = leng;
    srcNode->next = vertex->listArr[v1].src;
    vertex->listArr[v1].src = srcNode;
    edge *destNode = (edge *)malloc(sizeof(edge));
    destNode->dest = v1;
    destNode->lngth = leng;
    destNode->next = vertex->listArr[v2].src;
    vertex->listArr[v2].src = destNode;
}

MinHeap *createMinHeap(int total_vertices)
{
    MinHeap *mh = (MinHeap *)malloc(sizeof(MinHeap));
    mh->positionInheap = (int *)malloc(total_vertices * sizeof(int));
    mh->heap_size = total_vertices;
    mh->number_of_nodes = 0;
    mh->arr = (heap_element **)malloc(total_vertices * sizeof(heap_element *));
    return mh;
}

heap_element *newheap_element(int ver, int dist)
{
    heap_element *heap_element = (struct heap_element *)malloc(sizeof(heap_element));
    heap_element->v = ver;
    heap_element->d = dist;
    return heap_element;
}

void decreaseKey(MinHeap *mh, int v, int dist)
{
    int id = mh->positionInheap[v];
    if (DEBUG)
        printf("initial id:%d\n", id);
    mh->arr[id]->d = dist;
    while (mh->arr[id]->d < mh->arr[(id - 1) / 2]->d && id)
    {
        mh->positionInheap[mh->arr[id]->v] = (id - 1) / 2;
        mh->positionInheap[mh->arr[(id - 1) / 2]->v] = id;
        heap_element *t = mh->arr[id];
        mh->arr[id] = mh->arr[(id - 1) / 2];
        mh->arr[(id - 1) / 2] = t;
        id = (id - 1) / 2;
        if (DEBUG)
            printf("modified id:%d\n", id);
    }
}

heap_element *extractMin(MinHeap *mh)
{
    heap_element *min_heap_root;
    if (mh->number_of_nodes == 0)
        return NULL;
    else
    {
        if (DEBUG)
            printf("number of nodes:%d\n", mh->number_of_nodes);
        min_heap_root = mh->arr[0];
        heap_element *lnode = mh->arr[mh->number_of_nodes - 1];
        mh->arr[0] = lnode;
        mh->positionInheap[min_heap_root->v] = mh->number_of_nodes - 1;
        mh->positionInheap[lnode->v] = 0;
        mh->number_of_nodes = mh->number_of_nodes - 1;
        minHeapify(0, mh);
    }
    return min_heap_root;
}
void minHeapify(int index, MinHeap *mh)
{
    int least;
    int l, r;
    heap_element *leastNode;
    heap_element *indNode;

    least = index;
    l = (2 * (index)) + 1;
    r = (2 * (index)) + 2;

    if (l < mh->number_of_nodes)
    {
        if (mh->arr[l]->d < mh->arr[least]->d)
        {
            least = l;
        }
    }

    if (r < mh->number_of_nodes)
    {
        if (mh->arr[r]->d < mh->arr[least]->d)
        {
            least = r;
        }
    }

    if (least != index)
    {

        leastNode = mh->arr[least];
        indNode = mh->arr[index];
        mh->positionInheap[leastNode->v] = index;
        mh->positionInheap[indNode->v] = least;
        heap_element *t = mh->arr[least];
        mh->arr[least] = mh->arr[index];
        mh->arr[index] = t;
        minHeapify(least, mh);
    }
}

int main(int argc, char *argv[])
{
    printf("****************************\n\n");
    printf("NAME:- ABHISHIKTH BODA\nCOURSE:- ADSA\nASSIGNMENT NUMBER:- 11\nDATE:- 11-11-2022\n\n");
    printf("****************************\n\n");
    int k = 0, v, i, src, des, edgeLength, total_vertices, total_edges, maximum, total_cost = 0;
    printf("Enter no.of edges and no.of vertices\n");
    scanf("%d %d", &total_vertices, &total_edges);
    if (total_vertices == 0)
        exit(0);

    vertex *vertex = graph_create(total_vertices);
    printf("Enter source, destination and edgelength\n");
    for (k = 0; k < total_edges; k++)
    {
        scanf("%d %d %d", &src, &des, &edgeLength);
        edge_add(vertex, src, des, edgeLength);
    }
    int dist[total_vertices];

    MinHeap *mh = createMinHeap(total_vertices);
    mh->number_of_nodes = total_vertices;
    for (i = 0; i < total_vertices; ++i)
    {
        dist[i] = INT_MAX;
        mh->arr[i] = newheap_element(i, dist[i]);
        mh->positionInheap[i] = i;
    }
    mh->arr[0] = newheap_element(0, dist[0]);
    mh->positionInheap[0] = 0;
    dist[0] = 0;
    decreaseKey(mh, 0, dist[0]);
    while (!(mh->number_of_nodes == 0))
    {
        heap_element *heap_element = extractMin(mh);
        int vrtex = heap_element->v;
        edge *nodeAl = vertex->listArr[vrtex].src;

        while (nodeAl != NULL)
        {
            int v = nodeAl->dest;
            if (DEBUG)
                printf("destination vertex:%d\n", v);
            if (dist[vrtex] != INT_MAX)
            {
                if (mh->positionInheap[v] < mh->number_of_nodes)
                {
                    if (nodeAl->lngth + dist[vrtex] < dist[v])
                    {
                        dist[v] = dist[vrtex] + nodeAl->lngth;
                        decreaseKey(mh, v, dist[v]);
                    }
                }
            }
            nodeAl = nodeAl->next;
        }
    }
    for (i = 0; i < total_vertices; ++i)
    {
        if (dist[0] < dist[i])
        {
            dist[0] = dist[i];
            maximum = i;
        }
    }
    printf("%d %d\n", maximum, dist[0]);
}