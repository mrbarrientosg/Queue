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

#ifndef Queue_h
#define Queue_h

typedef struct Queue Queue;

/**
 Crea un nuevo puntero de tipo Queue.

 @return Puntero a la nueva Queue.
 */
Queue * createQueue(void);

/**
 Inserta un elemento en la Queue.
 
 Complejidad: O(1)

 @param queue Puntero a la Queue.
 @param data Puntero al elemento que quiere ser insertado.
 */
void enqueue(Queue * queue, const void * data);

/**
 Elimina un elemento de la Queue, sin liberar la memoria del puntero guardado.
 
 Complejidad: O(1)

 @param queue Puntero a la Queue.
 @return Puntero al elemento eliminado de la Queue.
 */
void * dequeue(Queue * queue);

/**
 Retorna, pero no elimina, la cabeza de la cola, o devuelve nulo si esta cola está vacía.
 
 Complejidad: O(1)

 @param queue Puntero a la Queue.
 @return Puntero al elemento obtenido de la cabeza de la cola.
 */
void * front(Queue * queue);

/**
 Retorna la cantidad de elementos en la Queue.
 
 Complejidad: O(1)

 @param queue Puntero a la Queue.
 @return La cantidad de elementos en la Queue.
 */
long queueCount(Queue * queue);

/**
 Prueba si la Queue está vacía.
 
 Complejidad: O(1)
 
 @param queue Puntero a la Queue.
 @return 1 (true) si y solo si la Queue no contiene elementos; 0 (false) lo contrario.
 */
int emptyQueue(Queue * queue);

/**
 Elimina todo los elementos de la Queue, pero no los libera de la memoria.
 
 Complejidad: O(n)
 
 @param queue Puntero a la Queue.
 */
void removeAllQueue(Queue * queue);

#endif /* Queue_h */
