/*
Implement a function that adds two numbers together and returns their sum in binary. The conversion can be done before, or after the addition.

The binary number returned should be a string.

Examples:(Input1, Input2 --> Output (explanation)))

1, 1 --> "10" (1 + 1 = 2 in decimal or 10 in binary)
5, 9 --> "1110" (5 + 9 = 14 in decimal or 1110 in binary)
*/


#include <cstdint>
#include <string>
#include <algorithm>
#include <cstdio>

// Func aux para convertir de decimal a binario
std::string decToBin(uint64_t dec) {
  
  std::string bin {};
  
  do {
    int bit = dec % 2;
    bin.push_back('0' + bit);
    dec /= 2;
  } while (dec > 0);
  
  std::reverse(bin.begin(), bin.end());
  return bin;
}


std::string add_binary(uint64_t a, uint64_t b) {
  return decToBin(a + b);
}
