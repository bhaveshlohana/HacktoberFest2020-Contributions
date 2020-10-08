
use std::env;

// this a hello worl in rust reading a arg

fn main() {
    // reading arguments
    let args: Vec<String> = env::args().collect();
    //print message with arg 1
    println!("Hello World {}", args[1])
}