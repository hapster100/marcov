#pragma once

#include <map>
#include <vector>

using namespace std;

class CyrillicTransformer {
  map<string, char> cyrillicToRoman;
  string roman;
public:
  CyrillicTransformer(string roman = "qwertyuiopasdfghjklzxcvbnm1234567 ");
  string transform(string cyrillic);
  vector<char> romanAlphabet();
};