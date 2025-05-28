/*
Finish the solution so that it takes an input n (integer) and returns a string that is the decimal representation of the number grouped by commas after every 3 digits.

Assume: 0 <= n <= 2147483647

Examples
       1  ->           "1"
      10  ->          "10"
     100  ->         "100"
    1000  ->       "1,000"
   10000  ->      "10,000"
  100000  ->     "100,000"
 1000000  ->   "1,000,000"
35235235  ->  "35,235,235"
*/

#include <string>

std::string group_by_commas(int n)
{
  std::string num = std::to_string(n);
  std::string output {};
  int count {0};
  
  if (num.size() < 4) return num;
  
  for (int i = num.size() - 1; i >= 0; --i) {
    output += num[i];
    count++;
    
    if (count == 3) {
      if (i > 0) { // Verificar si aun queda digitos pendientes antes de agregar la coma
        output += ',';
        count = 0;
      }
    }
  }
  std::reverse(output.begin(), output.end());
  return output;
}