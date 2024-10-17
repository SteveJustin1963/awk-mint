# awk-forth

### AWK

AWK is a powerful text processing tool available on Linux (and other Unix-like systems). It allows you to manipulate and analyze text, especially structured data such as columns in a file. AWK operates on files, reading them line by line and applying user-defined patterns and actions. It’s ideal for tasks such as extracting fields, processing data, and generating reports.

### Key Features of AWK:
1. **Pattern Matching**: AWK allows you to specify patterns (regular expressions or specific strings) to match lines in a file.
   
2. **Field-based Processing**: AWK treats each line as a set of fields (columns) separated by a delimiter (default is whitespace). You can easily extract and manipulate these fields.
   - `$1`, `$2`, etc., represent the first, second, etc., fields of the current line.
   - `$0` represents the entire current line.

3. **Built-in Variables**:
   - `NR`: The current record (line) number.
   - `NF`: The number of fields in the current line.
   - `FS`: The field separator (default is space or tab).
   - `OFS`: The output field separator (default is space).
   - `RS`: The record separator (default is newline).

4. **Actions**: You define what actions to perform when a line matches a pattern. These actions can include printing, calculations, text replacement, or even writing to files.

5. **Control Structures**: AWK supports loops, conditionals, and functions, making it very flexible for advanced data manipulation.

### Basic Structure of AWK:
The basic syntax of an AWK program looks like this:

```bash
awk 'pattern { action }' input_file
```

- **pattern**: A condition that decides whether the action is applied to a line (if omitted, it applies to all lines).
- **action**: The operations to be performed on lines that match the pattern (if omitted, the default action is to print the line).

### Common Use Cases:

1. **Print specific columns**:
   ```bash
   awk '{ print $1, $3 }' file.txt
   ```
   This prints the first and third columns of each line from `file.txt`.

2. **Pattern Matching**:
   ```bash
   awk '/error/ { print $0 }' logfile.txt
   ```
   This prints all lines containing the word "error" from `logfile.txt`.

3. **Performing Calculations**:
   ```bash
   awk '{ sum += $2 } END { print "Total:", sum }' sales.txt
   ```
   This sums the values in the second column of `sales.txt` and prints the total at the end.

4. **Conditional Execution**:
   ```bash
   awk '$3 > 100 { print $1, $3 }' data.txt
   ```
   This prints the first and third fields for lines where the third field is greater than 100.

### Advanced Features:
- **User-defined functions**: You can write your own functions within AWK scripts.
- **Regular expressions**: AWK can match complex patterns using regular expressions.
- **Field and Record Separators**: You can specify custom field (FS) and record (RS) separators to process data formats like CSV.

### Example: AWK Script for Processing CSV
```bash
awk -F',' '{ print $1, $2 }' data.csv
```
This reads `data.csv` with a comma (`,`) as the field separator and prints the first two columns.

### AWK I/O in Linux:
- **Input**: AWK reads data from files, standard input (stdin), or pipelines.
- **Output**: AWK writes data to standard output (stdout) or files.
- **Redirection**: AWK supports I/O redirection, allowing you to write output to files or read input from multiple sources.

Example:
```bash
awk '/pattern/ { print $1 > "output.txt" }' input.txt
```
This redirects the first field of lines matching "pattern" into `output.txt`.

AWK is widely used for quick and effective text manipulation tasks in system administration, data analysis, and report generation.

### more
AWK is a powerful text-processing tool in Unix/Linux that allows users to extract, manipulate, and generate data. It is widely used for pattern scanning, report generation, and field-based processing of text files. Below is a list of AWK's core features:

### 1. **Field and Record Processing**:
   - **Fields**: AWK automatically splits each line of input into fields based on a field separator (default is whitespace). Fields are accessed using `$1`, `$2`, ..., `$NF` where `NF` is the number of fields in the current record.
   - **Records**: Each line of input is treated as a record. You can change the record separator using `RS`.

   **Example**:
   ```bash
   awk '{ print $1, $3 }' file.txt  # Prints first and third fields of each line
   ```

### 2. **Pattern Matching**:
   - AWK allows you to apply actions to lines (records) that match a specific pattern. These patterns can be regular expressions or simple conditions.

   **Example**:
   ```bash
   awk '/error/ { print $0 }' file.txt  # Prints lines containing the word "error"
   ```

### 3. **Arithmetic Operations**:
   - AWK supports arithmetic operations such as addition, subtraction, multiplication, division, and modulus.

   **Example**:
   ```bash
   awk '{ sum += $2 } END { print sum }' file.txt  # Sums values in the second column
   ```

