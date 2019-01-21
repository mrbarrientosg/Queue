/**
 MIT License
 
 Copyright (c) 2018 Matias Barrientos.
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#include "Queue.h"
#include <stdlib.h>
#include <assert.h>

typedef struct Node Node;

struct Node {
    const void * data;
    Node * next;
};

struct Queue {
    Node * tail;
    long count;
};

static Node * createNode(const void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
   
    assert(new != NULL);
    
    new->data = data;
    new->next = NULL;
   
    return new;
}

Queue * createQueue() {
    Queue * new = (Queue *)malloc(sizeof(Queue));
    
    assert(new != NULL);
    
    new->tail = NULL;
    new->count = 0;
    
    return new;
}

void enqueue(Queue * queue, const void * data) {
    assert(queue != NULL);
    
    Node * new = createNode(data);
    
    if (queue->tail == NULL) {
        new->next = new;
    } else {
        new->next = queue->tail->next;
        queue->tail->next = new;
    }
    
    queue->tail = new;
    queue->count += 1;
}

void * dequeue(Queue * queue) {
    assert(queue != NULL);
    
    if (queue->tail == NULL) return NULL;
    
    Node * aux = queue->tail->next;
    
    void * data = (void *)aux->data;
    
    if (aux == queue->tail) {
        queue->tail = NULL;
    } else {
        queue->tail->next = aux->next;
    }
    
    free(aux);
    
    queue->count -= 1;
    
    return data;
}

void * front(Queue * queue) {
    assert(queue != NULL);
    
    if (queue->tail == NULL || queue->tail->next == NULL) return NULL;
    
    return (void *)queue->tail->next->data;
}

long queueCount(Queue * queue) {
    assert(queue != NULL);
    
    if (queue->tail == NULL) return 0;
    
    return queue->count;
}

int emptyQueue(Queue * queue) {
    assert(queue != NULL);
    return queue->count == 0;
}

void removeAllQueue(Queue * queue) {
    assert(queue != NULL);
    
    while (queue->tail != NULL) {
        dequeue(queue);
    }
}
