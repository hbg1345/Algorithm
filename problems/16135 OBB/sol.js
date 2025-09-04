let input = require('fs').
    readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt").
    toString().trim().split("\n");

input = input.map(v => v.trim().split(' ').map(Number));

[x1, y1, x2, y2, x3, y3, x4, y4] = input[0];
[x21, y21, x22, y22, x23, y23, x24, y24] = input[1];


function subtract({x, y}) {
    return {"x": this.x-x, "y":this.y-y};
}
function add({x, y}) {
    return {"x":this.x+x, "y":this.y+y};
}
function dot({x, y}) {
    return Math.abs(this.x*x+this.y*y);
}

let p1 = {"x": x1, "y": y1};
let p2 = {"x": x2, "y": y2};
let p3 = {"x": x3, "y": y3};

let p21 = {"x": x21, "y": y21};
let p22 = {"x": x22, "y": y22};
let p23 = {"x": x23, "y": y23};

let c1 = add.call(p1, p3);
let c2 = add.call(p21, p23);

let a1 = subtract.call(p1,p2);
let a2 = subtract.call(p2, p3);

let b1 = subtract.call(p21,p22);
let b2 = subtract.call(p22, p23);

let d = subtract.call(c1, c2);
function check(u) {
    return dot.call(d, u) >= dot.call(a1, u) + dot.call(a2, u) + dot.call(b1, u) + dot.call(b2, u);
}

u = subtract.call(p1, p2);
let ret = 0;
ret |= check(u);
u = subtract.call(p2, p3);
ret |= check(u);

u = subtract.call(p21, p22);
ret |= check(u);
u = subtract.call(p22, p23);
ret |= check(u);

console.log(+!ret);


// 	9344KB	92ms