fun <T> Array<out T>.binarySearch(
    element: T,
    fromIndex: Int = 0,
    toIndex: Int = size
): Int
fun ByteArray.binarySearch(
    element: Byte,
    fromIndex: Int = 0,
    toIndex: Int = size
): Int
fun ShortArray.binarySearch(
    element: Short,
    fromIndex: Int = 0,
    toIndex: Int = size
): Int
fun IntArray.binarySearch(
    element: Int,
    fromIndex: Int = 0,
    toIndex: Int = size
): Int
fun LongArray.binarySearch(
    element: Long,
    fromIndex: Int = 0,
    toIndex: Int = size
): Int
fun FloatArray.binarySearch(
    element: Float,
    fromIndex: Int = 0,
    toIndex: Int = size
): Int
fun DoubleArray.binarySearch(
    element: Double,
    fromIndex: Int = 0,
    toIndex: Int = size
): Int
fun CharArray.binarySearch(
    element: Char,
    fromIndex: Int = 0,
    toIndex: Int = size
): Int
@ExperimentalUnsignedTypes fun UIntArray.binarySearch(
    element: UInt,
    fromIndex: Int = 0,
    toIndex: Int = size
): Int
@ExperimentalUnsignedTypes fun ULongArray.binarySearch(
    element: ULong,
    fromIndex: Int = 0,
    toIndex: Int = size
): Int
@ExperimentalUnsignedTypes fun UByteArray.binarySearch(
    element: UByte,
    fromIndex: Int = 0,
    toIndex: Int = size
): Int
@ExperimentalUnsignedTypes fun UShortArray.binarySearch(
    element: UShort,
    fromIndex: Int = 0,
    toIndex: Int = size
): Int