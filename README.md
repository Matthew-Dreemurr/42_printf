# Printf implementation


## Convertions

| Type character | Output | s_data |
|-|:-|:-|
| `%c` | Print a singlecharacter | `c` |
| `%s` | Print astring of characters | `s` |
| `%p` | Print the argument as an address in hexadecimal digits. | `p` |
| `%d` | Print adecimal (base 10) number | `d` |
| `%i` | print aninteger in base 10 | `i` |
| `%u` | print anunsigned decimal (base 10) number | `u` |
| `%x` | Unsigned hexadecimal integer; uses `abcdef` | `x` |
| `%X` | Unsigned hexadecimal integer; uses `ABCDEF` | `x_up` |
| `%%` | Print `%` | `mod` |

| **Bonus** |  | |
|-|:-|:-|
| `%n` | Is a special format specifier which load the variable pointed with a value equal to the number of characters before the occurrence of %n| |
| `%f` | Print afloating-point number | |
| `%g` | Print ageneral-format floating-point number | |
| `%e` | Print anexponential floating-point number | |

# Flags

| Flag | Meaning |  |
|-|:-|:-|
| `%-` | Left align the result within the given field width | `min` |
| `%0` | Shorter numbers are padded out with leading zeros | `zero` |
| `%.` | How many placesshould be shown after the decimal point | `prec` |
| `%*` | an int width argument must precede the value that's being formatted in the argument list, exemple `printf("%0*d", 5, 3);` /* 00003 is output */ | `arg` |

| **Bonus** |  |
| ------------- |:-------------|
| `%#` | When it's used with the `o`, `x`, or `X` format, the `#` flag uses `0`, `0x`, or `0X`, respectively, to prefix any nonzero output value |
| `% ` | Use a blank to prefix the output value if it's signed and positive. The blank is ignored if both the blank and + flags appear |
| `%+` | Use a sign (`+` or `-`) to prefix the output value if it's of a signed type. |

### Sources

Secrets of “printf” Professor Don Colton
  https://www.cypress.com/file/54441/download

https://docs.microsoft.com/en-us/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-160

https://en.wikipedia.org/wiki/Escape_sequences_in_C
