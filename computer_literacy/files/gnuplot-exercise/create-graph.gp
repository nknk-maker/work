# 初期化
reset

# ガウス分布の定義
f(x,mu,sigma)=1/sqrt(2*pi*sigma**2)*exp(-(x-mu)**2/(2*sigma**2))

# マクスウェル分布の定義
g(x,a)=4*a**3*x**2/sqrt(pi)*exp(-a**2*x**2)

# グリッドを表示
set grid

# 線、マーカの設定（linestyleの1番として黒を設定）
set style line 1 linecolor rgb "black"

# SVG形式でグラフを作成する
set term svg

# 実験データとガウス分布のグラフを黒で書く。linestyle 1はls 1と略記できる
fit f(x,mu,sigma) "energy.dat" via mu,sigma
set output "graph-gauss.svg"
plot [0:3] f(x,mu,sigma) ls 1, "energy.dat" ls 1

# 実験データとマクスウェル分布のグラフを黒で書く
fit g(x,a) "energy.dat" via a
set output "graph-maxwell.svg"
plot [0:3] g(x,a) ls 1, "energy.dat" ls 1

# EMF形式でグラフを作成する（以下ではコメントを省略）。fitは済んでいるので実行不要
set term emf

set output "graph-gauss.emf"
plot [0:3] f(x,mu,sigma) ls 1, "energy.dat" ls 1

set output "graph-maxwell.emf"
plot [0:3] g(x,a) ls 1, "energy.dat" ls 1

# ディスプレイへの出力
set term wxt
plot [0:3] f(x,mu,sigma) , "energy.dat"
set term wxt 1
plot [0:3] g(x,a) , "energy.dat"

# 後処理
reset
