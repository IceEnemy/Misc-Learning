console.log("Intro to JavaScript");

// var = globally/locally scoped, redeclare, update
// let = (only available in block scope ({})), can be updated
// ex: if(){
//    let a;
//}
// const = block scoped, cant update

var a;
var b = 9;
var c = "Hey";
var d = true;
var e = ["Apple","Banan","Watermelon",9,true];

//insert and remove data from last index
e.push("durian");
console.log(e);
e.pop();
e.pop();
console.log(e);

//insert and remove data from first index
e.unshift("Pear");
console.log(e);
e.shift();
e.shift();
console.log(e);

//selection
if(b == 9){
    console.log("b is equal to 9");
}
else{
    console.log("b is not equal to 9");
}

//switch case
var key = 10;
switch (key) {
    case 10:
        console.log("key == 10");
        break;

    default:
        console.log("key != 10");
        break;
}

//repetition (for loop, while loop, do while, for of,  ...)
for(let i = 0; i<10; i++){
    console.log(i);
}

while(b>0){
    console.log(b);
    b--;
}

do{
    console.log(key);
    key++;
}while(key<20);

for (const thing of e) {
    console.log(thing);
}

//function (prompt usually takes in strings, so we use parseInt to typecase it into an integer)
function addInputNumber(){
    let a = parseInt(prompt("Input the first Number"));
    let b = parseInt(prompt("Input the second Number"));

    return a+b;
}

// console.log(addInputNumber());

//built in functions
// getMonth Returns 0 to 11, so you have to add 1
var date = new Date;
document.getElementById("date").innerHTML = (date.getMonth()+1) + '/' + date.getDate() + '/' + date.getFullYear();

//string functions
var string = "MarVelous";
var substr = string.substr(0,5);
console.log(substr);
var substring = string.substring(0,5); //the end index is -1, so this actually only goes to the 4th index
console.log(substring);

var length = string.length;
console.log(length);

var idx = string.indexOf("Vel"); //prints the index where the substring starts
console.log(idx);

var check = isNaN(string); //checks whether something is a number or not, if its not, its true, if it is, its false
console.log(check);

var toLower = string.toLowerCase();
console.log(toLower);

var toUpper = string.toUpperCase();
console.log(toUpper);

//math functions (use Math. first)
var decimal = 4.5;
console.log(Math.round(decimal));
console.log(Math.floor(decimal));
console.log(Math.ceil(decimal));

var sqrt = 144;
console.log(Math.sqrt(sqrt));
console.log(Math.pow(sqrt,2));

document.getElementById("random").addEventListener("click", function(){
    let min = 1;
    let max = 10;
    let randomInt = Math.floor(Math.random() * (max - min + 1) + min); //only return 0-1 initially, so we have to make a formula to get something like a random number generator from 1-10
    document.getElementById("randnum").innerHTML = randomInt;
})

function dblclick(){
    document.getElementById("dblclick").style.backgroundColor = "green";
}

document.getElementById("mouseenter").addEventListener("mouseenter", function(){
    document.getElementById("mouseenter").style.color = "purple";
})

document.getElementById("mouseleave").addEventListener("mouseleave", function(){
    document.getElementById("mouseleave").style.color = "red";
})

document.getElementById("mouseover").addEventListener("mouseover", function(){
    document.getElementById("mouseover").style.color = "blue";
})

// mouseover takes in account the background also while mouseenter only accounts for the text

document.getElementById("keyboard").addEventListener("keydown", function(){
    document.getElementById("keyboard").style.backgroundColor = "pink";
})

document.getElementById("keyboard").addEventListener("keyup", function(){
    document.getElementById("keyboard").style.backgroundColor = "yellow";
})

// document.getElementById("keyboard").addEventListener("keypress", function(){
//     document.getElementById("keyboard").style.backgroundColor = "pink";
// }) 
//difference between this is on keypress, it doesnt register like control alt n stuff while keydown does