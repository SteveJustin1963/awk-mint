 
#!/usr/bin/awk -f

# Initialize an empty stack.
BEGIN {
    stack_top = -1
}

# Define functions to push and pop values from the stack.
function push(value) {
    stack[++stack_top] = value
}

function pop() {
    return stack[stack_top--]
}

# Main Forth-like commands.
{
    for (i = 1; i <= NF; i++) {
        token = $i
        
        # Check if the token is a number and push it onto the stack.
        if (token ~ /^[0-9]+$/) {
            push(token)
        }
        # Handle basic arithmetic operations.
        else if (token == "+") {
            operand2 = pop()
            operand1 = pop()
            result = operand1 + operand2
            push(result)
        }
        else if (token == "-") {
            operand2 = pop()
            operand1 = pop()
            result = operand1 - operand2
            push(result)
        }
        else if (token == "*") {
            operand2 = pop()
            operand1 = pop()
            result = operand1 * operand2
            push(result)
        }
        else if (token == "/") {
            operand2 = pop()
            operand1 = pop()
            if (operand2 == 0) {
                print "Error: Division by zero"
                exit 1
            }
            result = operand1 / operand2
            push(result)
        }
        # If the token is not recognized, print an error message.
        else {
            print "Error: Unrecognized token - " token
            exit 1
        }
    }
}

# Print the final result from the stack.
END {
    if (stack_top == 0) {
        print "Result:", stack[0]
    } else {
        print "Error: Incomplete expression or invalid input"
        exit 1
    }
}
 
