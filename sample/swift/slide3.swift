fun main() {
    var result = ""                // var で可変な状態
    var retry = 0                  

    while (retry < 2) {            // 命令が順序依存
        try {
            result = apiCall()     // 先に呼ばないと意味が壊れる
            break                  // 行を入れ替えると壊れる
        } catch (e: Exception) {
            retry++                // 状態をその場で変更（in-place）
        }
    }

    result += "!"                  // in-place 変更
    println(result)
}

fun apiCall(): String {
    throw RuntimeException("error")
}
