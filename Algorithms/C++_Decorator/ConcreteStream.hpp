#ifndef CONCRETE_STREAM_H
#define CONCRETE_STREAM_H

#include "AbstractStream.hpp"

/**
 * \Este é o componente concreto do decorador. Ele fornece uma implementação
 * muito simples para o fluxo abstrato.
 */
class ConcreteStream: public AbstractStream {

public:
  /**
   * \Construtor. Ele recebe uma string e a liga à string interna que essa classe
   * encapsula
   * \param stream: a string que será representada por este objeto.
   */
  ConcreteStream(const std::string stream): _stream(stream) {}

  /**
   * \simplesmente retorna a string interna. Sem modificações.
   * \retornar a string não modificada encapsulada por este objeto.
   */
  std::string toString() override { return this->_stream; }

  private:
    std::string _stream; ///< A string encapsulada por este objeto.
};

#endif