# Function Definition
Functions are defined using the `func` keyword or `func()` type declaration. This implicitly creates a void function.
```
func() name() {
    code that executes when function is called
}
```
# Parameters
Parameters are passed in with a name following a declaration of the type of the parameter to be passed in.
```
func() name(type var_one, type var_two) {
    operations involving variables
}
```
# Parameter default values
You can set default values with an in-line assignment of the variable.
```
func() name(type var_one=def_val, type var_two=def_val) {
    operations involving variables
}
```
# Return values and types
The type of the return value can be set if there is a return value using a type declaration in the parentheses following the `func` keyword including specifying `func(void)`.

The desired return value can be listed after the `return` keyword.
```
func(return_type) name(type var_one, type var_two) {
    operations involving variables

    return return_value
}
```
## Mutable
By default, functions will mutate the values of variables passed in. 

You can specify non-mutating by using the `val` keyword in the declaration.
```
func(return_type) name(val type var_one, val type var_two) {
    operations involving the values of the two variables.
}
```
# Function Calls
To call a function, one simply writes the function name followed by parantheses containing (optionally) the desired parameter.
`func_name()`
# Passing Functions
Functions can be passed by name as variables (of the `func` type) or parameters, not using the parentheses afterwards.
```
func func1() {
    stuff
}
func passed = func1`
```
# Lambda Functions
These I might regret adding later on, and I might change my mind and remove them. For now they will take the form of 
```
(type name, type name) -> {return_value}
```