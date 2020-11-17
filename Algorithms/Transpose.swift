//
//  Transpose.swift
//  
//
//  Created by Alexey Ivanov on 24.10.2020.
//

import Foundation

extension Collection where Element: Collection {
    func transposed() -> [[Element.Element]]? {
        guard let maxCount = self.map({$0.count}).max() else {return nil}
        var result = [[Element.Element?]](repeating: [Element.Element?](repeating: nil, count: self.count), count: maxCount)
        for (r,row) in self.enumerated() {
            for (c,v) in row.enumerated() {
                result[c][r] = v
            }
        }
        return result
            .map { (elements) -> [Element.Element] in
                elements.compactMap{$0}
        }
    }
}
func print(_ matrix: [[Int]]) {
    matrix.forEach{print($0)}
}
//print tests
let test1 = [
    [],
    [1,2,3],
    [4,5]
]
print("Test1")
print(test1)
print("Test1 Transposed:")
print(test1.transposed()!)

let test2 = [
    [1,2],
    [3,4,5,6,7],
    [],
    [8],
    []
]
print("Test2")
print(test2)
print("Test 2 Transposed:")
print(test2.transposed()!)

print("Test3")
print([[1]])
print("Test3 Transposed:")
print([[1]].transposed()!)


