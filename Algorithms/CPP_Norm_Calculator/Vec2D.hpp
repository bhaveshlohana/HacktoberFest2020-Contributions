#ifndef VEC_2D
#define VEC_2D

#include "Vec1D.hpp"

/**
 * \Um vetor bidimensional.
 */
class Vec2D: public Vec1D {
  public:
    Vec2D(double x, double y): Vec1D(x), _y(y) {}
    virtual double getY() const { return _y; }
    std::string to_string() const override;

    /**
     * \Fornece a norma do vetor, ou seja, a distância deste vetor para a origem.
     * \retorna um double que representa a norma do vetor.  No caso de um vetor 
     * bidimensional, é simplesmente a raiz quadrada do quadrado das coordenadas,
     * que é: sqrt(x*x + y*y).
     */
    virtual double get_norm() const override;
  protected:
    double _y; ///< A segunda coordenado do vetor.
};

#endif
