package miguch.com


import org.apache.lucene.analysis.Analyzer
import org.apache.lucene.analysis.cn.smart.SmartChineseAnalyzer
import org.apache.lucene.document.*
import org.apache.lucene.index.DirectoryReader
import org.apache.lucene.index.IndexWriter
import org.apache.lucene.index.IndexWriterConfig
import org.apache.lucene.queryparser.classic.QueryParser
import org.apache.lucene.search.spell.LuceneDictionary
import org.apache.lucene.search.spell.SpellChecker
import org.apache.lucene.store.Directory
import org.apache.lucene.store.FSDirectory
import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.nio.charset.StandardCharsets
import java.nio.file.*
import java.nio.file.attribute.BasicFileAttributes
import java.util.*
import java.util.stream.Collectors


class FileIndexer(directory: String) {
    var analyzer: Analyzer = SmartChineseAnalyzer()

    private var path: Path = Paths.get(directory)

    var indexDir: Directory? = null
        private set

    val queryParser: QueryParser
        get() = QueryParser("Contents", this.analyzer)

    var checker: SpellChecker? = null

    var ireader: DirectoryReader? = null

    init {
        if (!Files.isReadable(path)) {
            System.err.println("Document directory '" + path.toAbsolutePath() + "' does not exist or is not readable, please check the path")
            System.exit(1)
        }
        try {
            indexDir = FSDirectory.open(Paths.get(directory, "index"))
            checker = SpellChecker(indexDir)
            ireader = DirectoryReader.open(indexDir)

            val iwc = IndexWriterConfig(analyzer)
            iwc.openMode = IndexWriterConfig.OpenMode.CREATE


            checker!!.indexDictionary(LuceneDictionary(ireader, "Contents"), IndexWriterConfig(analyzer), true)

            val writer = IndexWriter(indexDir!!, iwc)
            indexDir(writer, path)

            writer.close()

        } catch (e: IOException) {
            e.printStackTrace()
        }

    }

    @Throws(IOException::class)
    private fun indexDir(writer: IndexWriter, filesDir: Path) {
        Files.walkFileTree(filesDir, EnumSet.noneOf(FileVisitOption::class.java), 1, object : SimpleFileVisitor<Path>() {
            @Throws(IOException::class)
            override fun visitFile(file: Path, attrs: BasicFileAttributes): FileVisitResult {
                try {
                    indexDoc(writer, file)
                } catch (ignored: IOException) {

                }

                return FileVisitResult.CONTINUE
            }
        })
    }

    @Throws(IOException::class)
    private fun indexDoc(writer: IndexWriter, file: Path) {
        if (Files.isDirectory(file)) {
            return
        }
        Files.newInputStream(file).use { stream ->
            val doc = Document()
            val pathField = StringField("Path", file.toString(), Field.Store.YES)
            doc.add(pathField)
            val contentStr = BufferedReader(InputStreamReader(stream, StandardCharsets.UTF_8)).lines().collect(Collectors.joining())
            val fieldType = FieldType(TextField.TYPE_STORED)
            fieldType.setStoreTermVectors(true)
            fieldType.setStoreTermVectorPositions(true)
            fieldType.setStoreTermVectorPayloads(true)
            fieldType.setStoreTermVectorOffsets(true)
            fieldType.setTokenized(true)
            val contents = Field("Contents", contentStr, fieldType)
            doc.add(contents)
            println("Added $file")
            writer.addDocument(doc)
        }

    }

}
