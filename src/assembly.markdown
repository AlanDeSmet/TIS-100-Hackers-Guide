Assembly
========

Overall Node Behavior
---------------------

Nodes are evaluted starting at the upper left, moving left to right, and advancing down one row and returning to the left edge upon reaching the end of a row.  The behavior impacts using `ANY` as a destination.


Comments
--------

The character # and any characters after it on a line are ignored.  Comments may follow a label or opcode and arguments.



Labels
------

A labelif present, must be the first thing on the line. It is terminated with a : which must be immediately adjacent to the label. Valid characters for labels are the letters A through Z, the digits 0 through 9, and the punctuation in the set of ~`$%^&*()_-+={}[]|\;'"<>,.?/ . There are no limitations on which characters may be in which positions of the label. A line may only have a single label.  A label must have at least one character before the colon. Labels may be up to 18 characters long, but the longest addressable label is 14 characters. 



Storage
-------

**`ACC`** - Accumulator. Register.  Can be used as a _source_ or _destination_. Initialized to 0.  Reads and writes are instantaneous.

**`BAK`** - Backup. Register.  Only `SAV` and `SWP` interact with `BAK`.  The identifier “`BAK`” is never a valid identifier in a program.

**`NIL`** - Nothing. Register. Can be used as a _source_, in which case “0” is returned.  Can be used as a _destination_, which which case the value is discarded.

**`UP`**, **`DOWN`**, **`LEFT`**, **`RIGHT`** - Connections to adjacent nodes. Ports.  Can be used as a _source_ or a _destination_.  When used as a destination, the value cannot be read by the adjacent node in the same cycle that it was written to.  Blocks until a _destination_ value is used as a _source_ by the adjacent node or a _source_ is used as a _destination_ by an adjacent node.

**`ANY`** - Port. Can be used as a _source_, in which case the value will be read from the first port with a waiting value, as searched in the order LEFT, RIGHT, UP, DOWN.  Can be used as a _destination_, in which case the value is available to all ports; it will be cleared from all ports as soon as any adjacent node reads it.  Assuming all adjacent points try to read simulataneously, the winner will be selected in the order UP, LEFT, RIGHT, and DOWN.

**`LAST`** - Port. Refers to the same port used by the last reference to `ANY`, either in read or write.

_source_ can be ACC, NIL, UP, DOWN, LEFT, RIGHT, ANY, LAST, or an integer from −999 through 999, inclusive.  If the value is an integer, it is used directory.  Otherwise the register or port is read for the value to use.

_destination_ can be ACC, NIL, UP, DOWN, LEFT, RIGHT, ANY, or LAST.


Opcodes
-------

### NOP - No Operation - 1 cycle

**Syntax:** `NOP`

Does nothing.



### MOV - Move - 1-2 cycles

**Syntax:** `MOV` _source_ _destination_

Reads a value from _source_ and write it to _destination_.  If _source_ is a port, blocks until a value is present.  If _destination_ is a port, blocks until the value is received.

1 cycle when writing ACC or NIL.

2 cycles when writing to UP, DOWN, LEFT, or RIGHT, assuming the neighboring node is willing to retrieve the value on the second cycle.  The data is not yet in the port until the end of the first cycle.  This prevents a single value from travelling multiple nodes in a single cycle.



### SWP - Swap - 1 cycle

**Syntax:** `SWP`

Swaps the values of ACC and BAK



### SAV - Save - 1 cycle

**Syntax:** `SAV`

Copies the value of ACC to BAK



### ADD - Add - 1 cycle

**Syntax:** `ADD` _source_

The _source_ value is added to the value in ACC, and the result placed in ACC. Results greater than 999 are limited to 999.  Results less than −999 are limited to −999.



### SUB - Subtract - 1 cycle

**Syntax:** `SUB` _source_

The _source_ value is subtracted to the value in ACC, and the result placed in ACC. Results greater than 999 are limited to 999.  Results less than −999 are limited to −999.



### NEG - Negate - 1 cycle

**Syntax:** `NEG` _source_

The value in ACC is negative (swapped between positive and negative) and written back into ACC.  0 is left unchanged.



### JMP - Jump - 1 cycle

**Syntax:** `JMP` _label_

Transfer execution to the first instruction after _label_.



### JEZ - Jump if equal to zero - 1 cycle

**Syntax:** `JEZ` _label_

If the ACC is 0, transfer execution to the first instruction after _label_.



### JNZ - Jump if not equal to zero - 1 cycle

**Syntax:** `JNZ` _label_

If the ACC is not 0, transfer execution to the first instruction after _label_.



### JGZ - Jump if greater than zero - 1 cycle

**Syntax:** `JGZ` _label_

If the ACC is greater than 0, transfer execution to the first instruction after _label_.



### JLZ - Jump if less than zero - 1 cycle

**Syntax:** `JLZ` _label_

If the ACC is greater than 0, transfer execution to the first instruction after _label_.



### JRO - Jump relative offset - 1 cycle

**Syntax:** `JRO` _source_

Transfer execution to the offset specified by _source_.  Offset is measured in instructions. Negative offsets can be used to move jump backward, positive offsets to jump forward, or 0 to execute the JRO instruction again.

