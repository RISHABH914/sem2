document.addEventListener("DOMContentLoaded", function () {
    let form = document.getElementById("registrationForm");
    let fullName = document.getElementById("fullName");
    let email = document.getElementById("email");
    let password = document.getElementById("password");
    let confirmPassword = document.getElementById("confirmPassword");
    let fullNameError = document.getElementById("fullNameError");
    let emailError = document.getElementById("emailError");
    let passwordError = document.getElementById("passwordError");
    let confirmPasswordError = document.getElementById("confirmPasswordError");

    function showError(ele, msg) {
        ele.innerText = msg;
        ele.style.display = "block";
    }

    function clearError(ele) {
        ele.style.display = "none";
    }

    // Function to validate the email (allows uppercase, lowercase, numbers, and specific domains)
    function validateEmail(email) {
        let emailRegex = /^[a-zA-Z0-9._%+-]+@(students\.iiit\.ac\.in|gmail\.com|research\.iiit\.ac\.in)$/i;
        return emailRegex.test(email);
    }

    // Function to validate the password (standard password rules)
    function validatePassword(password) {
        return password.length >= 8 && /[A-Z]/.test(password) && /[a-z]/.test(password) && /\d/.test(password);
    }

    form.onsubmit = function (event) {
        event.preventDefault();
        let isValid = true;

        if (fullName.value.trim() === "") {
            showError(fullNameError, "Full Name required");
            isValid = false;
        } else clearError(fullNameError);

        if (!validateEmail(email.value)) {
            showError(emailError, "Invalid email. Allowed domains: @students.iiit.ac.in, @gmail.com, @research.iiit.ac.in");
            isValid = false;
        } else clearError(emailError);

        if (!validatePassword(password.value)) {
            showError(passwordError, "Weak password");
            isValid = false;
        } else clearError(passwordError);

        // Check if passwords match
        if (confirmPassword.value !== password.value) {
            showError(confirmPasswordError, "Passwords don't match");
            isValid = false;
        } else clearError(confirmPasswordError);

        if (isValid) {
            alert("Success! Your form has been successfully submitted.");
            form.reset();
        }
    };

    [fullName, email, password, confirmPassword].forEach(input => {
        input.oninput = function () {
            clearError(document.getElementById(input.id + "Error"));
        };
    });
});
