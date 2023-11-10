let secretNumber = Math.floor(Math.random() * 10) + 1;
let tries = 5;

function checkGuess() {
    let guess = document.getElementById('guess').value;
    let message = document.getElementById('message');
    let triesElement = document.getElementById('tries');

    if (tries > 0) {
        if (guess == secretNumber) {
            message.innerHTML = "Congratulations! You guessed the number.";
            message.style.color = "green";
            tries = 0;
        } else {
            tries--;
            message.innerHTML = "Wrong guess. Try again!";
            message.style.color = "red";
        }
        triesElement.innerHTML = tries;
    } else {
        message.innerHTML = "Sorry, you're out of tries. The number was " + secretNumber + ".";
        message.style.color = "red";
    }
}