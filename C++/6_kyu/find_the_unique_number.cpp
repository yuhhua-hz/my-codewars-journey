/*
There is an array with some numbers. All numbers are equal except for one. Try to find it!

finduniq((const float[]){1, 1, 1, 2, 1, 1}, 5); --> 2
finduniq((const float[]){0, 0, 0.55, 0, 0}, 5); --> 0.55

It’s guaranteed that array contains at least 3 numbers.

The tests contain some very huge arrays, so think about performance.
*/

float find_uniq(const std::vector<float> &v)
{
  
  // Comprobar los 3 primeros numeros si son iguales o distintos
  if (v[0] != v[1]) {
    if (v[0] == v[2]) return v[1];
    else return v[0];
  }
  // En caso de v[0] == v[1], quiere decir que el repetido esta al inicio
  else {
    auto repeated = v[0];
    // Comenzar a iterar desde el 3 numero, los dos primeros se han comprobado ya
    for (size_t i {2}; i < v.size(); ++i) {
      if (v[i] != repeated) return v[i];
    }
  }
  
}
