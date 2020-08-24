#pragma once

#include <vector>
#include <map>
#include <iostream>
#include <iomanip>
#include "./AuthorTestFiles.hpp"
#include "./AuthorQualifer.hpp"
#include "../reader/FragmentReader.hpp"

using namespace std;

class MarkovExperiment {

  using QualiferResult = map<string, double>;
  
  vector<AuthorAssessment> authors;
  map<string, Fragment> authorTestFragments;

  int getRank(string authorName, QualiferResult result);
  void printResults(vector<pair<string, QualiferResult>> results);

public:
  MarkovExperiment(vector<AuthorTestFiles> testData);
  void runExperiment();
};