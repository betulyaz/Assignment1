# Prime Numbers - Sieve of Eratosthenes 

Sieve of Eratosthenes  algorithm which takes O(n log log n) and O(√n) space to find all the primes from 1 to 10^8.
This is how you can use g++ to compile and run your c++ application.

## Environment Setup
- To compile and run my program, you need to have a C++ compiler that supports the C++11 standard or higher, such as g++ or clang++. 

Make sure *g++* installed by running following command:

```
g++ --version
```

if you see *command not found: g++*, you need to install *g++*.

### Installing gcc

  - MacOS
    ```
    $ brew install gcc
    ```
  - Linux
    - Debian/Ubuntu
      ```
      $ sudo apt install gcc
      $ sudo apt install g++
      ```
  - Windows

    - [Download] gcc compiler
    
## Compiling
- To compile the file, you need to use the following command:

```
g++ -std=c++11 -O3 PrimeNumbers.cpp -o PrimeNumbers
```

- This command will create an executable file named primes in the same directory as the source code file primes.cpp.
- To run the program, you need to use the following command:

```
./PrimeNumbers
```

- This command will execute the file primes and write the output to a file named primes.txt in the same directory. 
- This will also print out the contents of the txt file as its called at the end of the main function
- You can open the file primes.txt to see the output.


[Download]: https://gcc.gnu.org/

