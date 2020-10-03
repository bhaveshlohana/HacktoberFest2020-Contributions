//Function implementing the linear search

fun linearSearch(list:List<Any>, key:Any):Int?{
	for ((index, value) in list.withIndex()) {
		if (value == key){
			return index
		}
	}
	return null
}

fun main(args: Array<String>) {
    println("\nOrdered list:")
    //custom test list for sorting
    val someList = listOf(9, 7, 5, "Clark", "John", "Tim", "Zack", 6)
    println(someList)
    val name = 7
    val position = linearSearch(someList, name)
    println("${name} is in the position ${position} in the ordered List.\n")

    val name2 = "Tim"
    val position2 = linearSearch(someList, name2)
    println("${name2} is in the position ${position2} in the ordered List.\n")
}
