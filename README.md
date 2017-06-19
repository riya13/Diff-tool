# Diff-tool

This is an implementation of the basic greedy diff algorithm, as described by Eugene W. Myers in his paper, "An O(ND) Difference Algorithm and Its Variations". It was published in the journal "Algorithmica" in November 1986. 

In his paper, Myers also extends his basic algorithm with the "Linear Space Refinement".

<b> DEFINITIONS </b>

File A and File B

The diff algorithm takes two files as input. The first, usually older, one is file A, and the second one is file B. The algorithm generates instructions to turn file A into file B.

Shortest Edit Script ( SES )

The algorithm finds the Shortest Edit Script that converts file A into file B. The SES contains only two types of commands: deletions from file A and insertions in file B.

Longest Common Subsequence ( LCS )

Finding the SES is equivalent to finding the Longest Common Subsequence of the two files. The LCS is the longest list of characters that can be generated from both files by removing some characters. The LCS is distinct from the Longest Common Substring, which has to be contiguous.

For any two files, there can be multiple LCSs. For example, given the sequences "ABC" and "ACB", there are two LCSs of length 2: "AB" and "AC". An LCS corresponds directly to an SES, so it is also true that there can be multiple SESs of the same length for any two files. The algorithm just returns the first LCS / SES that it finds, which therefore may not be unique.

Snakes

Snake is defined as a single deletion or insertion followed by zero or more diagonals.

For the example, there are two snakes starting at the top-left ( 0, 0 ). One goes right to ( 1, 0 ) and stops. The other goes down to ( 0, 1 ) and stops. The next snake down from ( 0, 1 ) goes to ( 0, 2 ) and then along the diagonal to ( 2, 4 ). I call these points the start, mid, and end points, respectively.

k lines

You can draw lines starting at points on the x-axis and y-axis and parallel to the diagonals. These are called k lines and will be very useful. The line starting at ( 0, 0 ) is defined to be k = 0. k increases in lines to the right and decreases downwards. So the k line through ( 1, 0 ) has k = 1, and the k line through ( 0, 1 ) has k = -1.

In fact, they are the lines represented by the equation: y = x - k. This is also useful, because we only need to store the x value for a particular point on a given k line and we can simply calculate the y value.

d contours

A difference is shown by a horizontal or vertical move in the edit graph. A contiguous series of snakes has a d value which is the number of differences in that trace, irrespective of the number of diagonals in it. A d contour can be created that joins the end points of all traces with a given d value.
