const divide = (a, b) => {
    return new Promise((resolve, reject) => {
        try {
            let ans = a / b 
            resolve(ans)
        } catch (e) {
            reject('error!')
        }   
    })  
}

divide(4, 2).then((ans1) => {
    divide(ans1, 2).then((ans2) => {
        console.log(ans2)
    })  
}).catch((e) => {
    console.log(e)
})
