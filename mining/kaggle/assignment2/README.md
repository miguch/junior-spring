Report.pdf 为项目报告。

Ensembles-rs 内为项目的 Rust 源码，运行测试使用的编译器版本为`rustc 1.35.0`。

在项目目录下可用的运行命令如下：

```shell
# 单棵决策树交叉验证
ENSEM_LOG=info cargo run --release --bin cv
# 单棵决策树训练并对测试集进行预测，结果输出至数据目录下的 csv 文件中
ENSEM_LOG=info cargo run --release --bin predict
# GBDT 交叉验证
ENSEM_LOG=info cargo run --release --bin boost_cv
# GBDT 训练并预测
ENSEM_LOG=info cargo run --release --bin boost_predict
# 随机森林交叉验证
ENSEM_LOG=info cargo run --release --bin rf_cv
# 随机森林训练并预测
ENSEM_LOG=info cargo run --release --bin rf_predict
# 命令行接收一个整数参数作为程序使用的并行线程数，用于检测并行效果
ENSEM_LOG=info cargo run --release --bin parallel_performance $num_thread
```

运行程序前需将数据集所有 csv 文件放于与 ensembles-rs 目录同级的 data 目录中。

