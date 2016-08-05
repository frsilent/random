var testingAdd = function(p1, p2) {
    return p1 + p2;
}

function testingMul(p1, p2) {
    return p1 * p2;
}

function cache(originalFunc) {
    function newFunc() {
        if(!newFunc.cache) {
            newFunc.cache = {};
        }
        var args = Array.prototype.slice.call(arguments);
        key = args.join(",");
        if(!newFunc.cache[key]) {
            var result = originalFunc.apply(this, arguments);
            newFunc.cache[key] = result;
        }

        return newFunc.cache[key];
    }
    return newFunc;
}

var cachedAdd = cache(testingAdd);
var cachedMul = cache(testingMul);

var added = cachedAdd(1,2);
var added2 = cachedAdd(1,3);
var added3 = cachedAdd(3,1);
var addedAgain = cachedAdd(1,2);
var multiplied = cachedMul(1,2);
