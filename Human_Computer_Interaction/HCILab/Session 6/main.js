function validate(){
    const username = document.getElementById("username").value
    const email = document.getElementById("email").value
    const password = document.getElementById("password").value
    const age = document.getElementById("age").value
    const male = document.getElementById("male")
    const female = document.getElementById("female")
    const terms = document.getElementById("terms")

    if(username.length < 5){
        // alert("bruh moment ur name too short, atleast 5 character ok?")
        document.getElementById("error_msg").innerHTML = "bruh moment ur name too short, atleast 5 character ok?<br>"
    }
    else if(!email.endsWith("@gmail.com")){
        alert("That aint a valid email bruv, must be @gmail.com")
    }
    else if(!isAlphaNum(password)){
        alert("Pass must contain atleast 1 alphabet character and 1 number bruv")
    }
    else if(age<13){
        alert("You must be atleast 13 years old you baby")
    }
    else if(!male.checked && !female.checked){
        alert("pick 1 genderrrrrrrrrrrrrrrr?")
    }
    else if(!terms.checked){
        alert("agreeeee the termsmssmsmsms")
    }
    // else document.getElementById("error_msg").innerHTML =""
    else window.location.href = "home.html"

    console.log(username)
}

function isAlphaNum(password){
    var isAlpha = false
    var isNum = false
    for(let i = 0; i<password.length; i++){
        if(isNaN(password[i])){
            isAlpha = true;
        }
        else{
            isNum = true;
        }
    }
    if(isAlpha == false || isNum == false) return false
    return true
}