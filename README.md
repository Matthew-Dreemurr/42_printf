# Printf implementation.


## Special characters.

| Escape Sequence | Represents |
| ------------- |:-------------|
| `\a` | Bell (alert) |
| `\b` | Backspace |
| `\c` | Form feed |
| `\e` | New line |
| `\f` |  |
| `\n` |  |
| `\r` | Carriage return |
| `\t` | Horizontal tab |
| `\v` | Vertical tab |
| `\\` |  |
| `\'` | Single quotation mark |
| `\"` | Double quotation mark |
| `\?` | Literal question mark |
| `%%` | Printf `%` |
| `\NNN` | ASCII character in octal notation |
| `\xHH` | ASCII character in hexadecimal notation |
| `\uHHHH` | Unicode (ISO/IEC 10646) character with hex value HHHH (4 digits) |

## Convertions.

| Type character | Output |
| ------------- |:-------------|
| `%c` | Print a singlecharacter |
| `%s` | Print astring of characters |
| `%p` | Print the argument as an address in hexadecimal digits. |
| `%d` | Print adecimal (base 10) number |
| `%i` | print aninteger in base 10 |
| `%u` | print anunsigned decimal (base 10) number |
| `%x` | Unsigned hexadecimal integer; uses `abcdef` |
| `%X` | Unsigned hexadecimal integer; uses `ABCDEF` |
| `%%` | Printf `%` |

| **Bonus** |  |
| ------------- |:-------------|
| `n` |  |
| `f` |  |
| `g` |  |
| `e` |  |

# Flags.

| Flag | Meaning |
| ------------- |:-------------|
| `-` | Left align the result within the given field width |
| `0` | Shorter numbers are padded out with leading zeros |
| `.` | How many placesshould be shown after the decimal point |
| `*` | `an int width argument must precede the value that's being formatted in the argument list, exemple printf("%0*d", 5, 3); /* 00003 is output */` |