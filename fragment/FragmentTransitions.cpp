#include "./FragmentTransitions.hpp"

FragmentTransitions::FragmentTransitions(Fragment fragment) {
  string fragmentContent = fragment.getContent();
  for(int i = 0; i < fragmentContent.size() - 1; i++) {
    char l = fragmentContent[i];
    char k = fragmentContent[i+1];
    transitions[{l, k}]++;
  }
}

long FragmentTransitions::get(char k, char l) {
  if(transitions.count({k, l}))
    return transitions[{ k, l }];
  return 0;
}