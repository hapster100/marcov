#include "./Fragment.hpp"

Fragment::Fragment(string fragmentContent) : content(fragmentContent) {}
Fragment::Fragment(Fragment const & f) : content(f.getContent()) {}

string Fragment::getContent() const {
  return content;
}
