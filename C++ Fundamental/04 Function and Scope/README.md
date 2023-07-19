# Recap

## Vector
- Initilization
    ```C++
    vector<int> v = (1, 1);
    vector<int> v(1, 1);
    vector<int> v= {1, 1};
    ```
- Append a value: `v.push_back(val)`
- Insert value: `v.insert(v.begin() + 5, val);`

## Loop
- `break` and `continue`

    ```C++
    for (int i = 0; i < 10; i++) {
        cout << i << endl;
        if (true) {
            break;
            cout << i * 10 << endl;
        }
    }
    ```

## Practice problems
- Number Guessing Game: greater or smaller?
- Prime Numbers Generator: generate prime numbers up to n.


# Function
Basic syntax:
```C++
int myFunction(int argument) {
  // code to be executed
  return argument;
}
```

## What consist of function signiture:
- Function Name
- Return type
- Parameter list

## Default argument
```C++
int myFunction(int argument = 0) {
  // code to be executed
  return argument;
}
```

## Function overloading
- Same name, different parameter list.

## Recursive function
- The function calls it self.
- Write ending condition, then write your iteration.

# Scope
- Global variable, local variable.

# Homework

Use function to factor out your past assignment:
- Guessing number game
- Prime Numbers Generator
- Reverse a string

Recursive function:
- Fibonacci series: use recursive to implement this problem.
- Greatest common divisor (GCD): [Euclid's algorithm](https://www.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/the-euclidean-algorithm)
