#pragma once

#include <string>
#include <vector>
#include "../fragment/FragmentTransitions.hpp"
#include "../cyrillic/CyrillicTransformer.hpp"

using namespace std;

class AuthorAssessment {

  using HsMap = map<pair<char, char>, long>; 
  using TransitionMap = map<pair<char, char>, double>; 

  string name;
  vector<FragmentTransitions> transitionList;
  vector<char> alphabet;
  HsMap hs;
  TransitionMap assessments;

  long getH(char k, char l);

public:
  AuthorAssessment(vector<Fragment> fragments, string name, vector<char> alphabet = CyrillicTransformer().romanAlphabet());

  void addFragment(Fragment newFragment);

  double get(char k, char l);
  const std::string authorName();
  
};