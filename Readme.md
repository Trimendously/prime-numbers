Prime.cpp Instructions to Run

This cpp file takes advantage of an age-old algorithm known as the Sieve of Eratosthenes and multithread processing in order to efficiently find all the prime numbers in the range [1,10^8].

To run this program simply open up the command prompt and navigate to the folder / directory you downloaded the file into 
and type in, or just copy and paste:
g++ -o primes primes.cpp
and then press enter.

This compiles the program so that you may now run it.

To run it simply type
./primes
and then press enter once again.

After that the program should run and within the same folder/ directory that you are in a new primes.txt file should be made storing the following:

<execution time (in microseconds)> <total number of primes found>  <sum of all primes found>
<top ten maximum primes, listed in order from lowest to highest>

Overall the program especially with the implementation of Sieve runs relativily efficiently