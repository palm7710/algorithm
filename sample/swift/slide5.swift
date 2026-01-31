import UIKit

class OrderViewController: UIViewController {
    var count = 0 // 「可変」な状態を持つ
    let label = UILabel()

    @objc func didTapButton() {
        // その場で「状態」を更新する
        count += 1
        
        // 命令を「上から書いた順」に実行し、UIを直接操作する
        label.text = "合計: \(count)"       // テキストを更新せよ
        label.textColor = .systemPink      // 色をピンクに変えよ
        
        // 実行コストを意識した細かい制御（軽量なアニメーション）
        UIView.animate(withDuration: 0.3) {
            self.label.transform = CGAffineTransform(scaleX: 1.2, y: 1.2)
        }
    }
}
