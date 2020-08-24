#pragma once

#include <map>
#include "./Fragment.hpp"

using namespace std;

class FragmentTransitions {
  map<pair<char, char>, long> transitions;
public:
  FragmentTransitions(Fragment fragment);
  long get(char k, char l);
};