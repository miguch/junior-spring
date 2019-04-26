package miguch.com

import org.apache.lucene.index.Term
import org.apache.lucene.search.IndexSearcher
import org.apache.lucene.search.highlight.*
import org.apache.lucene.search.spans.SpanTermQuery
import java.util.*
import kotlin.collections.ArrayList


class Searcher {

    private val indexer = FileIndexer("resources/page")
    private val parser = indexer.queryParser
    private val ireader = indexer.ireader
    private val isearcher = IndexSearcher(ireader)
    fun search(queryText: String): List<SearchResult> {
        val query = SpanTermQuery(Term("Contents", queryText))
        val scorer = QueryScorer(query)
        val formatter = SimpleHTMLFormatter()
        val highlighter = Highlighter(formatter, scorer)
        val fragmenter = SimpleSpanFragmenter(scorer)
        highlighter.textFragmenter = fragmenter
        var results = ArrayList<SearchResult>()

        val hits = isearcher.search(query, 12)

        for (hit in hits.scoreDocs) {
            val hitDoc = isearcher.doc(hit.doc)

            val content = hitDoc.get("Contents")
            val path = hitDoc.get("Path")
            val tokenStream = TokenSources.getAnyTokenStream(ireader, hit.doc, "Contents", indexer.analyzer)
            val frags = highlighter.getBestFragments(tokenStream, content, 10)

            results.add(SearchResult(frags.first(), path))
        }

        return results
    }

    fun getSimilars(queryText: String): Array<String> {
        return indexer.checker!!.suggestSimilar(queryText, 5)
    }
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

fun main(args: Array<String>) {
    val searcher = Searcher()

    val scanner = Scanner(System.`in`)
    println("\nEnter your query and press Enter:")
    while (scanner.hasNextLine()) {
        val queryText = scanner.nextLine()
        if (queryText.isEmpty()) {
            continue
        }
        val matches = searcher.search(queryText)
        val suggestions = searcher.getSimilars(queryText)
        for (match in matches) {
            println(match.toCommandLineHighlight())
        }

        if (suggestions.isNotEmpty()) {
            var suggestText = "Suggestions: "

            suggestText += ANSI_BLUE
            for (sim in suggestions) {
                suggestText += "$sim "
            }
            suggestText += ANSI_RESET
            println(suggestText)
        }
    }

}