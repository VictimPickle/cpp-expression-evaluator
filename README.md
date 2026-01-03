# C++ Expression Evaluator

A robust C++ expression evaluator with support for dynamic typing, variable management, and advanced mathematical operations.

## Features

- Dynamic type system supporting multiple data types
- Variable storage and manipulation with assignment operators
- Support for mathematical operations (+, -, *, /, ^, modulo, etc.)
- Safe error handling and input validation
- Efficient expression parsing with proper operator precedence
- Function evaluation capabilities

## Compilation

```bash
g++ -std=c++17 -O2 expression_evaluator.cpp -o evaluator
```

Or using GCC with optimizations:
```bash
g++ -Wall -Wextra -std=c++17 -O3 expression_evaluator.cpp -o evaluator
```

## Usage

Run the compiled executable:
```bash
./evaluator
```

Then enter expressions at the prompt.

## Examples

```
Input: 2 + 3 * 4
Output: 14

Input: x = 5
Output: 5

Input: x * 2 + 3
Output: 13

Input: (10 + 5) / 3
Output: 5
```

## Supported Operations

| Operator | Description | Example |
|---|---|---|
| `+` | Addition | `5 + 3` = 8 |
| `-` | Subtraction | `5 - 3` = 2 |
| `*` | Multiplication | `5 * 3` = 15 |
| `/` | Division | `15 / 3` = 5 |
| `^` | Exponentiation | `2 ^ 3` = 8 |
| `%` | Modulo | `10 % 3` = 1 |
| `=` | Assignment | `x = 10` |

## Architecture

The evaluator uses:
- Lexical analysis for tokenization
- Recursive descent parsing for syntax analysis
- Symbol table for variable storage
- Stack-based evaluation for efficiency

## Technology Stack

- **Language**: C++17
- **Standard Library**: Yes
- **Dependencies**: None (header-only)

## Complexity Analysis

- **Time Complexity**: O(n) for parsing and evaluation, where n is expression length
- **Space Complexity**: O(m) for m variables stored

## License

MIT License - see LICENSE file for details

## Author

Mobin Ghorbani