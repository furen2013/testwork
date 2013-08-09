/*
*	author:	Atom
* date:		2012/12/02
* file:		bheap.h
*/
#ifndef _BHEAP_H
#define _BHEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEF_SIZE			16				/* Ĭ��heap��С */
#define INC_RATE			1.5				/* heap�Զ������ٶ� */

enum Bheap_type
{
	BHEAP_TYPE_BIG,								/* �������� */
	BHEAP_TYPE_SMALL							/* С������� */
};

struct Bheap_node
{
	void* value;
};

struct Bheap
{
	struct Bheap_node**	head;
	size_t							size;				/* ��ǰԪ�ظ��� */
	size_t							max_size;		/* ������ */
	enum Bheap_type			Btype;			/* ������ */
};

/*		condition		result
*			n1 > n2				1
*			n1 == n2			0
*			n1 < n2				-1
*/
typedef int (*Bheap_compare_t)(struct Bheap_node* n1, struct Bheap_node* n2);

/*		condition		result
*			n1 == n2			1
*			n1 != n2			0
*/
typedef int (*Bheap_equal_t)(struct Bheap_node* n1, struct Bheap_node* n2);

/* free �ڵ�,����bn->value */
typedef void (*Bheap_free_node_t)(struct Bheap_node* bn);

/*���� Bheap_type ���������,���δָ���Ѵ�С��ָ���ĶѴ�С С�ڵ��� 1,���ʼ��������Ϊ16*/
static struct Bheap* Bheap_create(size_t size, enum Bheap_type Btype)
{
	struct Bheap* heap = NULL;

	if (NULL == (heap = (struct Bheap*)malloc(sizeof(struct Bheap))))
	{
		fprintf(stderr, "Bheap malloc error!\n");
		return (NULL);
	}
	memset(heap, 0x00, sizeof(struct Bheap));
		
	if (size > 1)
	{
		heap->head = (struct Bheap_node**)malloc(sizeof(struct Bheap_node*) * (size + 1));
		if (NULL == heap->head)
		{
			fprintf(stderr, "Bheap.head malloc error!\n");
			return (NULL);
		}
		heap->max_size = size;
	}
	else
	{
		heap->head = (struct Bheap_node**)malloc(sizeof(struct Bheap_node*) * ((DEF_SIZE) + 1));
		if (NULL == heap->head)
		{
			fprintf(stderr, "Bheap.head malloc error!\n");
			return (NULL);
		}
		heap->max_size = DEF_SIZE;
	}
	
	heap->Btype = Btype;
	
	return (heap);
}

/* ��ʼ������� */
static void Bheap_init(struct Bheap* heap)
{
	if (NULL == heap)
		return;
	
	memset(heap->head, 0x00, (sizeof(struct Bheap_node*) * (heap->size + 1)));
	
	heap->size = 0;
}

/* ������������� */
static size_t __inc_Bheap_size(struct Bheap* heap)
{
	if (NULL == heap)
		return (-1);

	heap->max_size = (size_t)((INC_RATE) * heap->max_size);
	
	heap->head = (struct Bheap_node**)realloc(heap->head, sizeof(struct Bheap_node*) * (heap->max_size + 1));
	
	if (NULL == heap->head)
		return (-1);

	return (0);
}

