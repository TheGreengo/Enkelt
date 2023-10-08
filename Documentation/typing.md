# Int
The default integer will be 4 bytes and will be declared with the lower case `int` keyword. You will also be able to use `int(num)` to specify the number of bytes you would like the int to be in order to accomodate small or large numbers. Acceptable sizes will be powers of 2 up to 32.
# Float
The default float will also be 4 bytes and I'm excited to learn how those are implemented so that I can plan out how the precision and all that will function. It will use the `float` keywoard and similarly to a `int` you will be able to specify size using powers of 2, but limited to starting with 4.
# Char
`char` will be individual characters using the UTF-8 encoding.
# String
Strings will be arrays of `char`s using the `string` keyword.
# Bool
`bool`s will be able to be set to `TRUE`, `true`, or `True` equivalently, or `FALSE`, `False`, or `false`. In memory, this will be a single bit however and will default to print out as `true` or `false`.
# Conversions
Using the syntax `(newtype) variable_name` one can statically cast any of the basic types together, including between datatypes (not from datatypes to base types other than `string`). The conversions to `int` or `float` will be 1 or 0 for `bool`, the UTF encoding for `string` or `char` and adding `.0` for `int` to `float` or removing decimal places for `float` to `int`. To `char` will lookup the UTF-8 encoding if valid for number types and take the first value for a string. The conversion to `string` should be obvious. 
# Any
The type `any` will exist but is highly discouraged and will be finally assigned at the time of first assignment. This is only to be used for data objects or function parameters.
## Type()
The `Type()` function may be used to get the type or classname of an `any` type variable.
# MultiType
DataTypes can be assigned `multiType` so that any values can be contained, but this will change and slow down the internal functionality to accomodate such madness.