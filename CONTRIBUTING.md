# Contributing to Expression Evaluator

First off, thank you for considering contributing to this project! It's people like you that make this expression evaluator a great tool.

## How Can I Contribute?

### Reporting Bugs

Before creating bug reports, please check the existing issues to see if the problem has already been reported. When you create a bug report, include as many details as possible:

* **Use a clear and descriptive title**
* **Describe the exact steps to reproduce the problem**
* **Provide specific examples** (input expressions that cause issues)
* **Describe the behavior you observed and what you expected**
* **Include your compilation environment** (compiler version, OS)

### Suggesting Enhancements

Enhancement suggestions are tracked as GitHub issues. When creating an enhancement suggestion, include:

* **Use a clear and descriptive title**
* **Provide a detailed description of the suggested enhancement**
* **Explain why this enhancement would be useful**
* **List any examples of how it would work**

### Pull Requests

* Fill in the required template
* Follow the C++ coding style used in the project
* Include comments for complex logic
* Test your changes thoroughly
* Update documentation as needed

## Development Setup

1. **Fork the repository**
2. **Clone your fork**
   ```bash
   git clone https://github.com/your-username/expression-evaluator.git
   cd expression-evaluator
   ```

3. **Create a branch**
   ```bash
   git checkout -b feature/your-feature-name
   ```

4. **Make your changes and commit**
   ```bash
   git add .
   git commit -m "Add descriptive commit message"
   ```

5. **Push to your fork**
   ```bash
   git push origin feature/your-feature-name
   ```

6. **Create a Pull Request**

## Coding Standards

### C++ Style Guidelines

* Use meaningful variable and function names
* Follow consistent indentation (4 spaces)
* Add comments for complex algorithms
* Keep functions focused and concise
* Use STL containers and algorithms where appropriate

### Example:

```cpp
// Good
double calculateAverage(const vector<double>& values) {
    if (values.empty()) return 0.0;
    double sum = 0.0;
    for (const auto& value : values) {
        sum += value;
    }
    return sum / values.size();
}

// Avoid
double calc(vector<double> v) {
    double s=0;
    for(int i=0;i<v.size();i++)s+=v[i];
    return s/v.size();
}
```

## Testing

Before submitting a pull request:

1. **Compile with no warnings**
   ```bash
   g++ -std=c++11 -Wall -Wextra main-1.cpp -o expression_evaluator
   ```

2. **Test basic functionality**
   * Variable assignments (int, double, string)
   * Arithmetic operations
   * Comparison operations
   * Type conversions
   * Edge cases (division by zero, empty strings, etc.)

3. **Document any new features** in the README

## Priority Areas for Contribution

We especially welcome contributions in these areas:

1. **Error Handling**: Better error messages and input validation
2. **Testing**: Unit tests and test framework integration
3. **Features**: 
   - Multi-character variable names
   - Mathematical functions (sin, cos, sqrt, etc.)
   - File I/O for batch processing
   - Command history
4. **Documentation**: Usage examples, tutorials, API documentation
5. **Performance**: Optimization of expression parsing

## Questions?

Feel free to open an issue with your question or reach out to the maintainers.

## Code of Conduct

This project adheres to a Code of Conduct. By participating, you are expected to uphold this code. Please report unacceptable behavior to [INSERT CONTACT].

## License

By contributing, you agree that your contributions will be licensed under the same license as the project (MIT License).

---

Thank you for contributing! 🎉
