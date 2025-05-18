/*
Remove the duplicates from a list of integers, keeping the last ( rightmost ) occurrence of each element.

Example:
For input: [3, 4, 4, 3, 6, 3]

remove the 3 at index 0
remove the 4 at index 1
remove the 3 at index 3
Expected output: [4, 6, 3]

More examples can be found in the test cases.

Good luck!
*/

#include <vector>
#include <algorithm> // std::reverse
#include <set> // std::set

std::vector<int> solve(std::vector<int> vec){
  std::vector<int> output {};
  std::set<int> banList {};
  
  if (vec.empty()) return output;
  // recorrer empezando desde el final porque el elemento que se debe conservar es el de mas derecha
  for (int n {static_cast<int>(vec.size()) - 1}; n >= 0; --n ) {
    if (banList.find(vec[n]) == banList.end()) { // Si el numero no se encuentra en la lista baneada
      banList.insert(vec[n]); // marcarlo para no agregar nuevamente 
      output.push_back(vec[n]); // agregarlo a la lista final
    }
  }
   
  std::reverse(output.begin(), output.end());
  return output;
  
}
