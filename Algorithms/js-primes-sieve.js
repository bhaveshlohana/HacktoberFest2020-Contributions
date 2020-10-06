const primesSieve = function(num){
    const primes = [];
    for(let i = 2; i<=num; i++){
        primes.push(i);
    };
    for(let j = 2; j<=Math.sqrt(num); j++){
        if (primes.includes(j)){
            for(let k = j*j; k <= num; k+=j){
                console.log(`removing ${k}`)
                primes = primes.splice(primes.indexOf(k), 1)
            }
        }
    }
    console.log(primes)
}