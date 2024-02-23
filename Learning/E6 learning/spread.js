const first = [1, 2, 3];
const second = [4, 5, 6];

// Old way to combine arrays
const combined = first.concat(second); // returns [1, 2, 3, 4, 5, 6]

// New way to combine arrays
const combinedSpread = [...first, 'a', ...second, 'b']; // returns [1, 2, 3, "a", 4, 5, 6, "b"]

const clone = [...first]; // returns [1, 2, 3]
console.log(first);
console.log(clone);
console.log(combinedSpread);

const firstObj = {name: 'Mosh'};
const secondObj = {job: 'Instructor'}; 

const combinedObj = {...firstObj, ...secondObj, location: 'Australia'}; // returns {name: "Mosh", job: "Instructor", location: "Australia"}

console.log(combinedObj);