#ifndef VEC_H
#define VEC_H

#include <string>

/**
 * \Interface que representa cada vetor, independente de sua dimensão.
 */
class Vec {
  public:
    /**
     * \Representação de string do vetor.
     * \retorna uma string que representa o vetor, como uma tupla de n-dimensões.
     */
    virtual std::string to_string() const = 0;

    /**
     * \Fornece a norma do vetor, ou seja, a distância deste vetor para a origem.
     * \retorna um double que representa a norma do vetor.
     */
    virtual double get_norm() const = 0;

    /**
     * \o destruidor virtual (ou então o compilador irá criar um para você).
     */
    virtual ~Vec() {};
};

#endif