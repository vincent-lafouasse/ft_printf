# Notes

must handle:

- c
- s
- p
- d, i int
- u, X, x unsigned int
- %

`-O.`
`# +`

> 2 If there are insufficient arguments for the format, the behavior is
> undefined. If the format is exhausted while arguments remain, the excess
> arguments are evaluated (as always) but are otherwise ignored.

> 9 If a conversion specification is invalid, the behavior is undefined.239) If
> any argument is not the correct type for the corresponding conversion
> specification, the behavior is undefined.

sequence:

- Zero or more flags (in any order)
- An optional minimum field width. If the converted value has fewer characters
  than the field width, it is padded with spaces (by default) on the left (or
  right, if the left adjustment flag, described later, has been given) to the
  field width. The field width takes the form of an asterisk * (described
  later) or a decimal integer
- An optional precision that gives the minimum number of digits to appear for
  the d, i, o, u, x, and X conversions, or the maximum number of bytes to be
  written for s conversions. The precision takes the form of a period (.)
  followed either by an asterisk * (described later) or by an optional decimal
  integer; if only the period is specified, the precision is taken as zero. If
  a precision appears with any other conversion specifier, the behavior is
  undefined.
- (An optional length modifier that specifies the size of the argument. eg zu)
- A conversion specifier character that specifies the type of conversion to be
  applied.


> 14 The fprintf function returns the number of characters transmitted, or a
> negative value if an output or encoding error occurred.
