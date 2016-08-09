function digPow(n, p){
    digits = n.toString(10).split("").map(Number);
    var big_number = 0;
    for(var i = 0; i < digits.length; i++) {
        big_number += Math.pow(digits[i], p);
        p++;
    }
    var k = big_number / n;

    return Number.isInteger(k) ? k : -1;
}

console.log(digPow(89, 1)); //should return 1 since 8¹ + 9² = 89 = 89 * 1
console.log(digPow(92, 1)); //should return -1 since there is no k such as 9¹ + 2² equals 92 * k
console.log(digPow(695, 2)); //should return 2 since 6² + 9³ + 5⁴= 1390 = 695 * 2
console.log(digPow(46288, 3)); //should return 51 since 4³ + 6⁴+ 2⁵ + 8⁶ + 8⁷ = 2360688 = 46288 * 51
