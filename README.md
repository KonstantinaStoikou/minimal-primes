## Program that finds minimal prime numbers
According to Wikipedia's [Minimal prime (recreational mathematics)](https://en.wikipedia.org/wiki/Minimal_prime_(recreational_mathematics))
> In recreational number theory, a minimal prime is a prime number for which there is no shorter subsequence of its digits in a given base that form a prime.

Define the number (MAXNUMB) until the program will search for minimal primes (default 100000000).  
The program might run for some seconds until all minimal primes are found.  
Compile and run:
```
$ gcc -o minprimes minprimes.c -lm
$ ./minprimes
```
Output:
```
2
3
5
7
11
19
41
61
89
409
449
499
881
991
6469
6949
9001
9049
9649
9949
60649
666649
946669
60000049
66000049
66600049
```
