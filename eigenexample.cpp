#include <RcppEigen.h>

// [[Rcpp::depends(RcppEigen)]]

using Eigen::Map;                       // 'maps' rather than copies
using Eigen::MatrixXd;                  // variable size matrix, double precision
using Eigen::VectorXd;                  // variable size vector, double precision
using Eigen::SelfAdjointEigenSolver;    // one of the eigenvalue solvers
using Eigen::ColPivHouseholderQR;
using Eigen::FullPivHouseholderQR;

// [[Rcpp::export]]
VectorXd colpiv(Map<MatrixXd> M, Map<VectorXd> b) {
  ColPivHouseholderQR<MatrixXd> dec(M);
  VectorXd x = dec.solve(b);
  // SelfAdjointEigenSolver<MatrixXd> es(M);
  // double relative_error = (M*x - b).norm() / b.norm(); // norm() is L2 norm
  // std::cout << "The relative error is:\n" << relative_error << std::endl;
  return x;
}

// [[Rcpp::export]]
VectorXd fullpiv(Map<MatrixXd> M, Map<VectorXd> b) {
  FullPivHouseholderQR<MatrixXd> dec(M);
  VectorXd x = dec.solve(b);
  // SelfAdjointEigenSolver<MatrixXd> es(M);
  // double relative_error = (M*x - b).norm() / b.norm(); // norm() is L2 norm
  // std::cout << "The relative error is:\n" << relative_error << std::endl;
  return x;
}
