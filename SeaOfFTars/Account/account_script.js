function validate(){
    const username = document.getElementById("username").value
    const country = document.getElementById("country").value
    const email = document.getElementById("email").value
    const password = document.getElementById("password").value
    const pass = validPassword(password)
    const confirm_password = document.getElementById("confirm_password").value
    const agree = document.getElementById("agree")
    if(username.length < 3){
        document.getElementById("error_msg").innerHTML = "Your Username must be 3 characters or longer!"
    }
    else if(username.length > 20){
        document.getElementById("error_msg").innerHTML = "Your Username must be less than 20 characters!"
    }
    else if(country == "none"){
        document.getElementById("error_msg").innerHTML = "You must pick a valid country!"
    }
    else if(!validEmail(email)){
        document.getElementById("error_msg").innerHTML = "You must input a valid email! (contains @ and ends with .com)"
    }
    else if(pass == 0){
        document.getElementById("error_msg").innerHTML = "Password must be at least 8 characters long!"
    }
    else if(pass == -1){
        document.getElementById("error_msg").innerHTML = "Password must contain lowercase letters!"
    }
    else if(pass == -2){
        document.getElementById("error_msg").innerHTML = "Password must contain uppercase letters!"
    }
    else if(pass == -3){
        document.getElementById("error_msg").innerHTML = "Password must contain numbers!"
    }
    else if(password != confirm_password){
        document.getElementById("error_msg").innerHTML = "Password and confirmation must be the same!"
    }
    else if(!agree.checked){
        document.getElementById("error_msg").innerHTML = "You must agree with the terms of service!"
    }
    else{
        document.getElementById("error_msg").innerHTML = ""
        alert("Registration Successful!")
        window.location.href = "/Homepage/Homepage.html"
    }
}

function validEmail(email){
    if(email.includes('@') && email.endsWith(".com")){
       return true 
    } 
    return false
}

function isLetter(character){
    if((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')){
       return true 
    } 
    return false
}

function validPassword(password){
    var len = password.length
    if(len < 8) return 0

    var num = false
    var lowercase = false
    var uppercase = false
    for(let i = 0; i < len; i++){
        if(isNaN(password[i])){
            if(isLetter(password[i])){
                if(password[i] == password[i].toUpperCase()){
                    uppercase = true
                } 
                else{
                   lowercase = true 
                } 
            }
        }
        else{
            num = true
        }
    }
    if(lowercase == false){
        return -1
    }
    else if(uppercase == false){
        return -2
    } 
    else if(num == false){
        return -3
    }
    return 1
}

function logged(){
    window.location.href = "/Homepage/Homepage.html"
}