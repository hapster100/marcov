#pragma once

#include <string>
#include <fstream>
#include "../cyrillic/CyrillicTransformer.hpp"
#include "../fragment/Fragment.hpp"

using namespace std;

class FragmentReader {
  CyrillicTransformer cyrillic;
public:
  FragmentReader();
  Fragment read(string fileName);
};
