/**
 * @return {Function}
 */
var createHelloWorld = function() {
    
    return function(...args) {
        return "Hello World";
    }
};
const helloFn = createHelloWorld();
console.log(helloFn());        // "Hello World"
console.log(helloFn(42));      // "Hello World"
console.log(helloFn("test"));  // "Hello World"
console.log(helloFn(true, [])); // "Hello World"
/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */