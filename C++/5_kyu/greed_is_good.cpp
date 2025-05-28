/*
Greed is a dice game played with five six-sided dice. Your mission, should you choose to accept it, is to score a throw according to these rules. You will always be given an array with five six-sided dice values.

 Three 1's => 1000 points
 Three 6's =>  600 points
 Three 5's =>  500 points
 Three 4's =>  400 points
 Three 3's =>  300 points
 Three 2's =>  200 points
 One   1   =>  100 points
 One   5   =>   50 point
A single die can only be counted once in each roll. For example, a given "5" can only count as part of a triplet (contributing to the 500 points) or as a single 50 points, but not both in the same roll.

Example scoring

 Throw       Score
 ---------   ------------------
 5 1 3 4 1   250:  50 (for the 5) + 2 * 100 (for the 1s)
 1 1 1 3 1   1100: 1000 (for three 1s) + 100 (for the other 1)
 2 4 4 5 4   450:  400 (for three 4s) + 50 (for the 5)
In some languages, it is possible to mutate the input to the function. This is something that you should never do. If you mutate the input, you will not be able to pass all the tests.
*/

#include <array>
#include <map>

int score(const std::array<unsigned, 5>& dice) {
  // Your code here
  int score{0};
  std::map<unsigned, unsigned>dict {};
  
  // Crear diccionario con el numero y num de repeticiones
  for (auto n : dice) {
    dict[n]++;
  }
  
  for (auto elem : dict) {
    
    int count = elem.second;
    int number = elem.first;
    // Procesar triples sumar los puntos correspondientes. Calcular el monton de dados restantes
    if (count >= 3) {
      count -= 3;
      if (number == 1) score += number * 1000;
      else score += number * 100;
    }
    
    // Procesar si hay dados restantes. Sumar puntos segun el numero de dados restantes
    if (count > 0) {
      if (number == 1) score += count * 100; 
      else if (number == 5) score += count * 50;
    }

  }
  return score;
}
