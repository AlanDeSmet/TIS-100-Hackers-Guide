Lua Style
==========

When writing [puzzles in Lua](lua.html), you may wish to mirror the style used by the official levels.

Input and Output Names
----------------------

Inputs always begin with "IN" and outputs always begin with "OUT".  If there is only one of an input or output, that is the entire name.  If there are more than one a single period followed by a single letter or digit is appended.  If the difference between the inputs are meaningless (for example, commutative operations like addition or multiplication), they are "A" and "B" (for example, "IN.A" and "IN.B"). Otherwise a single letter or digit is chosen as best represents the data. (for example, Q for Quotient, R for Remainder, 3 for the 3rd interrupt source, X or the X coordinate)

Description Phrasing
--------------------

The description can be up to 6 lines, each 33 characters long, with word wrapping.  These are phrases used in the official puzzles.

### Read (Input)

   * READ A VALUE FROM IN
   * READ A _COLOR_ VALUE FROM IN
       * also HEIGHT, LENGTH, WIDTH
   * READ INDEX VALUES FROM IN
   * READ AN X VALUE FROM IN
   * READ A Y VALUE FROM IN
   * READ A SEQUENCE FROM IN
   * READ FROM IN.1 THROUGH IN.4
   * READ VALUES FROM IN
   * READ VALUES FROM IN.A AND IN.B

### Write (Output)

   * WRITE 0 TO END THE SEQUENCES
   * WRITE 1 IF CHANGED BY 10 OR MORE
   * WRITE 1 TO OUT.X IF IN < 0
   * WRITE 1 WHEN PATTERN IS FOUND
   * WRITE IN.A - IN.B TO OUT
   * WRITE IN.A + IN.B WHEN IN.S = 0
   * WRITE IN.A WHEN IN.S = 1
   * WRITE INDEXED VALUE TO OUT
   * WRITE THE GREATER VALUE TO OUT
   * WRITE THE MAX VALUE TO OUT
   * WRITE THE INPUT NUMBER WHEN THE VALUE GOES FROM 0 TO 1
   * WRITE THE _LENGTH_ TO OUT
       * also PRODUCT, QUOTIENT, REMAINDER, SEQUENCE, SUM, and VALUE
   * WRITE THE SUM OF THE LAST 3 VALUES TO OUT.3 AND THE SUM OF THE LAST 5 VALUES TO OUT.5
   * IF NOT TRUE, WRITE 0 INSTEAD
   * WHEN A 1 IS NOT WRITTEN TO AN OUTPUT, WRITE A 0 INSTEAD

### Image Output

   * DRAW A LINE OF THAT LENGTH AND COLOR, WRAPPING WHEN THE EDGE OF THE IMAGE IS REACHED
   * DRAW A LINE THAT MANY UNITS LONG TO THE RIGHT OF THE PREVIOUS LINE DRAWN
   * DRAW A RECTANGLE OF THAT SIZE AT THE SPECIFIED LOCATION
   * FILL THE IMAGE BUFFER WITH THE SPECIFIED TARGET TEST PATTERN

### Read and Write

   * READ A VALUE FROM IN.A AND WRITE THE VALUE TO OUT.A

### Operations

   * DOUBLE THE VALUE
   * MULTIPLY THE VALUES
   * REVERSE THE SEQUENCE
   * SORT THE SEQUENCE
   * DIVIDE IN.A BY IN.B
   * COMPARE VALUE TO PREVIOUS VALUE
   * LOOK FOR THE PATTERN 1,5,4
   * LOOK UP INDEX VALUE IN SEQUENCE
 
### Assumptions

   * SEQUENCES ARE ZERO-TERMINATED
   * ASSUME PRIOR IN VALUES ARE 0
   * THE FIRST VALUE IS ALWAYS 0
   * TWO INTERRUPTS WILL NEVER CHANGE IN THE SAME INPUT CYCLE

This was inspired by [the work of bigalphillips on Reddit](https://www.reddit.com/r/tis100/comments/3a271m/contest_design_a_puzzle_for_the_upcoming_bonus/cscj1za)

