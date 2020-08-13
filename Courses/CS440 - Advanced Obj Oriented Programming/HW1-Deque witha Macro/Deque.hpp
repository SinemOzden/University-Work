#ifndef DEQUE_H
#define DEQUE_H

#include <stddef.h>
#include <iostream>
#include <stdlib.h>


#define Deque_DEFINE(type)\
\
    struct Deque_##type;\
    \
    struct Deque_##type##_Iterator{\
        Deque_##type *deq;\
        int curr_index;\
        \
        type& (*deref) (Deque_##type##_Iterator * iter);\
        void (*inc) (Deque_##type##_Iterator * iter);\
        void (*dec) (Deque_##type##_Iterator * iter);\
    };\
    \
    struct Deque_##type{\
        int max_size;\
        type* data;\
        int  head, tail;\
        int num_of_items;\
        bool (*compar)(const type& o1,const type& o2);\
        const char type_name[sizeof("Deque_"#type)] = "Deque_"#type;\
        Deque_##type##_Iterator& (*begin) (Deque_##type * q);\
        Deque_##type##_Iterator& (*end) (Deque_##type * q);\
        \
        \
        void dtor(Deque_##type *q){\
            free(q->data);\
        }\
        \
        bool clear(Deque_##type *q){\
            if(q -> num_of_items != 0){\
                q -> num_of_items = 0;\
                q -> head = -1;\
                q -> tail = 0;\
                return 1;\
            }\
            else{\
                return 0;\
            }\
        }\
        \
        void push_back(Deque_##type *q, type x){\
            if(q -> empty(q)){\
                q -> head = 0;\
                q -> num_of_items = 1;\
                q -> data[q -> head] = x;\
            }\
            else{\
                if(q -> isFull(q)){\
                    q -> max_size += max_size;\
                    q -> data = (type*) realloc(q -> data, (size_t) q -> max_size * sizeof(type));\
                    q -> tail++;\
                }\
                else if(q -> tail == q -> max_size-1){\
                    q -> tail =0;\
                }\
                else{\
                    q -> tail++;\
                }\
                q -> data[q -> tail] = x;\
                q -> num_of_items++;\
            }\
        }\
        \
        void push_front(Deque_##type *q, type x){\
            if(q -> empty(q)){\
                q -> head = 0;\
                q -> num_of_items = 1;\
                q -> data[q -> head] = x;\
            }\
            else{\
                if(q -> isFull(q)){\
                    q -> max_size += max_size;\
                    q -> data = (type*) realloc(q -> data, (size_t) q -> max_size * sizeof(type));\
                    q -> head = q -> max_size -1;\
                }\
                else if(q -> head == 0){\
                    q -> head = q -> max_size -1;\
                }\
                else{\
                    q -> head--;\
                }\
                q -> data[q -> head] = x;\
                q -> num_of_items++;\
            }\
        }\
        \
        void pop_front(Deque_##type *q){\
            if(q -> empty(q)){\
                printf("deque is empty\n");\
            }\
            else{\
                if(q -> head == q -> max_size-1){\
                    q -> head = 0;\
                }\
                else{\
                    q -> head++;\
                }\
                q -> num_of_items--;\
            }\
        }\
        \
        void pop_back(Deque_##type *q){\
            if(q -> empty(q)){\
                printf("deque is empty\n");\
            }\
            else{\
                if(q -> tail == 0){\
                    q -> tail = q -> max_size - 1;\
                }\
                else{\
                    q -> tail--;\
                }\
                q -> num_of_items--;\
            }\
        }\
        \
        type& front(Deque_##type *q){\
            return q -> data[q -> head];\
        }\
        \
        type& back(Deque_##type *q){\
            return q -> data[q -> tail];\
        }\
        \
        size_t size(Deque_##type *q) {\
            size_t size = q -> num_of_items;\
            return size;\
        }\
        \
        type& at(Deque_##type* q, int pos){\
            int p = (q -> head + pos)%  q -> max_size;\
            return q -> data[p];\
        }\
        \
        bool isFull(Deque_##type *q){\
            if(q -> num_of_items == q -> max_size){\
                return 1;\
            }\
            else{\
                return 0;\
            }\
        }\
        \
        bool empty(Deque_##type *q){\
            if(q -> num_of_items == 0){\
                return 1;\
            }\
            else{\
                return 0;\
            }\
        }\
        \
        void sort(Deque_##type *q, Deque_##type##_Iterator& iter1, Deque_##type##_Iterator& iter2){\
            /*qsort (void* base, size_t num, size_t size, int (*compar)(const void*,const void*))*/\
            int size = iter1.curr_index - iter2.curr_index;\
            size += q->head;\
            /*qsort(q, *size, sizeof(type), q -> compar((void*) iter1.deref(&iter1), (void*) iter2.deref(&iter2)));*/\
        }\
    };\
    \
    type& deref(Deque_##type##_Iterator* iter){\
            return iter->deq->data[iter->curr_index];\
        }\
    \
    void inc(Deque_##type##_Iterator* iter){\
        if(iter -> curr_index == iter -> deq -> max_size-1){\
            iter -> curr_index = 0;\
        }\
        else{\
            iter -> curr_index++;\
        }\
    }\
    \
    void dec(Deque_##type##_Iterator* iter){\
        if(iter -> curr_index == 0){\
            iter -> curr_index = iter -> deq -> max_size-1;\
        }\
        else{\
            iter -> curr_index--;\
        }\
    }\
    \
    bool Deque_##type##_Iterator_equal(Deque_##type##_Iterator& iter1, Deque_##type##_Iterator& iter2){\
        if(iter1.curr_index == iter2.curr_index){\
            return true;\
        }\
        return false;\
    }\
    bool Deque_##type##_equal(Deque_##type& q1, Deque_##type& q2){\
        if(q1.num_of_items == q2.num_of_items){\
            printf("    len ==\n");\
            Deque_##type##_Iterator it2 = q2.begin(&q2);\
            for (Deque_##type##_Iterator it1 = q1.begin(&q1); !Deque_##type##_Iterator_equal(it1, q1.end(&q1)); it1.inc(&it1)) {\
                if(!Deque_##type##_Iterator_equal(it2, q2.end(&q2))){\
                    printf("        comp1: %d\n", q1.compar(deref(&it1), deref(&it2)));\
                    printf("        comp2: %d\n", q1.compar(deref(&it2), deref(&it1)));\
                    if(q1.compar(deref(&it1), deref(&it2)) || q1.compar(deref(&it2), deref(&it1))){\
                        return 0;\
                    }\
                }\
                it2.inc(&it2);\
            }\
            return 1;\
        }\
        return 0;\
    }\
    \
    void Deque_##type##_Iterator_ctor(Deque_##type##_Iterator * iter, Deque_##type * q, int idx){\
        iter->curr_index = idx;\
        iter->deq = q;\
        iter->inc = &inc;\
        iter->deref = &deref;\
        iter->dec = &dec;\
    }\
    \
    Deque_##type##_Iterator& begin(Deque_##type *q){\
        Deque_##type##_Iterator* iter = (Deque_##type##_Iterator*)malloc(sizeof(Deque_##type##_Iterator));\
        Deque_##type##_Iterator_ctor(iter, q, q->head);\
        return *iter;\
    }\
    \
    Deque_##type##_Iterator& end(Deque_##type *q){\
        Deque_##type##_Iterator* iter = (Deque_##type##_Iterator*)malloc(sizeof(Deque_##type##_Iterator));\
        Deque_##type##_Iterator_ctor(iter, q, q->tail+1);\
        return *iter;\
    }\
    \
    void Deque_##type##_ctor(Deque_##type *q,bool (*func)(const type& o1, const type& o2)){\
        q -> max_size = 10;\
        q -> data = (type*) malloc((size_t) q -> max_size * sizeof(type));\
        q -> head = -1;\
        q -> tail = 0;\
        q -> num_of_items = 0;\
        q -> compar = func;\
        q -> begin = &begin;\
        q -> end = &end;\
    }\


#endif