const person = {
    talk() {
        setTimeout(() => {
            console.log('this', this);
        }, 1000);
        console.log('this', this);
    }
}

person.talk(); // {talk: ƒ} // the talk function is a method of the person object