fun sortByRec(orig: IntArray, copy: IntArray, low: Int, high: Int, point: Int) {
    if (low >= high)
        return
    val mid = low + (high - low) / 2
    sortByRec(orig, copy, low, mid, point)
    sortByRec(orig, copy, mid + 1, high, point)
    merge(orig, copy, low, mid, high)
}

private fun merge(orig: IntArray, copy: IntArray, low: Int, mid: Int, high: Int) {
    assert(isSorted(orig, low, mid))
    assert(isSorted(orig, mid + 1, high))

    for (k in low..high)
        copy[k] = orig[k]
    var i = low
    var j = mid + 1
    for (k in low..high) {
        if (i > mid)
            orig[k] = copy[j++]
        else if (j > high)
            orig[k] = copy[i++]
        else if (copy[j] < copy[i])
            orig[k] = copy[j++]
        else
            orig[k] = copy[i++]
    }
    assert(isSorted(orig, low, high))
}

private fun isSorted(a: IntArray, l: Int, m: Int): Boolean {
    for (i in l..m)
        if (a[i] > a[i - 1])
            return false
    return true
}

fun main(args: Array<String>) {
    val test = intArrayOf(1, 5, 3, 7, 1, 6, 0, 4, 2)
    for (k in test)
        println(k)
    sortByRec(test, IntArray(test.size), 0, test.size - 1, 0)
    for (k in test)
        println(k)

}
