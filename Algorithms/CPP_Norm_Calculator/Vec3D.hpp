#ifndef VEC_3D
#define VEC_3D

#include "Vec2D.hpp"

/**
 * \Um vetor tridimensional.
 */
class Vec3D: public Vec2D {
  public:
    Vec3D(double x, double y, double z): Vec2D(x, y), _z(z) {}
    virtual double getZ() const { return _z; }

    std::string to_string() const override;

    /**
     * \Fornece a norma do vetor, ou seja, a distância deste vetor para a origem.
     * \retorna um double que representa a norma do vetor.  No caso de um vetor 
     * tridimensional, é simplesmente a raiz quadrada do quadrado das coordenadas,
     * que é: sqrt(x*x + y*y + z*z).
     */
    virtual double get_norm() const override;
  protected:
    double _z; ///< A terceira coordenada do vetor.
};

#endif
