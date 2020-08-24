#include "./marcov/MarkovExperiment.hpp"

int main(int argc, char** argv) {
  if(argc < 2) {
    cout << "No config file on input!" << endl;
  } else {
    string configFileName = argv[1];
    ifstream config;
    config.open(configFileName);

    vector<AuthorTestFiles> testData;

    string input;
    if(config.is_open()) {
      while(!config.eof()) {
        config >> input;
        if(input == "AUTHOR") {
          
          string name;
          vector<string> fragments;
          string test;

          config >> input; 
          while(input != "FRAGMENTS") {
            name += input + " ";
            config >> input;
          }
          config >> input;
          while(input != "TEST") {
            fragments.push_back(input);
            config >> input;
          }
          config >> test;

          testData.push_back({
            name,
            fragments,
            test
          });

        }
      }

      MarkovExperiment(testData).runExperiment();

    } else {
      cout << "Error on open " << configFileName << endl;
    }
  }
}
