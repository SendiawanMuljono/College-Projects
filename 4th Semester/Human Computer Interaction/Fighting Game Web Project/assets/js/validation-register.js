function register(){
    var name = document.getElementById('name').value;
    var email = document.getElementById('email').value;
    var genders = "";
    var password = document.getElementById('password').value;
    var confirmPassword = document.getElementById('confirm-password').value;
	var termCondition = document.getElementById('term-and-condition');
    if(document.getElementById('radioMale').checked==true)
		genders = 'male';
	else if(document.getElementById('radioFemale').checked==true)
        genders ='female';

    var isValid = true;
    if(validateName(name) == false){
        isValid = false;
    }
    else if(validateEmail(email) == false){
        isValid = false;
    }
    else if(validatePassword(password) == false){
        isValid = false;
    }
    else if(validateConfirmPassword(password, confirmPassword) == false){
        isValid = false;
    }
    else if(validateGender(genders) == false){
        isValid = false;
    }
    else if(validateTermAndCondition(termCondition) == false){
        isValid = false;
    }
    if(isValid){
        alert('Register success');
        //pindah halaman
        window.location.href = '../home/home.html';
    }

}

function validateName(name) {
    var isNameValid = true;
    if(name == ""){
        alert("Name must filled");
        isNameValid = false;
    }
    else if(name.length < 3) {
        alert("Name must have 3 haracters minimum");
        isNameValid = false;
    }
    return isNameValid;  
}

function validateEmail(email)
{
    var isEmailValid = true;
    if(email == "") {
        isEmailValid = false;
        alert("Email must be filled");
    }
    else if(email.startsWith("@") || email.startsWith(".")){
		isEmailValid = false;
        if(email.startsWith("@")) {
            alert("Email format could not start with @");
        }
        else if (email.startsWith(".")) {
            alert("Email format could not start with .");
        }
	}
	else if(email.endsWith("@") || email.endsWith("."))	{
		isEmailValid = false;
        if(email.endsWith("@")) {
            alert("Email format could not end with @");
        }
        else if (email.endsWith(".")) {
            alert("Email format could not end with .");
        }
    }
    else if(email.indexOf("@.") > -1 || email.indexOf(".@") > -1 ){
		isEmailValid = false;
        if(email.indexOf("@.") > -1) {
            alert("Email format @. could not accepted");
        }
        else if (email.indexOf(".@") > -1) {
            alert("Email format .@ could not accepted");
        }
	}
    else if(!email.endsWith(".com") && !email.endsWith(".co.id"))	{
		isEmailValid = false;
        alert("Email format must be end with .com or .co.id");
    }
    return isEmailValid;
}

function validatePassword(password){
    var isPasswordValid = true;
    if(password == "") {
        alert("password must filled");
        isPasswordValid = false;
    }
    else if(password.length < 5) {
        alert("Password must have 5 haracters minimum");
        isPasswordValid = false;
    }
    else {
        var uppercase = false;
        for(var i = 0; i < password.length; i++) {
            if(password[i] >= 'A' && password[i] <= 'Z'){
                uppercase = true;
                break;
            }
        }

        if(uppercase == false) {
            alert("Password must have at least 1 uppercase character");
            isPasswordValid = false;
        }
    }
    return isPasswordValid; 
}

function validateConfirmPassword(password, confirmPassword){
    var isConfirmPasswordValid = true;
    if(confirmPassword == "") {
        alert("confirm password must filled");
        isConfirmPasswordValid = false;
    }
    else if(confirmPassword != password){
        alert("confirm password must same with password");
        isConfirmPasswordValid = false;
    }
    return isConfirmPasswordValid; 
}

function validateGender(gender) {
    var isGenderValid = true;
    if(gender == ""){
        isGenderValid = false;
        alert("Gender must be chosen");
    }
    return isGenderValid;
}

function validateTermAndCondition(termCondition) {
    if(!termCondition.checked){
        alert("Term and Condition must be checked");
        return false;
    }
    return true;
}