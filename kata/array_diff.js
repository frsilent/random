function array_diff(a, b) {
    for (var i = 0; i < b.length; i++) {
        index = a.indexOf(b[i]);
        while(index > -1) {
            index = a.indexOf(b[i]);
            if (index > -1) {
               a.splice(index, 1);
            }
        }
    }
    return a;
}

console.log(array_diff([1,2],[1])); // == [2]
console.log(array_diff([1,2,2,2,3],[2])); // == [1,3]

// Your goal in this kata is to implement an difference function, which subtracts one list from another.

// It should remove all values from list a, which are present in list b.

// difference([1,2],[1]) == [2]
// If a value is present in b, all of its occurrences must be removed from the other:

// difference([1,2,2,2,3],[2]) == [1,3]
