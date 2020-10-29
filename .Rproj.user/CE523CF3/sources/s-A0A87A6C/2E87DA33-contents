library(Rcpp)
library(RcppEigen)

sourceCpp("eigenExample.cpp")

set.seed(0)

A <- matrix(rnorm(200), ncol=200) # rnorm(c(3,2))
b <- rnorm(200)

x <- colpiv(A, b)
fullpiv(A, b)

microbenchmark::microbenchmark(colpiv(A, b), fullpiv(A, b))
