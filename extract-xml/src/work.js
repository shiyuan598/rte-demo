let arr  = [
    {
        a: 958,
        b: 91,
        opt: "*",
    },
    {
        a: 647,
        b: 23,
        opt: "*",
    },
    {
        a: 427,
        b: 31,
        opt: "*",
    },
    {
        a: 427,
        b: 31,
        opt: "*",
    },
    {
        a: 443,
        b: 88,
        opt: "*",
    },
    {
        a: 443,
        b: 88,
        opt: "*",
    },
    {
        a: 276,
        b: 46,
        opt: "/",
    },
    {
        a: 760,
        b: 95,
        opt: "/" ,
    },
    {
        a: 228,
        b: 38,
        opt: "/" ,
    },
    {
        a: 360,
        b: 40,
        opt: "/" ,
    },
    {
        a: 400,
        b: 20,
        opt: "/" ,
    },
    {
        a: 483,
        b: 69,
        opt: "/" ,
    },
    {
        a: 495,
        b: 45,
        opt: "/" ,
    },
    {
        a: 928,
        b: 29,
        opt: "/" ,
    },
]


arr.forEach((item) => {
    let result = ""
    const {a:num1, b:num2, opt} = item
    switch (opt) {
        case "*":
            result = num1 * num2;
            break;
        case "/":
            result = num1 / num2;
            break;
        case "+":
            result = num1 + num2;
            break;
        case "-":
            result = num1 - num2;
            break;

        default:
            break;
    }

    console.info(`${num1} ${opt} ${num2} = ${result}`);

})
