# 2D物理シミュレータ

C++を用いて作成した2Dで物体の動きをシミュレーションするコードです。
GLUTを用いて描画を行なっています。

## 動作確認環境
```
端末: MacBook Pro (15-inch, 2017)
バージョン: Mac OSX 10.15.1 Beta
コンパイラ: Apple clang version 11.0.0 (clang-1100.0.33.8)
```
### 実行方法
もしGLUTが無いと怒られた場合は[こちら](https://tokoik.github.io/opengl/libglut.html#2.4)を参考にDeveloper Toolsのインストールをお願いします

全てCLIで操作する想定です。
1. クローンする。 
`git clone https://github.com/y-ideta/2d_physics.git`

2. ディレクトリに移動する
`cd 2d_physics`

3. 実行コマンドを叩く
`make run`

## めざすところ
以下の内容をシミュレーションできるようにしたい
- 重力
- 衝突
- 摩擦力
- モーメント

## 今できていること
- 重力
- 衝突(途中)

まではできています  
具体的には以下のとおりです  

- マウスでクリックした所に新しくオブジェクト(緑の正方形)を生成する
- 天井と床の衝突判定と処理
- 正方形同士の衝突判定と処理

## まだできていないこと
今はほぼ質点として扱っているので剛体として扱えるようにしたい  
摩擦も0として計算しているので摩擦力(物体同士、各壁面、空気)を加えたい。  

また、一通り動くようになったら高速化に向けて以下の事を試したい。
- for文を使っているところを行列計算に置き換える
- 衝突判定のアルゴリズムをちゃんと調べて実装してみたい
