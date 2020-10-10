import Foundation

func binarySearch<T: Comparable>(in elements: [T], value: T) -> Int? {
    var startIndex = elements.startIndex
    var endIndex = elements.endIndex
    while startIndex < endIndex {
        let midIndex = startIndex + (endIndex - startIndex) / 2
        if elements[midIndex] == value {
            return midIndex
        } else if elements[midIndex] < value {
            startIndex = midIndex + 1
        }else {
            endIndex = midIndex
        }
    }
    return nil
}

let numbers = [1, 6, 23, 24, 33, 34, 36, 45, 46, 47, 55, 123, 678, 789, 1234, 7678]
binarySearch(in: numbers, value: 46)
binarySearch(in: numbers, value: 47)
binarySearch(in: numbers, value: 23)
