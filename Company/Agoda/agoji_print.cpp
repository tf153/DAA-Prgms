Agoji Print
 Flag Question
Agoda has its own line of emojis called Agojis, and because every Agodan loves Agojis, now everyone wants Agoji stickers! To fulfill this request, the People Team director wants to print N Agojis.

Agojis come in M unique styles, and for each style, there is a minimum A requirement and a maximum B requirement (A ≤ 0, B ≤ A) for printing.

In order to print the Agojis, you must calculate the number of distinct ways that $N$ Agojis can be printed, while satisfying the minimum and maximum requirement for each unique style of Agoji. Since the answer could be a very large number, please calculate your answer using mod 1e9+7.

Input Format
The first line contains two integers, N and M (total Agojis and types of Agojis).

The second line (M) contains two integers, $A$ and $B$ (minimum and maximum requirements of $0 \lt A \le B \le N$ for Agojis of $i^{th}$ type in $i^{th}$ line).

Constraints:
$1\le N \le 1e6$

$1\le M\le 16$

$0\lt A \le B \le N$

Output Format
A single integer (using mod $1e9+7$) that represents the number of distinct ways the Agojis can be printed.

Sample Input
Sample 1
9 3
2 4
2 4
2 4
Sample 2
6 2
3 3
3 3
Sample 3
4 2
3 4
2 4
Sample Output
Sample 1

7

Sample 2

1

Sample 3

0

Explanation of Sample Output:
In the first test case, the requirement is to print 9 Agojis from three types of Agojis. Let's say these Agojis are as follows:

  ;)  :)  ;(

For each Agoji, the minimum requirement is 2 and the maximum requirement is 4, so we can print them in the following combinations:

2 + 3 + 4

2 + 4 + 3

3 + 2 + 4

3 + 3 + 3

3 + 4 + 2

4 + 2 + 3

4 + 3 + 2

Now, we can see there are 7 ways in total to print the Agojis.