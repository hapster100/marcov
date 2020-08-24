#pragma once

#include <string>

using namespace std;

class Fragment {
  string content;
public:
  Fragment(string fragmentContent);
  Fragment(Fragment const & f);
  string getContent() const;
};