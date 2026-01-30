import SwiftUI

struct SimpleView: View {
    @State private var on = false

    var body: some View {
        VStack(spacing: 16) {

            // 文字（状態からUIを宣言）
            Text(on ? "ON" : "OFF")
                .font(.title)              // フォントサイズ
                .foregroundColor(.white)   // 文字色
                .padding()                 // 余白

            // ボタン（状態を変更するだけ）
            Button("Toggle") { on.toggle() }
                .padding()
                .background(Color.blue)    // 背景
                .foregroundColor(.white)
                .clipShape(Capsule())      // 形をカプセルにする

            // まるい図形（状態の結果として表示）
            Circle()
                .fill(on ? Color.green : Color.red)
                .frame(width: 50, height: 50)
        }
    }
}
