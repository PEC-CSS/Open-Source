var boxes = document.getElementsByClassName('grid-item');
var flag = 0;
var clicks = 0;
for (let square of boxes) {
    square.addEventListener('click', function () {
        if (this.innerHTML == '' && flag == 0) {
            this.innerHTML = '0';
            flag = 1;
        } else if (this.innerHTML == '' && flag == 1) {
            this.innerHTML = 'X';
            flag = 0;
        }
    });
}
function rme() {
    for (let b of boxes) {
        b.replaceWith(b.cloneNode(true));
    }
}
function checkwin(id) {
    clicks += 1;
    var a = 0,
        b = 3,
        c = 6;
    for (let i = 0; i <= 2; i++) {
        if (
            boxes[a + i].innerText == boxes[b + i].innerText &&
            boxes[b + i].innerText == boxes[c + i].innerText &&
            boxes[a + i].innerText != ''
        ) {
            document.getElementById('result').innerHTML =
                '<h1>' + boxes[a + i].innerText + ' WINS !</h1>';
            rme();
            return;
        }
    }
    (a = 0), (b = 1), (c = 2);
    for (let i = 0; i <= 6; i += 3) {
        if (
            boxes[a + i].innerText == boxes[b + i].innerText &&
            boxes[b + i].innerText == boxes[c + i].innerText &&
            boxes[a + i].innerText != ''
        ) {
            document.getElementById('result').innerHTML =
                '<h1>' + boxes[a + i].innerText + ' WINS !</h1>';
            rme();
            return;
        }
    }
    if (
        boxes[0].innerText == boxes[4].innerText &&
        boxes[4].innerText == boxes[8].innerText &&
        boxes[0].innerText != ''
    ) {
        document.getElementById('result').innerHTML =
            '<h1>' + boxes[0].innerText + ' WINS !</h1>';
        rme();
        return;
    } else if (
        boxes[2].innerText == boxes[4].innerText &&
        boxes[4].innerText == boxes[6].innerText &&
        boxes[6].innerText != ''
    ) {
        document.getElementById('result').innerHTML =
            '<h1>' + boxes[2].innerText + ' WINS !</h1>';
        rme();
        return;
    }
    if (clicks == 9) {
        document.getElementById('result').innerHTML = '<h1> GAME OVER !</h1>';
    }
}