/* �����ڵ����� */
static void __swap_Bheap_node(struct Bheap_node** n1, struct Bheap_node** n2)
{
	struct Bheap_node* temp;
	
	if (*n1 == *n2)
		return;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

/* ��Ѳ��� */
static int Bheap_push(struct Bheap* heap, struct Bheap_node* node, Bheap_compare_t comp)
{
	int n = 0, c;
	if ((NULL == heap) || (NULL == node) || (NULL == comp))
		return	(-1);
	
	if ((heap->size == heap->max_size) && (-1 == __inc_Bheap_size(heap)))
	{
		fprintf(stderr, "increase heap size error!\n");
		return (-1);
	}
	heap->size++;
	n = heap->size;
	heap->head[heap->size] = node;
	
	/* �������,����ѭ���е��ж� */
	if (BHEAP_TYPE_SMALL == heap->Btype)
	{
		/* С���� */
		for ( ; ; )
		{
			if (1 == n)
				break;
			c = n;
			n = n>>1;
			if (1 == comp(heap->head[n], heap->head[c]))
				__swap_Bheap_node(&(heap->head[n]), &(heap->head[c]));
			else
				break;
		}
	}
	else
	{
		/* ����� */
		for ( ; ; )
		{
			if (1 == n)
				break;
			c = n;
			n = n>>1;
			if (-1 == comp(heap->head[n], heap->head[c]))
				__swap_Bheap_node(&(heap->head[n]), &(heap->head[c]));
			else
				break;
		}
	}
	
	return (0);
}

/* �Ƴ��ڵ� */
static struct Bheap_node* Bheap_remove(struct Bheap* heap, size_t idx, Bheap_compare_t comp)
{
	int n = 0, c;
	if ((NULL == heap) || (idx < 1) || (idx > heap->size) || (NULL == comp))
		return (NULL);
		__swap_Bheap_node(&(heap->head[idx]), &(heap->head[heap->size]));
	
	n = idx;	
	heap->size--;
	
	/* �������,����ѭ���е��ж� */
	if (BHEAP_TYPE_SMALL == heap->Btype)
	{
		/* С���� */
		for ( ; ; )
		{
			c = n;
			n = n<<1;
			if (n > heap->size)
				break;
			
			if ((n + 1) > heap->size)
			{
				if (1 == comp(heap->head[c], heap->head[n]))
					__swap_Bheap_node(&(heap->head[c]), &(heap->head[n]));
				else
					break;
			}
			else
			{
				if (1 == comp(heap->head[n], heap->head[n + 1]))
				{
					if (1 == comp(heap->head[c], heap->head[n + 1]))
					{
						__swap_Bheap_node(&(heap->head[c]), &(heap->head[n + 1]));
						n += 1;
					}
					else
						break;
				}
				else 
				{
					if (1 == comp(heap->head[c], heap->head[n]))
						__swap_Bheap_node(&(heap->head[c]), &(heap->head[n]));
					else
						break;
				}
			}
		}/* end for */
	}
	else
	{
		/* ����� */
		for ( ; ; )
		{
			c = n;
			n = n<<1;
			if (n > heap->size)
				break;
			
			if ((n + 1) > heap->size)
			{
				if (-1 == comp(heap->head[c], heap->head[n]))
					__swap_Bheap_node(&(heap->head[c]), &(heap->head[n]));
				else
					break;
			}
			else
			{
				if (-1 == comp(heap->head[n], heap->head[n + 1]))
				{
					if (-1 == comp(heap->head[c], heap->head[n + 1]))
					{
						__swap_Bheap_node(&(heap->head[c]), &(heap->head[n + 1]));
						n += 1;
					}
					else
						break;
				}
				else 
				{
					if (-1 == comp(heap->head[c], heap->head[n]))
						__swap_Bheap_node(&(heap->head[c]), &(heap->head[n]));
					else
						break;
				}
			}
		}/* end for */
	}
	
	return (heap->head[heap->size + 1]);
}

/* ���Ѳ��� */
static struct Bheap_node* Bheap_pop(struct Bheap* heap, Bheap_compare_t comp)
{
	if ((NULL == heap) || (NULL == comp) || (0 == heap->size))
		return (NULL);
	
	return Bheap_remove(heap, 1, comp);
}

/* �ж϶����Ƿ����ĳ�ڵ� */
static size_t is_Bheap_contain(struct Bheap* heap, struct Bheap_node* node, Bheap_equal_t eq)
{
	int n = 1;
	if ((NULL == heap) || (node == NULL) || (NULL == eq))
		return (-1);
	
	for ( ; n <= heap->size; n++)
	{
		if (1 == eq(heap->head[n], node))
			return (n);
	}
	
	return (-1);
}

/* ��ȡĳ�ڵ� */
static struct Bheap_node* Bheap_get(struct Bheap* heap, size_t idx)
{
	if ((NULL == heap) || (idx < 1) || (idx > heap->max_size))
		return (NULL);
	
	return (heap->head[idx]);
}

/* ������,�����Ҫ���ٽڵ㣬
*	is_need_free_node �������ֵ(���鴫1) ����ָ���Լ�ʵ�ֵ�Bheap_free_node_t,
* �粻��Ҫ���ٶ��нڵ� ��is_need_free_node����0,Bheap_free_node_tΪNULL
*/
static void Bheap_destory(struct Bheap** heap, int is_need_free_value, Bheap_free_node_t free_node)
{
	size_t o_idx = 1;
	if ((NULL == *heap))
		return;

	if (is_need_free_value && (NULL != free_node))
		for ( ; o_idx <= (*heap)->size; o_idx++)
		{
			if (NULL != ((*heap)->head[o_idx])->value)
			{
				if (NULL != (*heap)->head[o_idx])
				{
					free_node((*heap)->head[o_idx]);
					(*heap)->head[o_idx] = NULL;
				}
			}
		}
	if (NULL != (*heap)->head)
	{
		free((*heap)->head);
		(*heap)->head = NULL;
	}
	free(*heap);
	*heap = NULL;
}

#endif	/*_BHEAP_H*/
