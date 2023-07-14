# Recap

- Primitive data types: `short`, `int`, `long`, `unsigned int`, `long long`, `float`, `double`, `char`, `bool`
- Input and output: `cin >> x;`, `cout << ??`
- Process-oriented programming: enter from `main()` function, and execute line by line.

**Question:** What is the result for the following code:
```C++
bool b = true;
cout << b;
```

```C++
int c = 96;
cout << c;
```

```C++
char c = 96;
cout << c;
```

# Today's Topics

- Variables
- Constants

- One more type: `std::string`
  - Not primitive type.
  - `#include <string>`
  - Concatenation: `s1 + s2`, `s1.append(s2)`
  - Length: `s.size()` or `s.length()`
  - Access: `s[1]`
  - Substring: `s.substr(from, len)`
  - Escape character: `'\"'`, `'\t'`, `'\n'`, `'\\'`

- basic arithmetic operators
  - Addition: `+` (overflow)
  - Subtraction: `-` (overflow)
  - Multiplication: `*` (overflow)
  - Division: `/` (integer to float)
  - Remainder / Modulus: `%` (negative)
  - Increment: `++` (`i++` vs. `++i`, pre-inc and post-inc)
  - Decrement: `--`
  - Combining with assignment: `+=`, `-=`, `*=`, `/=`, `%=`

- Comparation:
  - Less than: `a < b`
  - Less than or equal to: `a <= b`
  - Greater than: `a > b`
  - Greater than or equal to: `a >= b`
  - Equal to `a == b` (This is different from assignment!)
  - Not Equal to: `a != b`

- Logic:
  - And: `&&`
  - Or: `||`
  - Not: `!`
  - Exclusive (XOR): `^` True when not the same.

- Branching:
  ```C++
  if (condition_1) {

  } else if (condition_2) {

  } else {

  }
  ```

  ```C++
  switch (expression) {
      case a:
          break;
      case b:
          break;
      case c:
          break;
      default:
  }
  ```

    - `variable = (condition) ? expressionTrue : expressionFalse;`

  # Assignment:
  - Write a program that asks the user for two numbers and then tells the user which number is larger or if they are equal.
  - Write a program that asks the user for their age and whether they are a citizen (yes or no). The program should then tell the user whether they are eligible to vote. (In most places, you have to be at least 18 and a citizen to vote.)
  - Write a program that asks the user to enter a number. The program should then output whether the number is positive, negative, or zero, and whether it's even or odd.
  - **Extra:** Write a program to simulate a simple calculator. The program should ask the user for two numbers, and an operation to perform on them. The operations are: `+ - * / %`, and try to handle error for invalid input.