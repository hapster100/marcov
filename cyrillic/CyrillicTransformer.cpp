#include "./CyrillicTransformer.hpp"

CyrillicTransformer::CyrillicTransformer(string roman) : roman(roman) {
  string cL = "йцукёенгшщзхъфывапролджэячсмитьбю";
  string cU = "ЙЦУКЁЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ";
  
  for(int i = 1; i < cL.size(); i += 2) {
    cyrillicToRoman[{cL[i - 1], cL[i]}] = roman[i/2];
    cyrillicToRoman[{cU[i - 1], cU[i]}] = roman[i/2];
  }
}

string CyrillicTransformer::transform(string cyrillic) {
  string res = "";
  for(int i = 1; i < cyrillic.size(); i+=2) {
    if(cyrillicToRoman.count({ cyrillic[i - 1], cyrillic[i] })) {
      res += cyrillicToRoman[{ cyrillic[i - 1], cyrillic[i] }];
    } else {
      if(cyrillic[i - 1] == ' ') {
        res += ' ';
      }
      i--;
    }
  }
  return res;
}

vector<char> CyrillicTransformer::romanAlphabet() {
  return { roman.begin(), roman.end() };
}