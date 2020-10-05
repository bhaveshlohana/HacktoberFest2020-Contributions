class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
     

class Queue:
    def __init__(self):
        self.first = None
        self.last = None
        # atributos que comecam com _ no python significa que eh um atributo que nao deve ser manipualdo diretamente
        self._size = 0

    def __len__(self):
        '''Retorna o tamanho da fila
            Complexidade O(1)'''
        return self._size

    def push(self, elem):
        '''Insere um elemento na fila
            Complexidade O(1)'''
        node = Node(elem)
        if self.last is None:
            self.last = node
        else:
            self.last.next = node
            self.last = node

        if self.first is None:
            self.first = node

        self._size += 1

    def pop(self):
        '''Remove o primeiro elemento da fila
            Complexidade O(1)'''
        if self._size > 0:
            node = self.first
            self.first = self.first.next
            self._size -= 1
            return node.data
        raise IndexError('The queue is empty')


    def pick(self):
        '''Retorna o elemento do inicio da fila (sem remover)
            Complexidade O(1)'''
        if self._size > 0:
            node = self.first
            return node.data
        raise IndexError('The queue is empty')

    def __repr__(self):
        '''Retorna todos os elementos da fila
            Complexidade O(n)'''
        r = ''
        pointer = self.first
        while pointer:
            r = r + str(pointer.data) + ' |'
            pointer = pointer.next
        return r

    def __str__(self):
        return self.__repr__()
