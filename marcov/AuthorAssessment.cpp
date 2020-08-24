#include "./AuthorAssessment.hpp"

long AuthorAssessment::getH(char k, char l) {
  if(hs.count({ k, l}))
    return hs[{ k, l }];
  
  long h = 0;
  for(auto transition : transitionList) {
    h += transition.get(k, l);
  }
  hs[{ k, l }] = h;
  return hs[{ k, l}];
}

AuthorAssessment::AuthorAssessment(vector<Fragment> fragments, string name, vector<char> alphabet) 
: name(name), alphabet(alphabet) {
  for(auto fragment : fragments) {
    transitionList.push_back(FragmentTransitions(fragment));
  }
}

void AuthorAssessment::addFragment(Fragment newFragment) {
  FragmentTransitions ft = FragmentTransitions(newFragment);
  transitionList.push_back(ft);
  hs = HsMap();
  assessments = TransitionMap();
}

double AuthorAssessment::get(char k, char l) {
  if(assessments.count({ k, l }))
    return assessments[{ k, l }];
  long hValule = getH(k, l);
  long hlSum = 0;
  for(char alpha : alphabet) {
    hlSum += getH(k, alpha);
  }
  if(hlSum == 0) {
    return 0;
  }

  assessments[{ k, l }] = hValule/(double)hlSum;
  return assessments[{ k, l }];
}

const string AuthorAssessment::authorName() {
  return name;
}