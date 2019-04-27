package miguch.com

class SearchResult(val bestFragment: String, val path: String, val score: Float) {
    override fun toString(): String {
        return "$path: $bestFragment"
    }

    val ANSI_RESET = "\u001B[0m"
    val ANSI_BLACK = "\u001B[30m"
    val ANSI_RED = "\u001B[31m"
    val ANSI_GREEN = "\u001B[32m"
    val ANSI_YELLOW = "\u001B[33m"
    val ANSI_BLUE = "\u001B[34m"
    val ANSI_PURPLE = "\u001B[35m"
    val ANSI_CYAN = "\u001B[36m"
    val ANSI_WHITE = "\u001B[37m"
    fun toCommandLineHighlight(): String {
        if (bestFragment.isEmpty()) {
            return "No Match!"
        }
        var highlighted = bestFragment.replace("<B>", ANSI_RED)
        highlighted = highlighted.replace("</B>", ANSI_RESET)
        var result = "$path:"
        result += highlighted
        return result
    }
}

