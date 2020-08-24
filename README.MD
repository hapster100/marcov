# Authorship analysis by Markov chains

Analysis of authorship of a text fragment based on the frequency of transitions of letters.

## Experiment description

There are authors, each of whom has a list of works on the basis of which his "style" is determined. Also for each author there is a text fragment whose authorship will be determined.

## Config

The config file consists of blocks, each of which represents the author.

Block example:

AUTHOR\
FirstName LastName
FRAGMENTS
path_to_texts/text1.txt
path_to_texts/text2.txt
path_to_texts/text3.txt
TEST
path_to_test_fragment/test.txt

AUTHOR: author name
FRAGMENTS: list of absolute or relative pathes to author works
TEST: absolute or relative path to author test text fragment

## Explanation of results

Result example:

Authors:
0 Kir Bylychyov
1 Mikhail Bulgakov
2 Nikolai Vasilievich Gogol
3 Vladimir Nabokov
Ranks:
 №   0   1   2   3
 0   0   2   3   1
 1   1   0   3   2
 2   3   1   0   2
 3   2   1   3   0

Each row of the table shows how much the test fragment resembles the author's works from the column. The higher the value, the less similar they are.

## Runing

make && run config.txt
