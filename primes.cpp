
#include <iostream>
#include <vector>
#include <thread>
#include <fstream>
#include <math.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Prime
{
    int **integers; // Array of ints in range [0,10^8)
    int N; // 10^8
    public:
        Prime(int N)
        {
            this->N = N;
            
            integers = new int *[N]; // An array of size N where 1 indicates is prime and 0 indicate otherwise

            for(int i=0; i < N; i++)
              {
                integers[i] = new int[2]; //Allocates space for int
                integers[i][0] = i; // Stores each int at its respective index 
                integers[i][1] = 1; // Temporarily marks all ints as primes
              }
        }
        void multiples(int x, int buckets)
        {
          int p;
          if (x == 1) 
            p = 2; // Starts at 2 since we don't want multiples of 1 (as that's everything)
          else
            p = (x-1)*buckets;

          for(; p < x*buckets; p++) // Assumes that 8*buckets = sqrt(N) 
          {
            int i = 2*p;

            // Marks every multiple of p as not being prime
            while (i < N)
            {
              integers[i][1] = 0;
              i += p;
            }
          }
        }
        void save(string file, int execution)
        {
          int count = 0; // Counts the total # of primes
          long int sum = 0; // The sum of all prime #'s
          int temp[10], ten_counter = 0; // To get the last 10 primes

          ofstream fout(file);

          if(fout.is_open())
              {
                for(int i = 2 ;i <N ;i++) // Starts at 2 since 1 isn't prime
                    {
                      if (integers[i][1] == 1)
                      {
                        sum += integers[i][0];
                        count ++;
                      } 
                    }
                fout<< execution << " microseconds "<< count << " "<< sum <<endl; 
                //cout<<"Sum:" <<(sum) << endl << "Count: "<< (count) <<endl;

                // Gets the last 10 primes
                for (int j = 1; j < N; j++)
                {
                  if (integers[N-j][1] == 1)
                  {
                    temp[ten_counter] = integers[N-j][0];
                    ten_counter++;
                  }
                  if (ten_counter == 10)
                    break;
                
                }
                // Prints the last 10 primes in order of least to greatest
                for (int z = 9; z >=0;z--)
                  fout<<temp[z]<<endl;

                fout.close();    
              }

          else
              cout<<"cannot open file "<<file;
        }
};



int main()
{
  vector<thread> vecOfThreads; 
  int execution;
  int N = pow(10,8); // Calcs 10^8
  int buckets =  (int)sqrt(N)/8; // Divides sqrt(10^8) into 8 buckets for each thread

  Prime pr(N);

  // We will now implement Sieve of Eratosthenes using 8 concurrent threads
  
  auto start = high_resolution_clock::now(); // Starts the clock

  // Divides the Sieve of Erasthenes space by 8 for 8 threads
  /* Note: This would be faster if instead of using 8 buckets we could spawn more than 8 threads and iterate over 
     the integers up to sqrt(N) all within the for loop below
  */
  for (int x = 1; x < 9; x++)
    vecOfThreads.push_back(thread (&Prime::multiples, ref(pr), x , buckets));


  //cout << sqrt(N) << endl;

  // Waits for all threads in the vector to join

  for (auto& th : vecOfThreads)
    if (th.joinable())
      th.join();    

  auto stop = high_resolution_clock::now(); // Ends the clock
  auto duration = duration_cast<microseconds>(stop - start); 
  
  execution = duration.count();
  //cout << duration.count() << endl;
  //cout << execution << endl;
  pr.save("primes.txt",execution);


  return 0;
}