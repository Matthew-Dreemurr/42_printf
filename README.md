# Printf implementation `V2`
# Todo, make a log for norm /w norminette src 2>&1 | grep "Error\!"
| Todo for V2 |
|-|
| Meilleur gestion de la Output Conversion Syntax|
| Refaire la logique du parseur avec cette [doc](https://www.gnu.org/software/libc/manual/html_node/Output-Conversion-Syntax.html)|

## Convertions

| Type character | WIP | Output |
|:-|:-|:-|
| `%c` | ✅ | Print a singlecharacter |
| `%s` | ✅ | Print astring of characters |
| `%p` | ✅ | Print the argument as an address in hexadecimal digits. |
| `%d` | ✅ | Print a decimal (base 10) number |
| `%i` | ✅ | print an integer in base 10 |
| `%u` | ❌ | print an unsigned decimal (base 10) number |
| `%x` | ✅ | Unsigned hexadecimal integer; uses `abcdef` |
| `%X` | ✅ | Unsigned hexadecimal integer; uses `ABCDEF` |
| `%%` | ✅ | Print `%` |

| **Bonus** |  |
|-|:-|
| `%n` | Is a special format specifier which load the variable pointed with a value equal to the number of characters before the occurrence of %n|
| `%f` | Print afloating-point number |
| `%g` | Print ageneral-format floating-point number |
| `%e` | Print anexponential floating-point number |

# Flags

| Flag | s_data | WIP | Meaning |
|-|:-|:-|-|
| `%-` | `min`  | 🔧 | Left align the result within the given field width |
| `%0` | `zero` | 🔧 | Shorter numbers are padded out with leading zeros |
| `%.` | `dot` | 🔧 | How many placesshould be shown after the decimal point |
| `%*` | `arg`  | ✅ | an int width argument must precede the value that's being formatted in the argument list, exemple `printf("%0*d", 5, 3);` `00003 is output` |

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
