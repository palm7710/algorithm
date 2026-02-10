// データは 「書き換えない」
// 変えたいときは、新しいデータを作る
struct User {
    let name: String        // let で　不変性　
    let nickname: String?   // ? はオプショナル（NULLを許容し、参照できる）

    // 自分自身は変えず、名前を変えた新しい User を返す
    func renamed(to newName: String) -> User {
        User(name: newName, nickname: nickname)
    }
}
// この時点では、user の中身は一切変わっていない
let user = User(name: "Miki", nickname: "mikichan")

// user.name は "Miki" のまま
// 新しい User が作られる（書き換えない）
let renamed = user.renamed(to: "Hanako")

// nickname があるときだけ処理される
// nil のときは何もしない変換　
// （ map は値があれば変換する / $0 はこの関数の省略された第1引数）
let nicknameLength = renamed.nickname.map { $0.count }
                                                                                        ッc