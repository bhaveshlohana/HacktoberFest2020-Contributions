fun main(args: Array<String>) {
    val list = mutableListOf('a', 'b', 'c', 'd', 'e')
    println(list.binarySearch('d')) // 3

    list.remove('d')

    val invertedInsertionPoint = list.binarySearch('d')
    val actualInsertionPoint = -(invertedInsertionPoint + 1)
    println(actualInsertionPoint) // 3

    list.add(actualInsertionPoint, 'd')
    println(list) // [a, b, c, d, e]
}
