//#pragma
#ifndef RANDOM_H_
#define RANDOM_H_
#include <cstdlib>
#include <vector>
#include <ctime>
#include "Vector.h"    // works for STL vector and  CSE-made Vector
using namespace std;
void rand_seed();
int rand_int(int, int);
// for vector
void random_vector(int, int, int, vector<int>&, int);
void random_vector_norep(int, int, int, vector<int>&, int);
// for Vector
void random_vector(int, int, int, Vector<int>&, int);
void random_vector_norep(int, int, int, Vector<int>&, int);
#endif
