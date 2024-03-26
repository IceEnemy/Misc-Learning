function hey(){
    console.log('hey');
}

hey(); // hey

const person = {
    name: 'Mosh',
    walk() {
        console.log(this);
    }

}

person.walk(); // {name: "Mosh", walk: ƒ}

const walk = person.walk.bind(person); // bind returns a new instance of the walk function
console.log(walk); // ƒ walk() {console.log(this);
walk(); 



