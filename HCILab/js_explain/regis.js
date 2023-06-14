function validate(){
    const username = document.getElementById("username").value
    const email = document.getElementById("email").value
    const password = document.getElementById("password").value
    const country = document.getElementById("country").value
    const agree = document.getElementById("terms")

    if(username.length < 5){
        document.getElementById("error_msg").innerHTML = "name too short, just like belle, must be atleast 5 characters <br>"
    }
    else if(!email.includes('@') || !email.endsWith(".com")){
        document.getElementById("error_msg").innerHTML="must have a valid email! <br>"
    }
}