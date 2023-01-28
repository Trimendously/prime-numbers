Prime.cpp Instructions to Run

This cpp file takes advantage of an age-old algorithm known as the Sieve of Eratosthenes and multithread processing in order to efficiently find all the prime numbers in the range [1,10^8].
Essentially you take a list of all numbers from 0 to (10^8-1) and set them all as prime.
Then you divide up the square root of the max (10^8) into 8 sections (1 for each thread)
Lastly you take each section and set every multiple of the numbers that lie in this section as being composite (not prime).


To run this program first make sure that you have a C++ compiler installed.
Here is a guide that should help to do so: https://www.ics.uci.edu/~pattis/common/handouts/mingweclipse/mingw.html

Next open up the command prompt and navigate to the folder / directory you downloaded the file into 
and type in, or just copy and paste:
g++ -o primes primes.cpp
and then press enter.

This compiles the program so that you may now run it.

To run it simply type
./primes
and then press enter once again.

After that the program should run and within the same folder/ directory that you are in a new primes.txt file should be made storing the following:

<execution time (microseconds)> <total number of primes found>  <sum of all primes found>
<top ten maximum primes, listed in order from lowest to highest>

Overall the program especially with the implementation of Sieve runs relativily efficiently.
The alternatively and naive approach would be to simply iterate over every integer below the current index to check if it is a factor and if so then mark the index as composite and go to the next index.
This algorithm is horrible though in that it runs in O(N*N). While the Sieve approach runs in O(N * log(log(N)))
. On a more powerful machine that can support more concurrent threads the program would of course run faster.