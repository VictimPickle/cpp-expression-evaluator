# Expression Evaluator & Variable Manager

A C++ expression evaluator that supports mathematical operations, logical comparisons, variable storage with dynamic typing, and type conversions.

## Features

### 🧮 Expression Evaluation
- **Arithmetic Operations**: Addition (`+`), subtraction (`-`), multiplication (`*`), division (`/`)
- **Comparison Operators**: `<`, `>`, `<=`, `>=`, `==`, `!=`
- **Logical Operators**: AND, OR operations
- **Parentheses Support**: Nested expressions with proper precedence
- **Negative Numbers**: Handles negative values in expressions

### 💾 Variable Management
- **Multiple Data Types**:
  - Integers (`int`)
  - Floating-point numbers (`double`)
  - Strings (`string`)
- **Dynamic Type Conversion**: Convert between int, double, and string types
- **Variable Assignment**: Store and retrieve values using single-character variable names

### 🔄 Type System
- **Type Checking**: Query variable types with `Type(x)` command
- **Type Conversion Functions**:
  - `Int(x)`: Convert variable to integer
  - `Double(x)`: Convert variable to double
  - `Str(x)`: Convert variable to string

### 📋 String Operations
- String storage and comparison
- String indexing with bracket notation `[n]`

## Installation

### Prerequisites
- C++ compiler with C++11 support or higher (g++, clang++, MSVC)
- Standard Template Library (STL)

### Compilation

```bash
g++ -std=c++11 main-1.cpp -o expression_evaluator
```

Or with optimization:

```bash
g++ -std=c++11 -O2 main-1.cpp -o expression_evaluator
```

## Usage

Run the compiled program:

```bash
./expression_evaluator
```

### Command Syntax

#### Variable Assignment

**Integer Assignment:**
```
a = 42
```

**Double Assignment:**
```
b = 3.14159
```

**String Assignment:**
```
name = "Hello World"
```

**Expression Assignment:**
```
result = (5 + 3) * 2 - 1
```

#### Type Operations

**Check Variable Type:**
```
Type(a)
```
Output: `int` or `double` or `string`

**Convert to Integer:**
```
Int(b)
```

**Convert to Double:**
```
Double(a)
```

**Convert to String:**
```
Str(a)
```

#### String Indexing

Access character at position `n` (0-indexed):
```
text = "Hello"
text[0]
```
Output: `H`

### Example Session

```
> a = 10
> b = 20
> c = a + b * 2
> c
50

> x = 3.14
> y = 2.5
> result = x * y
> result
7.85

> name = "Computer"
> name[0]
C

> Type(a)
int

> Double(a)
10
> Type(a)
double
```

## Supported Operations

### Arithmetic Operators
| Operator | Description | Example |
|----------|-------------|---------|
| `+` | Addition | `a + b` |
| `-` | Subtraction | `a - b` |
| `*` | Multiplication | `a * b` |
| `/` | Division | `a / b` |

### Comparison Operators
| Operator | Description | Example |
|----------|-------------|---------|
| `<` | Less than | `a < b` |
| `>` | Greater than | `a > b` |
| `<=` | Less than or equal | `a <= b` |
| `>=` | Greater than or equal | `a >= b` |
| `==` | Equal to | `a == b` |
| `!=` | Not equal to | `a != b` |

### Operator Precedence
1. Parentheses `()`
2. Multiplication `*`, Division `/`
3. Addition `+`, Subtraction `-`
4. Comparison operators `<`, `>`, `<=`, `>=`, `==`, `!=`

## Technical Details

### Data Structures
- **Variable Storage**: Three separate `std::map` containers for integers, doubles, and strings
- **Expression Parsing**: Stack-based evaluation using Shunting Yard algorithm
- **Type Management**: Dynamic type conversion with validation

### Implementation Highlights
- Uses STL containers (`map`, `stack`, `string`)
- Handles floating-point precision with `long double` for decimal parsing
- String comparison using `strcmp` for equality checks
- Operator precedence enforcement through stack operations

## Limitations

- Variable names are single characters only
- String literals must be enclosed in double quotes (`"`)
- No support for multi-line expressions
- Limited error handling for invalid syntax

## Project Structure

```
.
├── main-1.cpp           # Main source file
├── README.md            # This file
└── LICENSE              # License file (if applicable)
```

## Contributing

Contributions are welcome! Please feel free to submit pull requests or open issues for:
- Bug fixes
- New features
- Documentation improvements
- Performance optimizations

### Suggested Improvements
- [ ] Add multi-character variable names
- [ ] Implement better error messages
- [ ] Add support for more mathematical functions (sin, cos, sqrt, etc.)
- [ ] Create unit tests
- [ ] Add file input/output for batch processing
- [ ] Implement variable scoping

## License

[Specify your license here - MIT, GPL, Apache 2.0, etc.]

## Author

[Your name or GitHub username]

## Acknowledgments

This project implements:
- Shunting Yard algorithm for expression parsing
- Stack-based evaluation for postfix notation
- Dynamic type system for variable management

---

**Note**: This is an educational project demonstrating expression parsing and evaluation in C++.
