Graphics Display
================

The "visualization module" or `[STREAM_IMAGE](lua.html)` is an output stream that is interpreted as drawing commands.  In puzzles the display is 30 pixels wide by 18 pixels tall.  In the `IMAGE CONSOLE SANDBOX` the display is 36 pixels wide by 22 pixels tall.  The display is indexed from 0, with 0,0 being the upper left corner and 29,17 being the bottom right for a puzzle display.

The display is capable of displaying 5 different colors:

<table>
<tr><th>Value</th><th colspan="3">Color</th></tr>
<tr><td style="text-align:center">0</td><td style="width: 1em; background-color: black">&nbsp;</td><td>Black</td><td>#000000</td></tr>
<tr><td style="text-align:center">1</td><td style="width: 1em; background-color: #464646">&nbsp;</td><td>Dark Grey</td><td>#464646</td></tr>
<tr><td style="text-align:center">2</td><td style="width: 1em; background-color: #9c9c9c">&nbsp;</td><td>Light Grey</td><td>#9c9c9c</td></tr>
<tr><td style="text-align:center">3</td><td style="width: 1em; background-color: #fafafa">&nbsp;</td><td>White</td><td>#fafafa</td></tr>
<tr><td style="text-align:center">4</td><td style="width: 1em; background-color: #c00b0b">&nbsp;</td><td>Red</td><td>#c00b0b</td></tr>
</table>

Output must consist of:

1. An X coordinate
2. A Y coordinate
3. Zero or more pixel colors, 0-4
4. Any negative value as a terminator

The pixel colors will be drawn starting at the X,Y coordinate and moving right. TODOCONFIRM: If there are enough entries to exceed the maximum X value (29 or 35), the extra values are discarded. (This behavior is not guaranteed)

TODOCONFIRM: If the X or Y coordinates out outside of the display, the values are discarded. TODO: What if you start negative X but eventually arrive into valid X?
Pixels are drawn as soon as the respective color arrives in the output stream.  They do _not_ wait until the terminator arrives.

Colors with values in excess of 4 are treated as "0".  Negative color values are not possible, as that indicates the terminator.

A negative X or Y coordinate is treated as a terminator; nothing is drawn and the next digit is expected to be an X coordinate.

Colors drawn beyond the maximum X or Y coordinate, either by explicitly addressing the point or by specifying enough pixel colors to travel beyond the maximum X,  are ignored.
