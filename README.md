# Assignments 2
## by Kfir Goldfarb

This assignment have two parts:
### Part 1 (isort):
1. shift_element function - by given a pointer to a integers array and an i (index), move from the index place in the array every int to next index, for example:
if we have an array:
```
[1,2,3,4,5,6,7,8]
```
and an index of i = 3
we get:
```
[1,2,3,4,4,5,6,7]
```

2. insertion_sort function - implements insertion sort algorithm by given integers array and the length of the array, for example:
if we have an array:
```
[8,7,6,5,4,3,2,1]
```

we get:
```
[1,2,3,4,5,6,7,8]
```

### Part 2 (textfind):
by given a text file in this format:
```
<key_word> <option_char(a or b)>

<file text>
```

the program will get the first line and take <key_word> as the word to search in the text, and the <option_char> as the char that can be 'a' or 'b',
1. by choose 'a' option the program will print all the lines that the word can be found in.
2. by choose 'b' option the program will print all the words in the text that the word can be found in to the point of omitting one letter from the word.

for example:
if we have the text file:
```
cat a

this is a text file
looking for the word cat
the program should print also cats
after cats crat and lcat are printed
the program shouldn’t print
the word caats
```

the program will print:
```
looking for the word cat
the program should print also cats
after cats crat and lcat are printed
```

and if we have the text file:
```
cat b

this is a text file
looking for the word cat
the program should print also cats
after cats crat and lcat are printed
the program shouldn’t print
the word caats
```
the program will print:
```
cat
cats
cats
crat
lcat
```