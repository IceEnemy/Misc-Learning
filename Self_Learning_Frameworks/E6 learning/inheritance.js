class Person {
    constructor(name) {
        this.name = name;
    }

    walk() {
        console.log('walk');
    }
}

class Teacher extends Person {
    constructor(name, degree) {
        super(name); // super is a reference to the base class
        this.degree = degree;
    }

    teach() {
        console.log('teach');
    }
}

const teacher = new Teacher('Mosh', 'MSc');
teacher.walk(); // walk
teacher.teach(); // teach
console.log(teacher); // Teacher {name: "Mosh", degree: "MSc"} // the teacher object has a name and a degree property
console.log(teacher.name); // Mosh
console.log(teacher.degree); // MSc
