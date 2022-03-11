/* Assignments to be submitted for Javascript */
/* Submitted by: Saurabh Jadhav */
// 1. A boomerang is a V-shaped sequence that is either upright or upside down. 
// Specifically, a boomerang can be defined as: sub-array of length 3,
// with the first and last digits being the same and the middle digit being different.

// - [3, 7, 3], [1, -1, 1], [5, 6, 5]

// Create a function that returns the total number of boomerangs in an array.

// input: [3, 7, 3, 2, 1, 5, 1, 2, 2, -2, 2]
// output: 3 boomerangs in this sequence:  [3, 7, 3], [1, 5, 1], [2, -2, 2]

console.log("Question No.1 ->\n");
arr = [3, 7, 3, 2, 1, 5, 1, 2, 2, -2, 2]
boomerang = []
for (let i = 0; i < arr.length - 2; i++) {
    if (arr[i] == arr[i + 2] & arr[i] != arr[i + 1])
        boomerang.push(arr.slice(i, i + 3))
}

console.log("Given array is: " + arr);
console.log(boomerang.length + " boomerangs in this sequence: ")
boomerang.forEach(element => {
    console.log(element);
});

// 2. Create a function that takes an array of strings and 
// returns an array with only the strings that have numbers in them. 
// If there are no strings containing numbers, return an empty array.

console.log("\nQuestion No.2 ->\n");

function getNumString(strArr) {
    var NumArray = new Array();
    strArr.forEach((str) => {
        if (str.match(/\d+/g)) NumArray.push(str);
        //Without using regex
        // for (let element in str) {
        //     if (Number(str[element])) {
        //         NumArray.push(str);
        //         break;
        //     }
        // }
    })
    return NumArray;
}

let strArr = ["123", "sau123", "saurabh", "tesla1", "spcaeX", "1.0 mission"]
console.log("Given array has following strings: ")
console.log(strArr);
console.log("\nString containing numbers are: ")
console.log(getNumString(strArr));

// 3. Create a function which counts how many lone 1's appear in a given number.
// Lone means the number doesn't appear twice or more in a row.
// example: countLoneOnes(101) ➞ 2, countLoneOnes(1191) ➞ 1

console.log("\nQuestion No.3 ->\n");

function countLoneOnes(NumArr) {

    NumArr.forEach(num => {
        let cnt = 0;
        num = num.toString()
        for (let i = 0; i < num.length; i++) {
            if (num[i] == '1' && num[i + 1] != '1' && num[i - 1] != '1') cnt++;
        }
        console.log(num, " ➞ ", cnt);

    });
}

let NumArr = [2, 25, 0, 10, 119, 101, 1121, 5101, 1, "012"]
countLoneOnes(NumArr)

// 4. Create a function that takes one, two or more numbers as arguments and adds them together to get a new number. 
// The function then repeatedly multiplies the digits of the new number by each other,
// yielding a new number, until the product is only 1 digit long. Return the final product.

console.log("\nQuestion No.4 ->\n");

function getSingleDigitProduct() {
    let product = 0, finalProduct = 1;
    for (let i = 0; i < arguments.length; i++)
        product += arguments[i]

    product = product.toString().split('');

    while (product.length > 1) {
        finalProduct = product.reduce(function (a, b) {
            return parseInt(a) * parseInt(b);
        }, 1);
        product = finalProduct.toString().split('');
    }

    return finalProduct;
}

console.log("Final product is: ", getSingleDigitProduct(11, 13));
console.log("Final product is: ", getSingleDigitProduct(23, 65, 34));

// 5. Given an array, write a function to calculate it's depth. Assume that a normal array has a depth of 1.

// example:
//                 depth([1, 2, 3, 4]) ➞ 1
//                 depth([1, [2, 3, 4]]) ➞ 2
//                 depth([1, [2, [3, 4]]]) ➞ 3
//                 depth([1, [2, [3, [4]]]]) ➞ 4

console.log("\nQuestion No.5 ->\n");

function depth(Arr) {
    let Depth = 1;
    for (let ele in Arr) {
        if (Array.isArray(Arr[ele])) {
            Depth += depth(Arr[ele]);
        }
    }
    return Depth;
}

console.log("depth([1, 2, 3, 4]) ➞ ", depth([1, 2, 3, 4]));
console.log("depth([1, [2, 3, 4]]) ➞ ", depth([1, [2, 3, 4]]));
console.log("depth([1, [2, [3, 4]]]]) ➞ ", depth([1, [2, [3, 4]]]));
console.log("depth([1, [2, [3, [4]]]]) ➞ ", depth([1, [2, [3, [4]]]]));

// 6. In JavaScript ES6 an arrow function expression is a syntactically compact alternative to a regular function expression.
// Create a function that takes a string representing a function and converts between an arrow function and a regular function
// - If the input is a regular function, return an equivalent arrow function.
// - If the input is an arrow function, return an equivalent regular function.

console.log("\nQuestion No.6 ->\n");

function Add(a, b) {
    return a + b;
}

function SayHey() {
    return "Hey";
}

let add = (a, b) => { return a + b; };
let sub = (a, b) => a - b;
let hello = () => {
    return "Hello World!";
};

function convertFunction(func) {
    let fname = func.name;
    func = func.toString()

    if (func[0] == 'f') {
        console.log(`Input function is a regular function-\n${func}\n\nArrow expression of given function is:`);
        fname = func.split('function ');
        let fname1 = fname[1].split('(')[0];
        let args = fname[1].split('(')[1].split(')')[0];
        let fbody = fname[1].split('(')[1].split(')')[1];
        let arrowExpression = 'let ' + fname1 + ' = (' + args + ') =>' + fbody + "\n";
        console.log(arrowExpression);
    }
    else {
        console.log(`Input function is an Arrow expression of regular function-\n${fname} = ${func}; \n\nRegular function of given function is:`);
        let args = func.split('=')[0];
        let body = func.split('>')[1];
        if (body.split('{')[1] === undefined)
            body = "{\n return" + body + "; \n}";
        let arrowExpression = 'function ' + fname + args + "\n" + body + "\n";
        console.log(arrowExpression);
    }
}

convertFunction(SayHey)
convertFunction(sub)
convertFunction(add)