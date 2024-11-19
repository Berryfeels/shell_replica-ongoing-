# **Shell_replica: As Beautiful as a Shell**

## **Introduction**  
Minishell is a simplified version of a Unix shell designed as a project for understanding and implementing essential shell functionalities. 
It replicates core behaviors of bash, focusing on process management, file descriptors, and interprocess communication. 
This project challenges developers to dive deep into the world of system programming, memory management, and user interaction.

---

## **Main Features**  

### **Core Shell Behavior**  
- **Command Prompt**: Displays a customizable prompt while waiting for user input.  
- **Command Execution**: Executes binaries using `PATH` or relative/absolute paths.  
- **Command History**: Keeps a history of executed commands for easy recall.  

---

### **Redirections and Pipes**  
- **Redirections**:  
  - Input (`<`): Redirects input from a file.  
  - Output (`>`): Redirects output to a file.  
  - Append (`>>`): Redirects output in append mode.  
  - Here-doc (`<<`): Reads input until a specified delimiter is encountered.  
- **Pipes (`|`)**: Connects the output of one command to the input of another.  

---

### **Environment Variables**  
- **Expansion**: Handles `$VAR` to expand environment variables.  
- **Exit Status**: Implements `$?` to display the exit status of the last executed command.  

---

### **Signal Handling**  
- Handles `ctrl-C`, `ctrl-D`, and `ctrl-\` signals:  
  - `ctrl-C`: Interrupts the current command and shows a new prompt.  
  - `ctrl-D`: Exits the shell.  
  - `ctrl-\`: Does nothing, similar to bash.  

---

### **Built-in Commands**  
Minishell implements the following built-in commands:  
1. **`echo`**: Supports the `-n` option.  
2. **`cd`**: Changes the current working directory.  
3. **`pwd`**: Prints the current working directory.  
4. **`export`**: Adds or modifies environment variables.  
5. **`unset`**: Removes environment variables.  
6. **`env`**: Displays all environment variables.  
7. **`exit`**: Exits the shell with a specified exit code.  

---

### **Bonus Features** (if implemented)  
- **Logical Operators**: Supports `&&` and `||` with parenthesis for priority.  
- **Wildcards (`*`)**: Matches patterns in the current directory.  

---

## **Technical Details**  
- Written in **C**.  
- Memory management ensures no leaks (excluding `readline` library leaks).  
- Compatible with the following system calls and libraries:  
  - `readline`, `fork`, `execve`, `pipe`, `dup2`, `signal`, and many more.  

---

## **How to Use**  
1. Clone the repository and navigate to the project directory.  
2. Compile the shell using the provided **Makefile**:  
   ```bash
   make
   ```  
3. Run Minishell:  
   ```bash
   ./minishell
   ```  
4. Type commands as you would in a typical shell.  

---

## **Conclusion**  
Minishell is not just about writing code; it's about understanding the foundational concepts of Unix-like systems. 
By creating this mini bash, you’ll gain insights into the intricacies of shells and the challenges of system-level programming. 
Dive in and make your shell as beautiful as possible!  
