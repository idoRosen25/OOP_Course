# Key Differences Between C and C++

## **Function Overloading**

- **What it is:** Multiple functions can share the same name with different parameters
- **Why use it:** Avoids needing many differently-named functions that do the same action; compiler determines which function to call based on arguments
- **Note:** Cannot distinguish by return type alone; watch for ambiguity errors

## **Default Parameters**

- **What it is:** Functions can have default values for the last arguments
- **Why use it:** Arguments with defaults can be omitted when calling the function
- **Important:** Default values defined in function prototype (not implementation); beware of ambiguity with overloading

## **Pass by Reference (ByRef)**

- **What it is:** Functions can receive arguments by reference using `&` syntax
- **Why use it:** Allows modifying original variables without explicit pointers; safer and cleaner than pointer syntax
- **Note:** Still implemented with pointers internally but hidden from the user

## **Reference Return Values**

- **What it is:** Functions can return references (memory locations) using `&`
- **Why use it:** Can be used as LValue (left side of assignment); enables chaining operations
- **Important:** Returned reference must remain valid after function ends (global, input variables, etc.)

## **Improved I/O (cin, cout)**

- **What it is:** Stream-based input/output using `<<` and `>>` operators
- **Why use it:** No need to specify format strings or data types (unlike printf/scanf); automatic type detection through function overloading
- **Included from:** `<iostream.h>`

## **Inline Functions**

- **What it is:** Functions embedded directly at call site using `inline` keyword
- **Why use it:** Eliminates function call overhead while maintaining type safety (unlike macros); better than macros for readability and type checking
- **Trade-off:** Larger executable size but more efficient execution

## **Memory Allocation**

- **What it is:** `new` for allocation, `delete` for deallocation (instead of malloc/free)
- **Why use it:** No casting required; type-safe; cleaner syntax
- **For arrays:** Use `new[n]` and `delete[]`

## **Comment Styles**

- **What it is:** Single-line comments using `//` in addition to `/* */`
- **Why use it:** More convenient for brief inline comments

## **Variable Declaration Flexibility**

- **What it is:** Variables can be declared anywhere in code (not just at beginning of blocks)
- **Why use it:** Declare variables closer to where they're used
- **Caution:** Should be used wisely for code clarity

## **Simplified struct/enum Syntax**

- **What it is:** No need to use `struct` or `enum` keyword when declaring variables
- **Why use it:** Cleaner syntax; eliminates need for typedef workarounds from C
- **Example:** `Student s1;` instead of `struct Student s1;`

## **Classes (Object-Oriented Programming)**

- **What it is:** Extension of structs that combines data with methods (functions that operate on that data)
- **Why use it:**
  - Encapsulation: Keep data and related functions together
  - Constructors/Destructors: Automatic initialization and cleanup
  - Access control: `public`/`private` members prevent misuse
  - Methods: Functions belong to objects, using implicit `this` pointer
- **Key difference from C structs:** In C, helper functions are separate and can be misused; in C++, methods are part of the class definition and enforce proper usage
