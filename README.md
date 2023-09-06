## Lexical Analyzer

This C program is a simple lexical analyzer designed to tokenize input strings and categorize them into various lexical elements such as operators, keywords, identifiers, integers, and real numbers.

### Features

- **Operator Recognition**: The program identifies common operators including `+`, `-`, `*`, `/`, `<`, `>`, and `=`.

- **Keyword Detection**: It recognizes keywords such as `if`, `else`, `while`, `do`, `break`, and many others commonly used in programming languages.

- **Integer Validation**: The program validates integers, ensuring they are correctly formatted and not containing invalid characters.

- **Real Number Validation**: It validates real numbers, checking for proper formatting, including the presence of a decimal point.

- **Identifier Verification**: The program verifies identifiers, making sure they start with a letter or underscore and don't contain invalid characters.

- **Delimeter Identification**: Delimiters like space, commas, semicolons, parentheses, brackets, and curly braces are recognized.

- **Output to File**: The program generates an output file named `output.txt`, where it records each token's type and value in a structured format.

### How to Use

1. Clone or download the code.

2. Compile the program using a C compiler (e.g., GCC) by running `gcc lexical_analyzer.c -o lexical_analyzer`.

3. Run the executable with an input string of your choice. Modify the `str` variable in the `main` function to use your desired input.

4. The program will create or append to `output.txt` with token information.

### Example

For instance, with the input string `int a = 2_2;`, the program will produce the following output in `output.txt`:

```
------------------------------------
|   'int'    |         KEYWORD       |
|   'a'      |  VALID IDENTIFIER     |
|   '='      |        OPERATOR        |
|   '2_2'    | NOT VALID IDENTIFIER  |
|   ';'      |        OPERATOR        |
------------------------------------
```

### Performance

The program also measures the time it takes to generate tokens using CPU time and reports it upon execution.

```
Time Used by CPU to Generate token is : [execution time] seconds
```

### Author

This Lexical Analyzer is authored by [Your Name].

### License

This project is open-source and available under the Lexical License. Feel free to use and modify it according to your needs.

---

