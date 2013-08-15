/*
* author:	Atom
* date:		2012/12/03
* file:		Astar.h
*/
#ifndef ASTAR_H
#define ASTAR_H

#include <stdio.h>
#include <math.h>
#include "bheap.h"
#include "iostream"
#define _ITERATOR_DEBUG_LEVEL  0
#define MALLOC(type,n)  (type *)malloc((n)*sizeof(type))

#define MAX(a,b) ((a)>(b))?(a):(b)

#define START		1
#define END			-1
#define EMPTY		0
#define WALL		9
#define ROAD		8

struct tile_map
{
	int** map;
	int row;
	int column;
};

struct aPoint
{
	aPoint()
	{
		posX = 0;
		posY = 0;
	}
	int posX;
	int posY;
};


struct map_node
{
	int x;
	int y;
	long f;											/*最终路径长度*/
	long g;											/*起点到该点的已知长度*/
	long h;											/*该点到终点的估计长度*/
	map_node* parent;
};

typedef long (* distance_t)(int, int, int, int);

int init_map(struct tile_map*);
void gen_wall(struct tile_map*);
bool gen_cell(struct tile_map* tmap, int row, int column, int type);
void destory_map(struct tile_map*);
void astar(struct tile_map*, int, int, int, int, distance_t, bool fourdir = true);
map_node* astar_find_road(tile_map* tmap, int st_x, int st_y, int end_x, int end_y, Bheap *o_heap,Bheap *c_heap, distance_t distance, bool fourdir = true);
bool astar_full_road(struct tile_map* tmap, int st_x, int st_y, int end_x, int end_y,
	std::vector<CCPoint>&vcPoint,int _cellwidth, int _cellheight, int _offsetx, int _offsety, distance_t distance, bool fourdir = true);
bool astar_next_step(struct tile_map* tmap, int st_x, int st_y, int end_x, int end_y, aPoint& nextstep, distance_t distance, bool fourdir = true);
int _comp(struct Bheap_node*, struct Bheap_node*);
int _eq(struct Bheap_node*, struct Bheap_node*);
int is_reachable(struct tile_map*, int, int);
int is_arrived(struct tile_map*, struct map_node*);
void free_map_node(struct Bheap_node*);
int deal_child(struct tile_map*, struct Bheap*, struct Bheap*, int, int,
 struct map_node*, distance_t, int, int);
long point_distance(int, int, int, int);

static void print_map(struct tile_map* tmap);
static void print_point(struct map_node*, char );
static void print_heap(struct Bheap*);

long euclidean_distance(int, int, int, int);		/* 欧氏距离 */
long manhattan_distance(int, int, int, int);		/* 曼哈顿距离 */
long chebyshew_distance(int, int, int, int);		/* 切比雪夫距离 */
#endif		/*ASTAR_H*/
