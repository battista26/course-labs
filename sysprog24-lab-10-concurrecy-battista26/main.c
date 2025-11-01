/*
 * main.c
 * 
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
double sum;


typedef struct Area {
    double a;
    double b;
    double (*f)(double);
} Area;

typedef struct Area2 {
    double n;
    double x_start;
    double x_end;
    double (*f)(double);
} Area2;

void *thread_routine1(void * arg) {
    double *localsum;
    localsum = (double*)malloc(sizeof(double));
    Area *test = (Area *)arg;

    if(localsum == NULL) {
        perror("Malloc couldn't allocate");
    }

    *localsum = ((test->b - test->a) * 0.5 * (test->f(test->a) + test->f(test->b)));
    return localsum;
}

void *thread_routine2(void * arg) {
    double localsum;
    Area2 *test2 = (Area2 *)arg;

    localsum = ((test2->f(test2->x_start) + test2->f(test2->x_end)) / 2) * (test2->x_end - test2->x_start);

    pthread_mutex_lock(&m);
    sum += localsum;
    pthread_mutex_unlock(&m);
}

double f1(double x){
	double y = x*x + 5;
	return y;
}

int main(int argc, char **argv){
    int NTHREADS = 5;

    pthread_t tid1;
    pthread_t tid2[NTHREADS];
    double *retval;

    /*[1, 3] is the example for thread_routine1()*/
    Area temp;
    temp.a = 1;
    temp.b = 3;
    temp.f = f1;

    /*[0, 20] is the example for thread_routine2()*/
    int lside = 0;
    int rside = 20;
    int n = ((rside - lside) / NTHREADS);
    Area2 temp2[NTHREADS];
    
    for (int i = 0; i < NTHREADS; i++){
        temp2[i].n = NTHREADS;
        temp2[i].x_start = i*n;
        temp2[i].x_end = i*n + n;
        temp2[i].f = f1;
    }
    
    
    pthread_create(&tid1, NULL, thread_routine1, (void *)&temp);

    pthread_join(tid1, &retval);
    
    for (int i = 0; i < NTHREADS; i++)
    {
        pthread_create(&tid2[i], NULL, thread_routine2, (void *)&temp2[i]);
    }

    for (int i = 0; i < NTHREADS; i++)
    {
        pthread_join(tid2[i], NULL);
    }
    
    
	printf("the integral f1(x): %lf\n", *retval);
    printf("the integral f2(x): %lf\n", sum);
	return 0;
}
