/*
Create a function named divisors/Divisors that takes an integer n > 1 and returns an array with all of the integer's divisors(except for 1 and the number itself), from smallest to largest. If the number is prime return the string '(integer) is prime' (null in C#, empty table in COBOL) (use Either String a in Haskell and Result<Vec<u32>, String> in Rust).

Examples:
divisors(12) --> [2, 3, 4, 6]
divisors(25) --> [5]
divisors(13) --> "13 is prime"
*/

#include <stddef.h>

//  assign divisors to array[]
//  set *length to the number of divisors

void divisors(unsigned n, size_t *length, unsigned array[]) {

  //  <----  hajime!
  *length = 0;
  
  size_t j = 0;
  for (size_t i = 2; i <= n/2; ++i) {
    if (n % i == 0) {
      array[j++] = i;
      (*length)++;
    }
  }
  
}