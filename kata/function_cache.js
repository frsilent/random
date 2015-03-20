/*
If you are calculating complex things or execute time-consuming API calls, you sometimes want to cache the results. In this case we want you to create a function wrapper, which takes a function and caches its results depending on the arguments, that were applied to the function.

Usage example:

var complexFunction = function(arg1, arg2) { complex calculation in here };
var cachedFunction = cache(complexFunction);

cachedFunction('foo', 'bar'); // complex function should be executed
cachedFunction('foo', 'bar'); // complex function should not be invoked again, instead the cached result should be returned
cachedFunction('foo', 'baz'); // should be executed, because the method wasn't invoked before with these arguments
*/

// function greaterThan(n) {
//   return function(m) { return m > n; };
// }
// var greaterThan10 = greaterThan(10);
// console.log(greaterThan10(11));
// → true


function complexFunction(p1, p2) {
    return p1 * p2;
}

var cache = {};

function cache(func) {
    debug(func);
}

var cachedFunction = cache(complexFunction(5, 2));

// //our cache object
// var cache = {};
// var formatTweets(info) {
//     //formats tweets, does whatever you want with the tweet information
// };

// //event
// $('myForm').addEvent('submit',function() {
//     var handle = $('handle').value; //davidwalshblog, for example
//     var cacheHandle = handle.toLowerCase();
//     if(cache[cacheHandle] != "undefined") {
//         formatTweets(cache[cacheHandle]);
//     }
//     else {
//         //gitter
//         var myTwitterGitter = new TwitterGitter(handle,{
//             count: 10,
//             onComplete: function(tweets,user) {
//                 cache[cacheHandle] = tweets;
//                 formatTweets(tweets);
//             }
//         }).retrieve();
//     }
// });