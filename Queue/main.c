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

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main() {
    
//    queue *cola = queue_init (NULL);
    queue *cola = queue_init (free);
    
    int * data;
    
    int i;
    
    for (i = 1; i < 10; i++) {
        data = (int *)malloc(sizeof(int));
        *data = i;
        queue_push (cola, data);
    }
    
    while (queue_empty (cola) == 0) {
        data = queue_front (cola);
        printf ("%d\n", *data);
        queue_pop (cola);
    }
    
    queue_release (&cola);
        
    return 0;
}
