import { Person } from './modulePerson.js';

export class Teacher extends Person {
    constructor(name, degree) {
        super(name); // super is a reference to the base class
        this.degree = degree;
    }

    teach() {
        console.log('teach');
    }
}