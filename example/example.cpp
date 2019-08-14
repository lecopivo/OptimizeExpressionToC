#include <array>
#include <iostream>
#include <cmath>

// <dimension>
constexpr int Dim = 3;
// </dimension>

using Real = double;
template <size_t N>
using Vector = std::array<Real, N>;
template <size_t N, size_t M>
using Matrix = std::array<std::array<Real, M>, N>;

Real Power(Real x, Real y){
  return pow(x,y);
}

Vector<Dim> stereographic_projection(const Vector<Dim + 1> pointOnSphere) {

  Vector<Dim> result;

  // Functions to access data
  auto x   = [&](int i) -> Real const & { return pointOnSphere[i]; };
  auto out = [&](int i) -> Real & { return result[i]; };

  // <stereographic>
  // </stereographic>

  return result;
}

Matrix<Dim, Dim + 1>
stereographic_projection_grad(const Vector<Dim + 1> pointOnSphere) {

  Matrix<Dim, Dim + 1> result;

  // Functions to access data
  auto x   = [&](int i) -> Real const & { return pointOnSphere[i]; };
  auto out = [&](int i, int j) -> Real & { return result[i][j]; };

  // <stereographic_grad>
  // </stereographic_grad>

  return result;
}

template<size_t N>
void print(Vector<N> const& x){
  for(auto y :x)
    std::cout << y << " ";
  std::cout << "\n";
}

template<size_t N,size_t M>
void print(Matrix<N,M> const& A){
  for(auto const& v :A)
    print(v);
}

int main() {

  Real angle = 0.5 * M_PI/2;
  Vector<Dim+1> v = {0};
  
  v[0] = cos(angle);
  v[Dim] = sin(angle);

  std::cout << "Point: \n";
  print(v);

  std::cout << "is projected to the point: \n";
  print(stereographic_projection(v));

  std::cout << "gradient at this point is: \n";
  print(stereographic_projection_grad(v));

  return 0;
}
