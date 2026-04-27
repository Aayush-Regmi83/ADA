
#include <stdio.h>
#include <stdlib.h>


#define LEFT -1
#define RIGHT 1


void printPermutation(int perm[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", perm[i]);
    printf("\n");
}


int getLargestMobile(int perm[], int dir[], int n) {
    int mobile = 0;
    int mobile_index = -1;

    for (int i = 0; i < n; i++) {
        if (dir[i] == LEFT && i != 0 && perm[i] > perm[i - 1]) {
            if (perm[i] > mobile) {
                mobile = perm[i];
                mobile_index = i;
            }
        }
        if (dir[i] == RIGHT && i != n - 1 && perm[i] > perm[i + 1]) {
            if (perm[i] > mobile) {
                mobile = perm[i];
                mobile_index = i;
            }
        }
    }

    return mobile_index;
}


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void johnsonTrotter(int n) {
    int *perm = (int *)malloc(n * sizeof(int));
    int *dir = (int *)malloc(n * sizeof(int));

   
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = LEFT;
    }

    printPermutation(perm, n);

    while (1) {
        int mobile_index = getLargestMobile(perm, dir, n);

       
        if (mobile_index == -1)
            break;

        int k = perm[mobile_index];

       
        if (dir[mobile_index] == LEFT) {
            swap(&perm[mobile_index], &perm[mobile_index - 1]);
            swap(&dir[mobile_index], &dir[mobile_index - 1]);
            mobile_index--;
        } else {
            swap(&perm[mobile_index], &perm[mobile_index + 1]);
            swap(&dir[mobile_index], &dir[mobile_index + 1]);
            mobile_index++;
        }

       
        for (int i = 0; i < n; i++) {
            if (perm[i] > k)
                dir[i] = -dir[i];
        }

        printPermutation(perm, n);
    }

    free(perm);
    free(dir);
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}
