#include "update_locations.h"

vec_t* generate_random_list(int size, int bound) {
    srand(size);
    vec_t* randArray = malloc((sizeof(vec_t))*size);
    for (int i = 0; i <= size; i++) {
        randArray[i] = (rand() % (2*bound + 1)) - bound;
    }
    return randArray;
}

void update_coords(vec_t* xs, vec_t* ys, vec_t* zs, vec_t* vx, vec_t* vy, vec_t* vz, int size) {
    for (int8_t i = 0; i <= size; i++) {
        xs[i] = xs[i] + vx[i];
        ys[i] = ys[i] + vy[i];
        zs[i] = zs[i] + vz[i];
    }
}

vec_t sum(vec_t* arr, int size) {
    vec_t arrSum = 0;
    for (int i = 0; i <= size; i++) {
        arrSum = arrSum + arr[i];
    }
    return arrSum;
}

double time_exe(vec_t* xs, vec_t* ys, vec_t* zs, vec_t* vx, vec_t* vy, vec_t* vz, int size) {
    struct timespec start, stop;
    clock_gettime(CLOCK_MONOTONIC, &start);
    update_coords(xs, ys, zs, vx, vy, vz, size);
    clock_gettime(CLOCK_MONOTONIC, &stop);
    double time_taken = (stop.tv_sec - start.tv_sec) + (double)(stop.tv_nsec - start.tv_nsec)/BILLION;
    return time_taken;
}

int main(int argc, char* argv[]) {
    if (argc <= 2 ){
        printf("Missing arguments, please try again\n");
        return -1;
    }
    int size = *argv[1];
    int iters = *argv[2];
    vec_t* xs = generate_random_list(size, 1000);
    vec_t* ys = generate_random_list(size, 1000);
    vec_t* zs = generate_random_list(size, 1000);
    vec_t* vx = generate_random_list(size, 1);
    vec_t* vy = generate_random_list(size, 1);
    vec_t* vz = generate_random_list(size, 1);
    double exec_time = MILLION * time_exe(xs, ys, zs, vx, vy, vz, size)/(size * iters);
    vec_t chksum = sum(xs, size) + sum(ys, size) + sum(zs, size);
    printf("Average time per coordinate= %0.22f us, Chksum = %i \n", exec_time, chksum);
    free(xs);
    free(ys);
    free(zs);
    free(vx);
    free(vy);
    free(vz);
    return 0;
}
