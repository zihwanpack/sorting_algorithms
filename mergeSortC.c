#include <stdio.h>
#include <stdlib.h>

int n;
int *arr;



// quick sort
void swap (int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int split(int s, int e) {
    int lptr = s + 1;
    int rptr = e;
    int pivot = arr[s];

    while (lptr <= rptr) {
        while ((arr[rptr] >= pivot) && (lptr <= rptr))
            rptr--;
        while ((arr[lptr] <= pivot) && (lptr <= rptr))
            lptr++;

        if (lptr < rptr)
            swap(&arr[lptr], &arr[rptr]);
    }
    swap(&arr[rptr], &arr[s]);
    return rptr;
}

void myQsort(int s, int e) {
  // 1. degenerate case
  if (s >= e) return;
  // 2. divide
  // m은 집어넣지 않는다. e, s가 뒤집어질 수 있다.
  int m = split(s, e);
  myQsort(s, m - 1);
  myQsort(m + 1, e);
}


// merge sort
void merge(int ls, int le, int rs, int re) {
    int lptr = ls;
    int rptr = rs;
    int bptr = ls;
    int *brr = (int *)calloc(n, sizeof(int));
    
    while (lptr <= le && rptr <= re) {
        if (arr[lptr] < arr[rptr]) {
            brr[bptr++] = arr[lptr++];
        } else {
            brr[bptr++] = arr[rptr++];
        }
    }
    
    while (lptr <= le) {
        brr[bptr++] = arr[lptr++];
    }
    
    while (rptr <= re) {
        brr[bptr++] = arr[rptr++];
    }

    for (int i = ls; i <= re; i++) {
        arr[i] = brr[i];
    }
    free(brr);
}

void msort(int s, int e) {
    // 1. degenerate case
    if (s == e) return;
    // 2. divide 
    int m = (s + e) / 2;
    msort(s, m);
    msort(m + 1, e);
    // 3. combine
    merge(s, m, m + 1, e);
}

int main(void) {
    FILE *fp = fopen("input.txt", "r");
    
    int tc; // test case 개수
    fscanf(fp, "%d", &tc);
    
    printf("Test cases: %d\n", tc);
    
    for (int i = 0; i < tc; i++) {
        fscanf(fp, "%d", &n);
        arr = (int *)calloc(n, sizeof(int));
        
        for (int j = 0; j < n; j++) {
            fscanf(fp, "%d", &arr[j]);
        }
        
        printf("Original array (size %d): ", n);
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");

        // msort(0, n - 1);
        myQsort(0, n - 1);

        printf("Sorted array: ");
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");

        free(arr);
    }
    
    fclose(fp);
    return 0;
}
