# Topics

## `while` loop

```C++
while (condition) {
    // code block to be executed
}
```

## `do-while` loop

```C++
do {
    // code block to be executed
} while (condition);
```

## `for` loop

```C++
for (statement_1; statement_2; statement_3) {
    // code block to be executed
}
```

- Interchangeable with `while` loop

```C++
statement_1;
while (statement_2) {
    // code block to be executed
    statement_3;
}
```

## `break` and `continue`

- Output all numbers until 5 (`break`)
- Output all numbers except 5 (`continue`)

## Array `std::vector<>`

- Think about `string` is an array of `char`.

```C++
std::vector<int> v1 = {1, 2, 3};
std::vector<int> v2(5, 0);

v1.size();
v1.at(0);
v1[0] = 4;


```

- Foreach loop

  ```C++
  for (int i : v) {
  }
  ```

- 2 Dimention array
`std::vector<std::vector<int>>`

## Struct
```C++
struct TypeName {
    int age;
    string name;
};
```

## Kahoot: 
- https://create.kahoot.it/details/946ba446-05be-4d6e-bdfa-8387a388e6bc

## Homework
- **Fibonacci series:** Create a program to print the first n numbers in the Fibonacci series using loops.
  - Create a program to print the Fibonacci series until n.
- **Number Guessing Game:** greater or smaller?
- **Prime Numbers Generator:** generate prime numbers up to n.
- **Reverse a string**
- **Palindrome Checker**
- **Bubble Sort**




