#ifndef ABSTRACT_STREAM_H
#define ABSTRACT_STREAM_H

#include <string>

/**
 * \Uma classe abstrata que denota um fluxo. Em nosso caso, um stream é apenas
 * uma string, ou seja, uma sequência de caracteres.
 */
class AbstractStream {
public:
  /**
   * Este é o método abstrato que retorna a string que esta classe codifica.
   * Observe que esse método não tem corpo, ou seja, é atribuído a zero. retorna
   * a string que este objeto representa.
   */
  virtual std::string toString() = 0;

  /**
   * O destruidor virtual. Cada classe abstrata, por exemplo, uma classe com um
   * método virtual atribuído a zero, precisa de um destruidor virtual. Por que
   * a classe abstrata precisa de um destruidor virtual? Qualquer usuário de sua
   * classe provavelmente terá um ponteiro para a classe abstrata, não um
   * ponteiro para a implementação concreta. Portanto, quando eles tentarem
   * excluí-lo, se o destruidor não for virtual, eles chamarão o destruidor da
   * classe abstrata (ou o padrão fornecido pelo compilador, se você não
   * especificou um), não o destruidor da classe derivada. Se houver memória a
   * ser liberada na classe concreta, o destruidor da classe abstrata não será
   * capaz de fazê-lo. Isso levará a um vazamento de memória.
   */
  virtual ~AbstractStream() {};
};

#endif