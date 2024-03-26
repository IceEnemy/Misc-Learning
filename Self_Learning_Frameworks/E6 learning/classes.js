// const person = {
//     name: 'Mosh',
//     walk() {
//         console.log(walk);
//     }
// };

// const person2 = {
//     name: 'Mosh',
//     walk() {
//         console.log(walk);
//     }
// };
//this have duplicate functions

class Person {
    constructor(name) {
        this.name = name;
    }

    walk() {
        console.log(this);
    }
}

const person = new Person('Mosh'); // the new keyword creates a new instance of the Person object

person.walk(); // Person {name: "Mosh"}