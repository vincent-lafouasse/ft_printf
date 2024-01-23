# Notes

must handle:

c
s
p
d
i
u
x
X
%

`-O.`
`# +`

> If there are insufficient arguments for the format, the
> behavior is undefined. If the format is exhausted while
> arguments remain, the excess arguments are evaluated (as
> always) but are otherwise ignored.

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

