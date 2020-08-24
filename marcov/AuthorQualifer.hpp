#pragma once

#include <vector>
#include <cmath>
#include "./AuthorAssessment.hpp"
#include "../cyrillic/CyrillicTransformer.hpp"

using namespace std;

class AuthorQualifier {
  vector<AuthorAssessment> assessments;
  vector<char> alphabet;
public:
  AuthorQualifier(vector<AuthorAssessment> aa, vector<char> alphabet = CyrillicTransformer().romanAlphabet());
  std::map<std::string, double> qualify(Fragment fragment);
};