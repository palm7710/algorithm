// ルール だけ定義 （プロトコル / Java　ではインターフェースともいう）
// 実際にどう対応するかは、あとから決める
protocol LoginDelegate {
    func didLogin()     // ログインしたよ
    func didLogout()    // ログアウトしたよ
    func didSignup()    // 新規登録が完了したよ
}

// ログイン周りの処理をまとめるクラス
class LoginManager {

    // デリゲート　を使うことで　「疎結合」 を実現できる　
    // コードを変更した時に、他に影響しにくくなる！
    var delegate: LoginDelegate?

    func login() {
        // ログイン処理
        delegate?.didLogin()
    }
}

// 「ログインしたら何をするか」 を引き受ける側
class LoginViewController: LoginDelegate {
    func didLogin() {
        print("ログイン成功")
    }
}
                                                                                        、、、