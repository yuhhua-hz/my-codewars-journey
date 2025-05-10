/*
Create a function that returns the sum of the two lowest positive numbers given an array of minimum 4 positive integers. No floats or non-positive integers will be passed.

For example, when an array is passed like [19, 5, 42, 2, 77], the output should be 7.

[10, 343445353, 3453445, 3453545353453] should return 3453455.
*/

#include <vector>
#include <climits>

long sumTwoSmallestNumbers(std::vector<int> numbers)
{
  int min1 {INT_MAX};
  int min2 {INT_MAX};
  
  // Encontrar los 2 minimos
  for (auto n : numbers) {
    if (n < min1) {
      min2 = min1;
      min1 = n;
    } else if (n < min2) min2 = n;
  }
  
  // Ojo con retornar un min1+min2 > overflow de INT
  return static_cast<long>(min1) + static_cast<long>(min2);
    
}
