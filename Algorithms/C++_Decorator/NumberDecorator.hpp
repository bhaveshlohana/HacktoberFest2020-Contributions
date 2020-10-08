#ifndef NUMBER_DECORATOR_H
#define NUMBER_DECORATOR_H

#include "StreamDecorator.hpp"

/**
 * \Este decorador pega um fluxo e adiciona um sinal '+' na frente de cada
 * inteiro neste fluxo. Este decorador preserva um espaço entre tokens
 * consecutivos (nenhum espaço após o último token). Observe que os números reais
 * com um ponto '.' permanecem inalterados. Exemplo: "a 23 b 3,14" => "a +23 b 3,14"
 */
class NumberDecorator: public StreamDecorator {

public:
  /**
   * \O construtor, que envia o objeto que será decorado, ou seja, o fluxo, para
   * o decorador de base. param o objeto que deve ser decorado.
   */
  NumberDecorator(AbstractStream* streamObj): StreamDecorator(streamObj) {}

  /**
   * \O destruidor é o destruidor padrão produzido pelo compilador.
   */
  ~NumberDecorator() {};

  /**
   * \Este método decorado adiciona o sinal '+' na frente dos inteiros. retornar
   * a string decorada.
   */
  std::string toString() override;
};

#endif