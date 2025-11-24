#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int is_present(int val) {
    int i = 0;
    for (i = 0; i < cachesize; i++) {
        if (cache[i] == val) {
            hitcounter += 1;
            return 1;  // hit
        }
    }
    return 0;  // miss
}
void print_cache() {
    printf("Cache: ");
    int i = 0;
    for (i = 0; i < cachesize; i++) {
        printf("%d ", cache[i]);
    }
    printf("\n");
}
int main() {

    int input[16] = {4, 3, 25, 8, 19, 6, 25, 8, 16, 35, 45, 22, 8, 3, 16, 25};
    int i = 0;
    for (i = 0; i < cachesize; i++) {
        cache[i] = 0;
    }
    int replacement_index = 0;
    for (i = 0; i < 16; i++) {
        int presence = is_present(input[i]);
        if (presence == 1) {
            printf("Accessing %d -> HIT\n", input[i]);
        } else {
            printf("Accessing %d -> MISS (placed at cache[%d])\n", input[i], replacement_index);
            cache[replacement_index] = input[i];
            replacement_index = (replacement_index + 1) % cachesize;
        }
        print_cache();
    }
    printf("\nTotal Hits: %d\n", hitcounter);
    printf("Hit Ratio: %.2f\n", (float)hitcounter / 16);


    return 0;
}
