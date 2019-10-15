fun shell(a: IntArray): IntArray {
    var interval = 1
    while (interval < a.size / 3) interval = 3 * interval + 1

    while (interval >= 1) {
        for (k in interval until a.size) {
            var i = k
            while (i >= interval) {
                if (a[i] < a[i - interval])
                    exch(a, i, i - interval)
                else
                    break
                i -= interval
            }
        }
        interval = interval / 3
    }
    return a
}

private fun exch(a: IntArray, i: Int, j: Int) {
    val swap = a[i]
    a[i] = a[j]
    a[j] = swap
}


fun main(args: Array<String>) {
    var test = intArrayOf(1, 5, 3, 7, 1, 6, 0, 4, 2)
    for (k in test)
        println(k)
    println("ASDAS")
    test = shell(test)
    for (k in test)
        println(k)
}
