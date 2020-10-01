fun quickSort(array: IntArray, left: Int, right: Int) {
    if (array.isEmpty()) return
    if (left >= right) return
    val mid = left + (right - left) / 2
    val el = array[mid]
    var i = left
    var j = right
    while (i <= j) {
        while (array[i] < el) {
            i++
        }
        while (array[j] > el) {
            j--
        }
        if (i <= j) {
            val temp = array[i]
            array[i] = array[j]
            array[j] = temp
            i++
            j--
        }
    }

    if (left < j) {
        quickSort(array, left, j)
    }
    if (right > i) {
        quickSort(array, i, right)
    }
}

fun main() {
    val arr = intArrayOf(123, -3, 12, 567, 0, 12, -1000, 256, 11)
    quickSort(arr, 0, arr.size - 1)
    println(arr.toList())
}
