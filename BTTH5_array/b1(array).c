#include <stdio.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void bubbleSort(int a[],int b){
    for(int i=0;i<b;i++){
        for(int j=0;j<b;j++){
            if(a[j]>a[j+1]){
                int tmp=a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

void selectionSort(int a[],int b){
    int i,j,min_idx;
    for( i=0;i<b;i++){
         min_idx=i;
        for( j=0;j<b;j++){
            if(a[j]<a[min_idx]){
                min_idx=j;
            }
        }
        int tmp1=a[j];
        a[j]=a[min_idx];
        a[min_idx]=tmp1;
    }
}


int main(){
    int a[1000];
    int b=sizeof(a)/sizeof(a[0]);
    srand(time(NULL));
    for(int i=0;i<b;i++){
        a[i]=rand();
    }
    clock_t start_bubble = clock();
    bubbleSort(a, b);
    clock_t end_bubble = clock();
    double time_bubble = (double)(end_bubble - start_bubble) / CLOCKS_PER_SEC;
    srand(time(NULL));
    for (int i = 0; i < b; i++) {
        a[i] = rand();
    }
    clock_t start_selection = clock();
    selectionSort(a, b);
    clock_t end_selection = clock();
    double time_selection = (double)(end_selection - start_selection) / CLOCKS_PER_SEC;
    printf("thoi gian thuc hien Bubble sort : %f giay\n", time_bubble);
    printf("thoi gian thuc hien Selection sort : %f giay\n",time_selection);
    return 0;
}