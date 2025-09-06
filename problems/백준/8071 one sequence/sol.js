let input = require('fs').
    readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt").
    toString().trim().split("\n");
input = input.map(Number);

[n, s] = input;

function solve() {
    let maxs = n*(n-1)/2;
    const as = Math.abs(s);
    if (maxs < as) {
        console.log("NIE");
        return;
    }
    let d = maxs - as;
    if (d & 1) {
        console.log("NIE");
        return;
    }
    d >>= 1;
    let ans = [0];
    for(let i=1; i<n; i++)
        ans[i] = 1;
    for(let i=1; i<n; i++) {
        if (d >= n-i) {
            d -= n-i;
            ans[i] = -1;
        }
    }
    let out = 0;
    for(let i=0; i<n; i++) {
        out += ans[i];
        console.log((s > 0 ? out:-out));
    }
}

solve();

//	13936KB	588ms