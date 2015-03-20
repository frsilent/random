/*
Write a function called calculate that takes 3 values. The first and third values are numbers.
The second value is a character. If the character is "+" , "-", "*", or "/",
the function will return the result of the corresponding mathematical function on the two numbers.
If the string is not one of the specified characters, the function should return null.
*/

function calculate(num1, operation, num2) {
    ops = new Array("+", "-", "*", "/");
    if(operation === "/" && num2 === 0) {
        return null;
    } else if(ops.indexOf(operation) > -1) {
        return eval(String(num1 + operation + num2));
    } else {
        return null;
    }
}

debug(calculate(3.2, "+", 8)); // 11.2
debug(calculate(3.2, "-", 8)); // -4.8
debug(calculate(3.2, "/", 8)); // 0.4
debug(calculate(3.2, "*", 8)); // 25.6
debug(calculate(-3, "+", 0)); // -3
debug(calculate(-3, "-", 0)); // -3
debug(calculate(-3, "/", 0)); // null
debug(calculate(-3, "*", 0)); // 0
debug(calculate(-3, "w", 0)); // null
