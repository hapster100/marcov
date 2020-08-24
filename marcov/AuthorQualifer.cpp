#include "./AuthorQualifer.hpp"


AuthorQualifier::AuthorQualifier(vector<AuthorAssessment> aa, vector<char> alphabet)
: assessments(aa), alphabet(alphabet) 
{}

map<string, double> AuthorQualifier::qualify(Fragment fragment) {
  FragmentTransitions ft(fragment);
  map<string, double> results;

  for(int i = 0; i < assessments.size(); i++) {
    for(char k : alphabet)
      for(char l : alphabet) {
        double assessment = assessments[i].get(k, l);
        long klTransitions = ft.get(k, l);
        if(assessment && klTransitions) {
          double kTransitions = 0;
          for(auto a : alphabet) {
            kTransitions += ft.get(k, a);
          }
          results[assessments[i].authorName()] -= assessment * log(klTransitions / kTransitions / assessment);
        } 
      }
  }

  return results;
}