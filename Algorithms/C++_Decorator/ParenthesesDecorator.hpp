#ifndef PARENTHESES_DECORATOR_H
#define PARENTHESES_DECORATOR_H

#include "StreamDecorator.hpp"

/**
 * \Este decorador pega um fluxo e adiciona parênteses antes e depois dele.
 * Haverá um espaço entre cada parêntese e o token mais próximo. Por exemplo,
 * se o fluxo é "a 23 b 3,14", então ele produz "(a, 23, b, 3,14)".
 */
class ParenthesesDecorator: public StreamDecorator {

public:
  /**
   * \O construtor, que envia o objeto que será decorado, ou seja, o fluxo,
   * para o decorador de base.
   * \param o objeto que deve ser decorado.
   */
  ParenthesesDecorator(AbstractStream* streamObj): StreamDecorator(streamObj) {}

  /**
   * \O destruidor é o destruidor padrão produzido pelo compilador.
   */
  ~ParenthesesDecorator() {};

  /**
   * \Este método decorado envolve o fluxo entre parênteses.
   * \retorna a string com os parênteses.
   */
  std::string toString() override;
};

#endif