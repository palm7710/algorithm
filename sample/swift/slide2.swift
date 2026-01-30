// データは 「書き換えない」
// 変えたいときは、新しいデータを作る
struct User {
    let name: String        // let で　不変性　
    let nickname: String?   // ? でオプショナル（NULLを許容し、クラッシュせずスキップ）

    // 自分自身は変えず、名前を変えた新しい User を返す
    func renamed(to newName: String) -> User {
        User(name: newName, nickname: nickname)
    }
}
// この時点では、user の中身は一切変わっていない
let user = User(name: "Miki", nickname: "mikichan")

// user.name は "Miki" のまま
// 新しい User が作られる
let renamed = user.renamed(to: "Hanako")

// nickname があるときだけ処理される
// nil のときは自動的にスキップされる
let nicknameLength = renamed.nickname.map { $0.count }
