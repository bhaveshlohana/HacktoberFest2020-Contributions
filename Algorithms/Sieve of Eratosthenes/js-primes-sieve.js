const primesSieve = function(num){
    let primes = [];
    for(let i = 2; i<=num; i++){
        primes.push(i);
    };
    for(let j = 2; j<=Math.sqrt(num); j++){
        if (primes.includes(j)){
            for(let k = j*j; k <= num; k+=j){
              if (primes.includes(k)){
                primes.splice(primes.indexOf(k), 1);
                };  
            };
        };
    };
    console.log(primes);
    return primes;
};