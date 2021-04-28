//
//  main.cpp
//  stable_matching.cpp
//
//  Created by Max Smiley on 4/26/21.
//

#include <iostream>
#include <stack>
#include <random>
#include <utility>

#define N 1000 //number of participants in the perfect matching

using namespace std;

static random_device rd;
static default_random_engine generator(rd());

struct Man
{
    int id;                 //Place in array
    int p_list[N];          //Ranking of women
    int num_proposed = 0;   //Number of women proposed to
    int matched_with = -1;  //Current match, -1 if unmatched
};

struct Woman
{
    int id;                 //Place in array
    int p_list[N];          //Ranking of men
    int get_ranking[N];     //Given a man, returns preference number
    int matched_with = -1;  //Current match, -1 if unmatched
};

Man men[N];
Woman women[N];
stack<int> unmatched_men;

// Return a uniformly distributed random integer from 0 to N-1 inclusive
int randInt()
{
  uniform_int_distribution<> distro(0, N - 1);
  return distro(generator);
}

//Given a pointer to the beginning of an int array, shuffles first n elements
void shuf(int* arr)
{
    for (int i = 0; i < N; i++)
    {
        swap(arr[i], arr[randInt()]);
    }
}

//Initializes an array size N to have random numbers (no numbers will be repeated) from 0-N exclusive
void init_rand_array(int* arr)
{
    for (int i = 0; i < N; i++)
    {
        arr[i] = i;
    }
    shuf(arr);
}

//Given an array indexed 0-N with elements 0-N, reverses indicies and elements
void reverse_copy_from_array(int* arr, const int* from_array)
{
    for (int i = 0; i < N; i++)
    {
        arr[from_array[i]] = i;
    }
}

void init_problem()
{
    for (int i = 0; i < N; i++)
    {
        //Initializes preference lists
        init_rand_array(men[i].p_list);
        init_rand_array(women[i].p_list);
        //Initializes id fields
        men[i].id = i;
        women[i].id = i;
        //Maintains a stack of unmatched men
        unmatched_men.push(i);
    }
}

void run_problem()
{
    while (!unmatched_men.empty())
    {
        Man proposer = men[unmatched_men.top()];
        Woman proposed = women[proposer.p_list[proposer.num_proposed]];
        
        //Unmatched case
        if (proposed.matched_with == -1)
        {
            proposer.matched_with = proposed.id;
            proposed.matched_with = proposer.id;
            unmatched_men.pop();
        }
        //Rejection case
        else if (proposed.get_ranking[proposer.id] < proposed.get_ranking[proposed.matched_with])
        {
            //nothing happens lol
        }
        //Acceptance case
        else
        {
            men[proposed.matched_with].matched_with = -1;
            unmatched_men.pop();
            unmatched_men.push(proposed.matched_with);
            proposer.matched_with = proposed.id;
            proposed.matched_with = proposer.id;
        }
        proposer.num_proposed++;
        men[proposer.id] = proposer;
        women[proposed.id] = proposed;
    }
}

void print_results()
{
    for (int i = 0; i < N; i++)
    {
        cout << "Man " << i << " is matched with woman " << men[i].matched_with << endl;
        cout << "Woman " << i << " is matched with man " << women[i].matched_with << endl;
    }
}

void print_info()
{
    for (int i = 0; i < N; i++)
    {
        cout << "Man " << i << " preference list is " << endl;
        for (int j = 0; j < N; j++)
        {
            cout << men[i].p_list[j];
        }
        cout << endl;
        cout << "Woman " << i << " preference list is " << endl;
        for (int j = 0; j < N; j++)
        {
            cout << women[i].p_list[j];
        }
        cout << endl;
    }
}

class Timer
{
  public:
    Timer()
    {
        start();
    }
    void start()
    {
        m_time = std::chrono::high_resolution_clock::now();
    }
    double elapsed() const
    {
        std::chrono::duration<double,std::milli> diff =
                          std::chrono::high_resolution_clock::now() - m_time;
        return diff.count();
    }
  private:
    std::chrono::high_resolution_clock::time_point m_time;
};

int main(int argc, const char * argv[])
{
    init_problem();
    
    Timer t;
    t.start();
    run_problem();
    cout << t.elapsed() << endl;
    //Indeed, for sufficient N, the runtime of the problem ~quadruples as we double the N, illustrating the quadatic time complexity of the Gale-Shapley algorithm
    
    return 0;
}
