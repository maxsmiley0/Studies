//
//  main.cpp
//  binary_search
//
//  Created by Max Smiley on 4/26/21.
//

#include <iostream>
#include <random>
#include <utility>

#define N 1000000   //Size of array. Must be > 1

using namespace std;

static random_device rd;
static default_random_engine generator(rd());

// Return a uniformly distributed random integer from low to high inclusive
int randInt(int low, int high)
{
  uniform_int_distribution<> distro(low, high);
  return distro(generator);
}

//Initializes a random-ish sorted array
void init_arr(int* arr)
{
    arr[0] = randInt(0, 10);
    for (int i = 1; i < N; i++)
    {
        arr[i] = randInt(arr[i - 1], arr[i - 1] + 100);
    }
}

//Prints an array
void print_array(int* arr)
{
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << endl;
    }
}

//Given an array, picks a random number from it
int pick_number(int* arr)
{
    int seed = randInt(0, N - 1);
    int num = arr[seed];
    cout << "Num: " << num << endl;
    return num;
}

//Traditional, O(n) search. Steps = index
void trad_search(int* arr, int num)
{
    int i = 0;
    while(true)
    {
        if (arr[i] == num)
        {
            cout << "Found! Index: " << i << endl;
            return;
        }
        i++;
    }
}

//Binary search, O(logn) time.
int binary_search(int* arr, int num, int min, int max, int steps)
{
    steps++;
    int mid = (max + min) / 2;
    //Too high
    if (arr[mid] > num)
    {
        return binary_search(arr, num, min, mid, steps);
    }
    //Too low
    else if (arr[mid] < num)
    {
        return binary_search(arr, num, mid, max, steps);
    }
    //Found
    else
    {
        cout << "Found! Index: " << mid << endl;
        cout << "Steps Taken: " << steps << endl;
        return mid;
    }
}

int arr[N];

int main(int argc, const char * argv[]) {
    
    init_arr(arr);
    int num = pick_number(arr);
    trad_search(arr, num);
    binary_search(arr, num, 0, N, 0);
    return 0;
}
