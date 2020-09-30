fun insertionSort(array: IntArray) {
    val n = array.size
    for (j in 1 until n) {
        val key = array[j]
        var i = j - 1
        while (i > -1 && array[i] > key) {
            array[i + 1] = array[i]
            i--
        }
        array[i + 1] = key
    }
}


fun main() {
    val arr1 = intArrayOf(9, 14, 3, 2, 43, 11, 58, 22)
    insertionSort(arr1)
    for (i in arr1) {
        print("$i ")
    }
}
