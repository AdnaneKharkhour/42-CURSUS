# Pipex

## 🔹 Description  
Pipex is a project that replicates the behavior of shell pipelines (`|`). It allows executing two commands where the output of the first command is passed as input to the second using pipes.

---

## 📂 Files  
- **pipex.c** – Main logic for handling pipes and executing commands.  
- **utils.c** – Helper functions for parsing and error handling.  
- **exec.c** – Handles process creation and command execution.  

---

## 🚀 Usage  

### 📌 Compilation  
Compile the program using:  
```bash  
make
```

### 📌 Running the Program
Run Pipex with the following syntax:

```bash
./pipex infile "cmd1" "cmd2" outfile
```
Example:

```bash
./pipex input.txt "cat" "wc -l" output.txt  
```
This mimics the shell command:

```bash
< input.txt cat | wc -l > output.txt  
```
### 📌 Bonus Features
The bonus version of Pipex includes:

Multiple pipes (e.g., cmd1 | cmd2 | cmd3 | ...).

Here document (<< LIMITER) for handling multi-line input.

To compile the bonus version, use:

```bash
make bonus  
```
### 📌 Running with here_doc Mode
```bash
./pipex here_doc LIMITER "cmd1" "cmd2" output.txt  
```
Example:

```bash
./pipex here_doc END "cat" "wc -l" output.txt  
```
This mimics:

```bash
cat << END | wc -l >> output.txt  
```
### 🔧 Error Handling
Pipex gracefully handles:

Invalid files (e.g., missing infile or outfile).

Incorrect command execution.

Memory allocation errors.

