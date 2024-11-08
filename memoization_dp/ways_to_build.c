/*
input:
    source string a
    target string b
    int k
want to build b from a by putting k substrings of a together

restrictions/rules
1. have to use substrings of a in the same order that they occur in a
2. not allowed to use any empty substrings
3. can't use substrings that overlap
4. must use exactly k substrings of a to build b

output:
numbwer of ways to build b that follow the rules

INPUT: contains one test case with following specs
1. First line of three numbers: length of string a, length of string b, and int k the # of substrings to be used
2. Second line contains string a
3. Third line contains string b
*/