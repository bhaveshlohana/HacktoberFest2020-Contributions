#ifndef VEC_1D
#define VEC_1D

#include "Vec.hpp"

/**
 * \Um vetor unidimensional.
 */
class Vec1D: public Vec {
  public:

    Vec1D(double x): _x(x) {}

    double getX() const { return _x; }

    std::string to_string() const override;

    /**
     * \Fornece a norma do vetor, ou seja, a distância deste vetor para a origem.
     * \ retorna um double que representa a norma do vetor. 
     *   No caso de um vetor unidimensional, é simplesmente a coordenada x.
     */
    virtual double get_norm() const override;

  protected:
    double _x; ///< A única coordenada do vetor.
};

#endif