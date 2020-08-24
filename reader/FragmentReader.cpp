#include "./FragmentReader.hpp"

FragmentReader::FragmentReader() {
  cyrillic = CyrillicTransformer();
}

Fragment FragmentReader::read(std::string fileName) {
  string fragmentContent = " ";
  
  ifstream txt;
  txt.open(fileName);
  
  if(txt.is_open()) {
    while(!txt.eof()) {
      string w; txt >> w;
      if(w[w.size() - 1] == '-' && !txt.eof()) {
        string wContinue; txt >> wContinue;
        w += wContinue;
      }
      string alphaw = cyrillic.transform(w);

      if(alphaw.size() > 0) {
        fragmentContent += alphaw + " ";
      }
    }
    txt.close();
  } else {
    throw "Error on open file";
  }
  return Fragment(fragmentContent);
}
