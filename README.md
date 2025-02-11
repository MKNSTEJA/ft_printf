# ft_printf

*Custom implementation of the C `printf` function for 42 School Projects.*

---

## Table of Contents
1. [Introduction](#introduction)
2. [Features](#features)
3. [Installation](#installation)
4. [Usage](#usage)
5. [Supported Conversions](#supported-conversions)
6. [Contributing](#contributing)
7. [License](#license)
8. [Acknowledgments](#acknowledgments)

---

## Introduction

**ft_printf** is a custom-built function that mimics the behavior of the standard C `printf` function. This project is part of the 42 School curriculum and provides valuable insights into variadic functions, formatted output, and memory management.

---

## Features

- **Standard Format Specifiers**: Supports `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, and `%`.
- **Precision and Width Handling**: Implements width and precision for formatted output.
- **Optimized for Performance**: Efficient handling of memory and formatted strings.
- **Error Handling**: Returns the number of printed characters, just like the standard `printf`.

---

## Installation

To use **ft_printf** in your project, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/MKNSTEJA/ft_printf.git
   ```

2. Navigate to the project directory:
   ```bash
   cd ft_printf
   ```

3. Compile the library:
   ```bash
   make
   ```

4. Include `ft_printf.h` in your project and link the compiled library:
   ```c
   #include "ft_printf.h"
   ```

5. Compile and link against `libftprintf.a`:
   ```bash
   gcc main.c libftprintf.a -o program
   ```

---

## Usage

Once compiled, `ft_printf` can be used similarly to `printf`:

```c
#include "ft_printf.h"

int main() {
    int printed_chars;
    printed_chars = ft_printf("Hello, %s! You have %d new messages.\n", "User", 5);
    ft_printf("Printed %d characters.\n", printed_chars);
    return 0;
}
```

Run the compiled program:
```bash
./program
```

---

## Supported Conversions

- **Character Output**: `%c` (Single character)
- **String Output**: `%s` (String)
- **Pointer Address**: `%p` (Memory address in hexadecimal)
- **Integer Output**: `%d` / `%i` (Signed decimal integer)
- **Unsigned Integer Output**: `%u` (Unsigned decimal integer)
- **Hexadecimal Output**: `%x` / `%X` (Lowercase and uppercase hexadecimal)
- **Literal Percent Sign**: `%%` (Prints a `%` symbol)

---

## Contributing

Contributions are welcome! Follow these steps to contribute:

1. Fork the repository.
2. Create a new branch:
   ```sh
   git checkout -b feature/your-feature-name
   ```
3. Commit your changes:
   ```sh
   git commit -m "Add feature or fix bug"
   ```
4. Push your changes:
   ```sh
   git push origin feature/your-feature-name
   ```
5. Open a pull request on GitHub.

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## Acknowledgments

- **42 School:** For providing the challenge to build this project.
- **Community:** For inspiration and support in improving the implementation.

---

## Author

**MKNSTEJA**

- GitHub: [MKNSTEJA](https://github.com/MKNSTEJA)
- Email: chessmaniacs123@gmail.com

Feel free to contribute, report issues, or suggest improvements!

