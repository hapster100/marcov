#include "./MarkovExperiment.hpp"

int MarkovExperiment::getRank(string authorName, QualiferResult result) {
  double targetResult = result[authorName];
  int rank = 0;
  for(auto authorResult : result) {
    if(authorResult.second < targetResult) rank++;
  }
  return rank;
}

void MarkovExperiment::printResults(vector<pair<string, QualiferResult>> results) {

  const int authorsNum = results.size();
  const string yellow = "\033[33m";
  const string white = "\033[0m";

  cout << "Authors:" << endl;

  for(int i = 0; i < authorsNum; i++) {
    cout << yellow << i << white << ") " << results[i].first << endl;
  }

  cout << "Ranks:" << endl;

  cout << yellow << setw(2) << " №";
  for(int i = 0; i < authorsNum; i++) cout << setw(4) << i;
  cout << endl << white;

  for(int i = 0; i < authorsNum; i++) {
    cout << yellow << setw(2) << i << white;
    for(int j = 0; j < authorsNum; j++) {
      int rank = getRank(results[j].first, results[i].second);
      cout << setw(4) << rank;
    } 
    cout << endl;
  }
}

MarkovExperiment::MarkovExperiment(vector<AuthorTestFiles> testData) {
  for(auto test : testData) {
    FragmentReader fr;

    vector<Fragment> authorFragments;
    for(auto text : test.fileNames) {
      authorFragments.push_back(fr.read(text));
    }

    Fragment testFragment = fr.read(test.testFileName);

    authors.push_back({ authorFragments, test.authorName });
    authorTestFragments.insert({ test.authorName, testFragment });
  }
}

void MarkovExperiment::runExperiment() {

  AuthorQualifier aq = AuthorQualifier(authors);
  vector<pair<string, QualiferResult>> results;
  for(auto testFragment : authorTestFragments) {
    results.push_back({ testFragment.first, aq.qualify(testFragment.second) });
  }
  printResults(results);
}