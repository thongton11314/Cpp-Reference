Programming, Review structs, arrays, functions, etc. (not object-oriented)
You are given names, last name then first name (each at most 30 characters long), and one integer (represents grade). You
expect no more than 100 records. Sort these using an insertion sort (sorted by last name, then by first name when the last
names are the same) and display. Also display a histogram and class average (using integer arithmetic).

SAMPLE INPUT: SAMPLE OUTPUT (yours must be identical, space for space):
frog freddie 60 		List of names sorted:
duck donald 65 			65 duck donald
mouse minnie 95 		60 frog freddie
mouse mickey 73 		71 ghost casper
error check -10 		85 mouse abby
error check 101 		73 mouse mickey
ghost casper 71 		95 mouse minnie
mouse abby 85

Histogram of grades:
0--> 9:
10--> 19:
20--> 29:
30--> 39:
40--> 49:
50--> 59:
60--> 69: **
70--> 79: **
80--> 89: *
90--> 99: *
100--> 100: