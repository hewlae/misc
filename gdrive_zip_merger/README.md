# Google Drive ZIP Merger
Googleドライブからたくさんファイルが入ったフォルダをDLすると、ZIPファイルが複数に分割されてDLされることがある。これを元通りのディレクトリ構成にマージする機能を実装した。

## 使い方
事前に、DLされたzipファイルを解凍してすべて一つのフォルダにまとめておく。すなわち、`foo`というフォルダをDLすると、`foo`, `foo 1`, `foo 2`, ... と分割された形でDLされるが、これを以下のような形でまとめる。
```
bar
|-- foo
|-- foo 1
|-- foo 2
|-- ⋮
```
また、これをマージする先として空のフォルダを用意しておく（仮に`baz`とする）。

最後に、`file_merger_multiple(bar, baz)`とすると、`baz`の中がGoogleドライブと同じディレクトリ構成になるはずである。