package miguch.com

import spark.Response
import spark.kotlin.Http
import spark.kotlin.ignite
import java.io.File
import java.io.IOException

fun main(args: Array<String>) {
    val service = WebService()
    service.run()
}

class WebService {
    val http: Http = ignite()

    val searcher = Searcher()

    fun run() {
        http.get("/file/:filename") {
            //Not using static file service here due to charset issue
            val filename = request.params(":filename")
            try {
                File("resources/page/$filename").readText(Charsets.UTF_8)
            } catch (e: IOException) {
                response.status(404)
                "<html><body><h1>Cannot Get file $filename</h1></body></html>"
            }
        }

        http.get("/search/") {
            response.redirect("/")
        }

        http.get("/search/:query") {
            handleQuery(request.params(":query"), response)
        }

        http.get("/index") {
            println("Querying Index")
            handleIndexQuery()
        }

        http.get("/") {
            htmlHead + searchFormBody + htmlTailWithScript
        }
    }

    private fun handleQuery(queryText: String, response: Response): String {
        if (queryText.isEmpty()) {
            response.redirect("/")
        }
        println("Query: $queryText")
        val similars = searcher.getSimilars(queryText)
        val searchResults = searcher.search(queryText)
        return htmlHead + searchFormBody + toSimilarsList(similars) + toResultList(searchResults) + htmlTailWithScript
    }

    private fun handleIndexQuery(): String {
        val indexes = searcher.getInvertedIndex()
        var allIndexes = StringBuilder()
        for (index in indexes) {
            allIndexes.append("<p>$index</p>")
        }
        println("Service")
        return allIndexes.toString()
    }

    private fun toResultList(items: List<SearchResult>): String {
        if (items.isEmpty()) {
            return "<p><b>No Search Result</b></p>"
        }
        var result = StringBuilder()
        for (item in items) {
            val name = item.path.split('/').last()
            result.append("""
                <a href="/file/$name">$name</a>   <span>(Score: ${item.score})</span>
                <p>${item.bestFragment}</p>
            """.trimIndent())
        }
        return result.toString()
    }

    private fun toSimilarsList(similars: Array<String>): String {
        if (similars.isEmpty()) {
            return "<p><b>No Suggestion</b></p>"
        }
        var result = StringBuilder("<p>Possible words: ")
        for (similar in similars) {
            val item = """
                <a href="/search/$similar">$similar</a><span>  </span>
            """.trimIndent()
            result.append(item)
        }
        return "${result.toString()}</p>"
    }

    private val htmlHead = """
        <!DOCTYPE html>
        <html lang="en">
        <head>
            <meta charset="UTF-8">
            <title>Search</title>
            <style>
                body {
                    text-align: center;
                }
                p {
                    margin-left: 20%;
                    margin-right: 20%;
                }
                b {
                    color: red;
                }
            </style>
        </head>
        <body>
    """.trimIndent()


    val htmlTailWithScript = """
        <script>
            document.getElementById("search-form").onsubmit = (function (event) {
                try {
                    let searchTerm = document.getElementById("searching").value;
                    if (searchTerm.length !== 0) {
                        window.location.pathname = "/search/" + searchTerm;
                    }
                } catch(e) {
                    console.log(e)
                }
                return false;
            });
        </script>
        </body>
        </html>
    """.trimIndent()

    private val searchFormBody = """
        <body>
        <h1>Search</h1>
        <form id="search-form">
            <label>
                Find word or phrase:
                <input type="text" name="searching" id="searching">
            </label>
            <br/>
            <button type="submit" style="margin-top: 20px;">
                Search
            </button>
            <button style="margin-top: 20px;" onclick='window.location.pathname = "/index"'>
                See Indexes
            </button>
        </form>
    """.trimIndent()


}