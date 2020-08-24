# Authorship analysis by Markov chains

Analysis of authorship of a text fragment based on the frequency of transitions of letters.

## Experiment description

There are authors, each of whom has a list of works on the basis of which his "style" is determined. Also for each author there is a text fragment whose authorship will be determined.

## Config

The config file consists of blocks, each of which represents the author.

Block example:

AUTHOR__
FirstName LastName__
FRAGMENTS__
path_to_texts/text1.txt__
path_to_texts/text2.txt__
path_to_texts/text3.txt__
TEST__
path_to_test_fragment/test.txt

AUTHOR: author name__
FRAGMENTS: list of absolute or relative pathes to author works__
TEST: absolute or relative path to author test text fragment__

## Explanation of results

Result example:

Authors:__
0 Kir Bylychyov__
1 Mikhail Bulgakov__
2 Nikolai Vasilievich Gogol__
3 Vladimir Nabokov__
Ranks:__
 №   0   1   2   3__
 0   0   2   3   1__
 1   1   0   3   2__
 2   3   1   0   2__
 3   2   1   3   0__

Each row of the table shows how much the test fragment resembles the author's works from the column. The higher the value, the less similar they are.

## Runing

make && run config.txt