### 4. **Built-in Variables**:
   AWK provides several built-in variables to help with processing:
   - **NR**: Current record (line) number.
   - **NF**: Number of fields in the current record.
   - **FS**: Field separator (default is whitespace).
   - **OFS**: Output field separator (default is space).
   - **RS**: Record separator (default is newline).
   - **ORS**: Output record separator (default is newline).

   **Example**:
   ```bash
   awk '{ print NR, NF }' file.txt  # Prints the record number and number of fields for each line
   ```

### 5. **User-defined Variables**:
   - You can define and use your own variables within an AWK script. These can be used to store values, counters, or results for later use.

   **Example**:
   ```bash
   awk '{ count += 1; total += $2 } END { print "Count:", count, "Total:", total }' file.txt
   ```

### 6. **String Operations**:
   - AWK supports various string manipulation functions such as `length()`, `substr()`, `index()`, `split()`, and `toupper()`/`tolower()`.

   **Example**:
   ```bash
   awk '{ print length($0) }' file.txt  # Prints the length of each line
   ```

### 7. **Control Structures**:
   AWK includes conditional and looping constructs such as `if`, `else`, `while`, `for`, `do-while`, and `break/continue`.

   **Example**:
   ```bash
   awk '{ if ($1 > 100) print $1 }' file.txt  # Prints first field if it's greater than 100
   ```

### 8. **Formatted Printing**:
   - AWK allows formatted output similar to `printf` in C. You can specify the format of numbers, strings, and spacing.

   **Example**:
   ```bash
   awk '{ printf "%-10s %5.2f\n", $1, $2 }' file.txt  # Prints the first field left-aligned and the second field as a float with 2 decimals
   ```

### 9. **Regular Expressions**:
   - AWK uses regular expressions for pattern matching. You can use regex to search for patterns within lines and take action based on matches.

   **Example**:
   ```bash
   awk '/^[A-Z]/ { print $0 }' file.txt  # Prints lines that start with a capital letter
   ```

### 10. **BEGIN and END Blocks**:
   - AWK has special `BEGIN` and `END` blocks that run before and after the main input processing, respectively.
   - `BEGIN` is executed before reading the first input line, often used for initialization.
   - `END` is executed after all input has been processed, often used to print final results.

   **Example**:
   ```bash
   awk 'BEGIN { print "Start of Processing" } { print $0 } END { print "End of Processing" }' file.txt
   ```

### 11. **Arrays**:
   - AWK supports associative arrays (indexed by strings or numbers) that can be used to store data and count occurrences.

   **Example**:
   ```bash
   awk '{ arr[$1]++ } END { for (i in arr) print i, arr[i] }' file.txt  # Counts occurrences of the first field
   ```

### 12. **Functions**:
   - AWK allows defining custom functions to organize reusable code.

   **Example**:
   ```bash
   awk 'function square(x) { return x * x } { print square($1) }' file.txt  # Prints the square of the first field
   ```

### 13. **Redirection and Piping**:
   - AWK supports output redirection and can send data to external files or programs.

   **Example**:
   ```bash
   awk '{ print $1 > "output.txt" }' file.txt  # Redirects the first field to a file
   ```

### 14. **Input from Multiple Files**:
   - AWK can process multiple input files in sequence. It can also print the file name with the `FILENAME` variable.

   **Example**:
   ```bash
   awk '{ print FILENAME, $0 }' file1.txt file2.txt  # Prints each line with its file name
   ```

### 15. **Inline AWK Scripts and Files**:
   - You can either write AWK commands inline on the command line or store them in a separate file to be executed.

   **Inline**:
   ```bash
   awk '{ print $1 }' file.txt
   ```

   **Script File (`script.awk`)**:
   ```awk
   { print $1 }
   ```

   **Run the script**:
   ```bash
   awk -f script.awk file.txt
   ```

---

### Summary of AWK Features:

1. Field and record processing.
2. Pattern matching using regular expressions.
3. Arithmetic operations.
4. Built-in variables (NR, NF, FS, etc.).
5. User-defined variables.
6. String operations.
7. Control structures (`if`, `while`, `for`).
8. Formatted printing (`printf`).
9. Regular expression matching.
10. `BEGIN` and `END` blocks for pre- and post-processing.
11. Associative arrays.
12. Custom function definitions.
13. Redirection and piping.
14. Multi-file processing.
15. Inline and file-based AWK scripts.

These features make AWK a versatile and powerful tool for text manipulation and data extraction in Unix/Linux environments.
### v

