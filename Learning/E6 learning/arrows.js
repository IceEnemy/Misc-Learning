const square = function(number){
    return number * number;
}

const sqr = number => number * number; // arrow function

console.log(square(5)); // 25
console.log(sqr(5)); // 25

const jobs = [
    {id: 1, isActive: true},
    {id: 2, isActive: true},
    {id: 3, isActive: false}
];

const activeJobs = jobs.filter(function(job) {return job.isActive;}); // returns the first two objects in the array

const activeJobsArrow = jobs.filter(job => job.isActive);   // returns the first two objects in the array

console.log(activeJobs); // [ { id: 1, isActive: true }, { id: 2, isActive: true } ]
console.log(activeJobsArrow); // [ { id: 1, isActive: true }, { id: 2, isActive: true } ]

const person = {
    talk() {
        console.log('this', this);
    }
}

person.talk(); // {talk: ƒ} // the talk function is a method of the person object