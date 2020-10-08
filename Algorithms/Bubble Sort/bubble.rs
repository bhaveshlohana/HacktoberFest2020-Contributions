// A Bubble Sort Algorithm in RustLang, this sorts both Numbers as well as Strings.
//@author : Srinjana

fn bubble_sort<T: Ord>(values: &mut[T]) {
    let mut n = values.len();
    let mut swapped = true;
 
    while swapped {
        swapped = false;
 
        for i in 1..n {
            if values[i - 1] > values[i] {
                values.swap(i - 1, i);
                swapped = true;
            }
        }
 
        n = n - 1;
    }
}
 
fn main() {
    // Sorting numbers.
    let mut numbers = [8, 7, 1, 2, 9, 3, 4, 5, 0, 6];
    println!("Before: {:?}", numbers);
 
    bubble_sort(&mut numbers);
    println!("After: {:?}", numbers);
 
    // Sorting  strings.
    let mut strings = ["elephant", "badger", "airplne", "cat", "doctor"];
    println!("Before: {:?}", strings);
 
    bubble_sort(&mut strings);
    println!("After: {:?}", strings);
}