#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define BILLION 1E9
#define MILLION 1E6

typedef int8_t vec_t;

vec_t* generate_random_list(int size, int bound);

void update_coords(vec_t* xs, vec_t* ys, vec_t* zs, vec_t* vx, vec_t* vy, vec_t* vz, int size);

vec_t sum(vec_t* arr, int size);

double time_exe(vec_t* xs, vec_t* ys, vec_t* zs, vec_t* vx, vec_t* vy, vec_t* vz, int size);

int main(int argc, char* argv[]);